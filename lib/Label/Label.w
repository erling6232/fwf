# XfwfLabel
# Author: Bert Bos <bert@let.rug.nl>
# Copyright: see README file
# Version: 2.6

@class XfwfLabel (XfwfBoard) @file=Label

@ The Label class has the capability to display one or more lines of
text in a single font. Otherwise it is the same as the Board class.
The text can be left, right or center justified and it can be centered
vertically or put against the top or the bottom of the widget. There
is also a resource to set tab stops.

The text is `grayed out' when the widget becomes insensitive
(resource: |sensitive|), even though a Label widget has no actions of
its own.

There are two ways of highlighting portions of the label: reversing
the colors or changing the foreground. Both methods can be combined,
though the result when both highlighting methods are applied to the
same part of the text is undefined.


@public

@ The text is a single string, which may contain embedded newlines.
There is no provision for changing fonts in the middle of a text.

	@var String label = NULL

@ A tablist can be provided for tabbing to particular columns
within the label.

	@var String tablist = NULL

@ The text is drawn in the font which is given as the |font| resource.

	@var <FontStruct> XFontStruct *font = <String> XtDefaultFont

@ The foreground color is the color used to draw the
text. |hlForeground| is the foreground for highlighted text.

	@var Color foreground = <String> XtDefaultForeground
	@var Color hlForeground = <String> XtDefaultForeground

@ The text can be aligned in the widget in nine ways: left, right or
center, combined with top, center or bottom. Symbolic constants
|XfwfTop|, |XfwfBottom|, |XfwfLeft| and |XfwfRight| can be added together to
get the desired alignment.  The alignment is actually a four-bit
number made up of two parts of 2 bits added together: 1 is left, 2 is
right, 0 is center, 4 is top, 8 is bottom, 0 is vertical center. Thus
5 (= 1 + 4) means top left and 2 (= 2 + 0) means center right. For
easier specification, there is also a converter from strings, that
accepts string like `top left' or `center right'.

	@var Alignment alignment = 0

@ The |topmargin| is only used when the text is not centered. It gives
the number of pixels between the frame and the top of the text.

	@var Dimension topMargin = 2

@ The |bottomMargin| is only used to compute the preferred size of the
button in case |shrinkToFit = True|.

	@var Dimension bottomMargin = 2

@ The |leftMargin| is only used when the text is not centered. It
gives the number of pixels between the frame and the left edge of the
text, and if possible also between the frame and the right edge of the
text.

	@var Dimension leftMargin = 2

@ The |rightMargin| is only used to compute the preferred size of the
button in case |shrinkToFit = True|.

	@var Dimension rightMargin = 2

@ Buttons will normally not occupy the full area of their parents.
Most likely they will be a fixed size or a size depending on the
label. By setting the |shrinkToFit| resource to True, the width and
height are recomputed with every new label.

	@var Boolean shrinkToFit = False

@ It is possible to set a part of the label apart by drawing it in
reverse. The |rvStart| resource gives the index of the first
character to draw in reverse video.

	@var int rvStart = 0

@ The |rvLength| resource contains the number of characters to
draw in reverse video.

	@var int rvLength = 0

@ A label normally needs no keyboard interface, therefore traversal is
turned off.

	@var traversalOn = False

@ The start and length of the highlighted portion are set with the
resources |hlStart| and |hlLength|.

	@var int hlStart = 0
	@var int hlLength = 0


@private

@ For faster drawing, the number of lines in the text is stored in a
private variable by the |set_values| and |initialize| methods.

	@var int nlines

@ The tablist is converted from string format to a list of int's for speed.

	@var int *tabs

@ For drawing the text, this GC is used.

	@var GC gc

@ This GC is for the text that is drawn in reverse video.

	@var GC rv_gc

@ The GC for the highlighted portion of the text

	@var GC hl_gc

@ For graying out the text, another GC is used.

	@var GC graygc

@ When the |shrinkToFit| resource is set, we need the minimum area
necessary for the complete label to be visible. |label_width| and
|label_height| include the size of |margin|.

	@var Dimension label_width
	@var Dimension label_height



@exports

@ |XfwfLabelSetLabel| is a convenience function that calls the
|set_label| method. If |shrinkToFit| is FALSE, this method is faster
than calling |XtSetValues|, since it only redraws the label and leaves
the size of the widget (and its border) unchanged.

@proc XfwfLabelSetLabel($, String newlabel)
{
    if (! XtIsSubclass($, xfwfLabelWidgetClass))
	XtError("XfwfLabelSetLabel called with incorrect widget type");
    $set_label($, newlabel);
}



@methods

@ The new method |set_label| makes a copy of the string that is passed
in, counts the number of lines and also draws the new label. This
could have been done in |set_values|, but it is expected that
subclasses will redraw the label frequently, so a more efficient way
is provided, at least for the case that |$shrinkToFit| is |FALSE|.

If |$shrinkToFit| is |TRUE|, the method simply calls |set_values|,
since the size needs to be recomputed, otherwise it redraws just the
text and leaves the border unchanged.

@proc set_label($, String newlabel)
{
    XRectangle rect;
    Region clip;

    if ($shrinkToFit) {
	XtVaSetValues($, XtNlabel, newlabel, NULL);
    } else {
	XtFree($label);
	$label = XtNewString(newlabel);
	count_lines($);
	if (XtIsRealized($)) {
	    $compute_inside($, &rect.x, &rect.y, &rect.width, &rect.height);
	    clip = XCreateRegion();
	    XUnionRectWithRegion(&rect, clip, clip);
	    XClearArea(XtDisplay($), XtWindow($), rect.x, rect.y,
		       rect.width, rect.height, FALSE);
	    $expose($, NULL, clip);
	    XDestroyRegion(clip);
	}
    }
}


@ The |set_values| method checks the |background| resource, because is
is used in the GC |graygc|. When the text or the font change, the
private variables |nlines|, |label_height| and |label_width| are
updated.

|need_count| is set to |True| if the size of the label changes.
|need_count| implies |need_redisplay|.

@proc set_values
{
    Boolean need_redisplay = False, need_count = False;
    Position x, y;
    Dimension w, h, wd, ht;

    if ($background != $old$background)
	make_graygc($);

    if ($tablist != $old$tablist) {
	XtFree((String) $old$tabs);
	$tabs = XfwfTablist2Tabs($tablist);
	if ($label != NULL) need_count = True;
    }

    if ($font != $old$font) {
	make_gc($);
	if ($label != NULL) need_count = True;
    }
    if ($foreground != $old$foreground
 	|| $hlForeground != $hlForeground
	|| $background != $old$background) {
	make_gc($);
	if ($label != NULL) need_redisplay = True;
    }
    if ($topMargin != $old$topMargin
	|| $bottomMargin != $old$bottomMargin
	|| $leftMargin != $old$leftMargin
	|| $rightMargin != $old$rightMargin)
	need_count = True;

    if ($sensitive != $old$sensitive)
	if ($label != NULL) need_redisplay = True;

    if ($rvStart != $old$rvStart || $rvLength != $old$rvLength
 	|| $hlStart != $old$hlStart || $hlLength != $old$hlLength)
	if ($label != NULL) need_redisplay = True;

    if ($label != $old$label) {
	XtFree($old$label);
	$label = XtNewString($label);
	need_count = True;
    }
    if (need_count) {
	count_lines($);
	need_redisplay = True;
    }
    if (need_count && $shrinkToFit) {
	$compute_inside($, &x, &y, &w, &h);
	wd = $label_width + $width - w;
	ht = $label_height + $height - h;
	if (wd != $width || ht != $height) {
	    $set_abs_location($, CWWidth | CWHeight, 0, 0, wd, ht);
	    need_redisplay = True;              /* or False? [BB 951207] */
	}
    }
    return need_redisplay;
}

@ The |initialize| methods creates the first GC's and initializes the
private variables. It sets the GC's to |NULL| and calls two utility
routines to actually create them.

@proc initialize
{
    char *s;
    Position x, y;
    Dimension w, h, wd, ht;

    if ($label) $label = XtNewString($label);
    $tabs = XfwfTablist2Tabs($tablist);
    count_lines($);
    $gc = NULL;
    $rv_gc = NULL;
    $graygc = NULL;
    $hl_gc = NULL;
    make_gc($);
    make_graygc($);
    if ($shrinkToFit) {
	$compute_inside($, &x, &y, &w, &h);
	wd = $label_width + $width - w;
	ht = $label_height + $height - h;
	$set_abs_location($, CWWidth | CWHeight, 0, 0, wd, ht);
    }
}

@ The |expose| method is responsible for drawing the text. The text is
put in the position given in |alignment|. The text is always kept
within the frame. If necessary, the text is clipped. The routine ends
by calling the |expose| method from the superclass, which is
responsible for drawing the frame.

The part of the text that is to appear in reverse video is drawn with
the |rv_gc| GC.

@def draw_line(dpy, win, from, to) =
    do {
	if ($hlStart >= to) hstart = to;
 	else hstart = max($hlStart, from);
	if ($hlStart + $hlLength <= from) hend = hstart;
 	else hend = min($hlStart + $hlLength, to);
        if ($rvStart >= to) rstart = to;
	else rstart = max($rvStart, from);
	if ($rvStart + $rvLength <= from) rend = rstart;
	else rend = min($rvStart + $rvLength, to);
	w1 = XfwfTextWidth($font, $label + from, rstart - from, $tabs);
	w2 = XfwfTextWidth($font, $label + rstart, rend - rstart, $tabs);
	w3 = XfwfTextWidth($font, $label + rend, to - rend, $tabs);
 	w4 = XfwfTextWidth($font, $label + hstart, hend - hstart, $tabs);
 	w5 = XfwfTextWidth($font, $label + from, hstart - from, $tabs);
	if ($alignment & XfwfLeft)
	    x = rect.x;
	else if ($alignment & XfwfRight)
	    x = rect.x + rect.width - w1 - w2 - w3;
	else
	    x = rect.x + (rect.width - w1 - w2 - w3)/2;
	if (w1)
	    XfwfDrawString(dpy, win, $gc, x, y, $label + from,
			     rstart - from, $tabs);
	if (w2)
	    XfwfDrawImageString(dpy, win, $rv_gc, x + w1, y, $label
			     + rstart, rend - rstart, $tabs);
	if (w3)
	    XfwfDrawString(dpy, win, $gc, x + w1 + w2, y, $label +
			     rend, to - rend, $tabs);
 	if (w4)
 	    XfwfDrawString(dpy, win, $hl_gc, x + w5, y, $label
 			     + hstart, hend - hstart, $tabs);
    } while (0)

@proc expose
{
    Region reg;
    XRectangle rect;
    int baseline;
    int w1, w2, w3, w4, w5;
    char *s, *t;
    int x, y, i, j, rstart, rend, hstart, hend;

    if (! XtIsRealized($)) return;
    #expose($, event, region);
    if ($label != NULL) {
	baseline = $font->ascent + $font->descent;
	$compute_inside($, &rect.x, &rect.y, &rect.width, &rect.height);
	rect.x += $leftMargin;  rect.width -= $leftMargin + $rightMargin;
	rect.y += $topMargin;  rect.height -= $topMargin + $bottomMargin;
	reg = XCreateRegion();
	XUnionRectWithRegion(&rect, reg, reg);
	if (region != NULL) XIntersectRegion(region, reg, reg);
	XSetRegion(XtDisplay($), $gc, reg);
	XSetRegion(XtDisplay($), $rv_gc, reg);
 	XSetRegion(XtDisplay($), $hl_gc, reg);
	if ($alignment & XfwfTop)
	    y = rect.y + $font->ascent;
	else if ($alignment & XfwfBottom)
	    y = rect.y + rect.height - $nlines * baseline + $font->ascent;
	else
	    y = rect.y + (rect.height - $nlines * baseline)/2 + $font->ascent;
	for (i = 0, j = 0; $label[i]; i++) {
	    if ($label[i] == '\n') {
		draw_line(XtDisplay($), XtWindow($), j, i);
		j = i + 1;
		y += baseline;
	    }
	}
	draw_line(XtDisplay($), XtWindow($), j, i);

	/* Gray out if not sensitive */
	if (! $sensitive) {
	    XSetRegion(XtDisplay($), $graygc, reg);
	    XFillRectangle(XtDisplay($), XtWindow($), $graygc, rect.x,
			   rect.y, rect.width, rect.height);
	    XSetClipMask(XtDisplay($), $graygc, None);
	}
	XSetClipMask(XtDisplay($), $gc, None);
	XSetClipMask(XtDisplay($), $rv_gc, None);
 	XSetClipMask(XtDisplay($), $hl_gc, None);
    }
}



@utilities

@ The |make_gc| routine creates the GCs for the normal and highlighted
text.

@proc make_gc($)
{
    XtGCMask mask;
    XGCValues values;

    if ($gc != NULL) XtReleaseGC($, $gc);
    values.background = $background;
    values.foreground = $foreground;
    values.font = $font->fid;
    mask = GCFont | GCBackground | GCForeground;
    $gc = XtGetGC($, mask, &values);

    if ($rv_gc != NULL) XtReleaseGC($, $rv_gc);
    values.foreground = $background;
    values.background = $foreground;
    values.font = $font->fid;
    mask = GCFont | GCBackground | GCForeground;
    $rv_gc = XtGetGC($, mask, &values);

    if ($hl_gc != NULL) XtReleaseGC($, $hl_gc);
    values.background = $background;
    values.foreground = $hlForeground;
    values.font = $font->fid;
    values.function = GXcopy;
    $hl_gc = XtGetGC($, mask, &values);
}

@ The |make_graygc| routine creates a GC for graying out the text. It
contains a stipple in the background color, that will be applied over
the text.

@proc make_graygc($)
{
    XtGCMask mask;
    XGCValues values;

    if ($graygc != NULL) XtReleaseGC($, $graygc);
    values.foreground = $background;
    values.stipple =
	XCreateBitmapFromData(XtDisplay($),
			      RootWindowOfScreen(XtScreen($)),
			      stip4_bits, stip4_width, stip4_height);
    values.fill_style = FillStippled;
    mask = GCForeground | GCStipple | GCFillStyle;
    $graygc = XtGetGC($, mask, &values);
}

@ The funtion |count_lines| computes the correct values for the
private variables |nlines|, |label_width| and |label_height|.

@proc count_lines($)
{
    String p, s;
    int w;

    $nlines = 0;
    $label_width = 0;
    if ($label) {
	for (p = $label, $nlines = 1, s = $label; *s; s++) {
	    if (*s == '\n') {
		$nlines++;
		w = XfwfTextWidth($font, p, s - p, $tabs);
		p = s + 1;
		if (w > $label_width) $label_width = w;
	    }
	}
	w = XfwfTextWidth($font, p, s - p, $tabs);
	if (w > $label_width) $label_width = w;
    }
    $label_height = $nlines * ($font->ascent + $font->descent);
    $label_width += $leftMargin + $rightMargin;
    $label_height += $topMargin + $bottomMargin;
}

@imports

@incl "stip4.bm"

@incl <stdio.h>
@incl <Xfwf/TabString.h>
