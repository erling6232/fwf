# ScrollWin.w -- ScrolledWindow widget
# Author: Bert Bos <bert@let.rug.nl>
# Copyright: see README file
# Version: 1.1 (see README for history)

@CLASS XfwfScrolledWindow (XfwfBoard)  @file = ScrollWin

@ The ScrolledWindow widget is a composite widget composed of two
Scrollbars and a Board within a Frame, and presumably a
grandgrandchild which is a child of the Board. The grandgrandchild is
called the `controlled widget' (CW). Usually, the controlled widget is
larger than the Board, and its origin will have negative x and y
coordinates. It is moved about inside the Board by the ScrolledWindow,
in reaction to the user clicking on the scrollbars. The controlled
widget is therefore clipped by the Board.

The ScrolledWindow provides a callback, but most application will not
need it, since the ScrolledWindow already moves the CW. The callback
is invoked {\em after} the CW is moved.


@PUBLIC

@ By default, the Frame widget and the Scrollbars are placed 4 pixels
from each other and from the edges of the ScrolledWindow itself.

	@var Dimension spacing = 4

@ The width of the scrollbars can be set with the |scrollbarWidth|
resource. The default is 22 pixels.

	@var Dimension scrollbarWidth = 22

@ The scrollbars and the frame have the same shadow frame. (The board
has no border or frame.) The width of both is set with a single
resource: |shadowWidth|. The style of the shadow cannot be changed. It
will always be |XfwfSunken|.

	@var Dimension shadowWidth = 2

@ It is possible to switch off the display of the scrollbars, with the
following two resources: |hideHScrollbar| is by default |False|.

	@var Boolean hideHScrollbar = False

@ |hideVScrollbar| is also by default |False|.

	@var Boolean hideVScrollbar = False

@ When the arrows of the scrollbars are clicked, the controlled widget
will be moved a fixed number of pixels in the indicated direction. The
distance can be set separately for horizontal and vertical movement.
E.g., if the controlled widget displays text, it is a good idea to set
the vertical scroll distance to the height of one line of text.

	@var int vScrollAmount = 20

@ The horizontal amount is by default copied from the vertical amount.

	@var int hScrollAmount = <CallProc> copy_vScrollAmount

@ The initial position of the CW can be set with the resources
|initialX| and |initialY|. Both are given in pixels and must be zero
or negative.

	@var Position initialX = 0

@ |initialY| is for the vertical position.

	@var Position initialY = 0

@ The callback is passed a pointer to an |XfwfScrollInfo| structure,
which is defined as |struct { XfwfSReason reason; XfwfSFlags flags;
float vpos, vsize, hpos, hsize; }| The |reason| can be:

* |XfwfSUp|: if the user clicked (or holds) the up arrow.

* |XfwfSLeft|: ditto left arrow.

* |XfwfSDown|: ditto down arrow.

* |XfwfSRight|: ditto right arrow.

* |XfwfSPageUp|: ditto area above thumb.

* |XfwfSPageDown|: ditto area below thumb.

* |XfwfSPageLeft|: ditto area left of thumb.

* |XfwfSPageRight|: ditto area right of thumb.

* |XfwfSDrag|: if the user drags one of the thumbs.

* |XfwfSMove|: if the user stops dragging the thumb.

* |XfwfSTop|: if the user requests to scroll all the way up.

* |XfwfSBottom|: same all the way down.

* |XfwfSLeftSide|: same to the left side.

* |XfwfSRightSide|: same to the right side.

Note that when the callback is called, the controlled window has
already been moved.

	@var <Callback> XtCallbackList scrollCallback = NULL

@ To set the scrolled window toaparticular position, the
scrollResponse function must be used. The function has the type
of a callback function and it must be retrieved with a call to
|XtGetValues|.

	@var XtCallbackProc scrollResponse = scroll_response


@PRIVATE

@ The ScrolledWindow widget has exactly three children, one grandchild
and one grandgrandchild. For convenience they are stored in private
variables as well as in the |children| field.

	@var Widget vscroll
	@var Widget hscroll
	@var Widget frame
	@var Widget board
	@var Widget CW

@ The variable |initializing| is set to |True| in the |initialize|
method, so that the |insert_child| method can see that the inserted
child is one of the three proper children.

	@var Boolean initializing

@ The scroll bars have scrollResponse function, that will be called if
the scrolled window itself received a call to its scrollResponse
function.

	@var XtCallbackProc vscroll_resp
	@var XtCallbackProc hscroll_resp


@METHODS

@ The |initialize| method creates the three child widgets and the
grandchild and sets the CW to NULL. The resources of the children are
set to fixed values and some of the ScrolledWindow's resources are
copied. The board widget will automatically be set to the correct size
by the frame widget.

@proc initialize
{
    $initializing = True;
    if ($initialX > 0) $initialX = 0;
    if ($initialY > 0) $initialY = 0;
    $CW = NULL;
    $frame = XtVaCreateManagedWidget
	("_frame", xfwfFrameWidgetClass, $, XtNframeType, XfwfSunken,
	 XtNframeWidth, $shadowWidth, XtNborderWidth, 0,
	 XtNhighlightThickness, 0, NULL);
    $board = XtVaCreateManagedWidget
	("_board", xfwfBoardWidgetClass, $frame, XtNframeWidth, 0,
	 XtNborderWidth, 0, XtNhighlightThickness, 0, NULL);
    $vscroll = XtVaCreateWidget
	("_vscroll", xfwfVScrollbarWidgetClass, $, XtNframeWidth,
	 $shadowWidth, XtNframeType, XfwfSunken, XtNborderWidth, 0, NULL);
    $hscroll = XtVaCreateWidget
	("_hscroll", xfwfHScrollbarWidgetClass, $, XtNframeWidth,
	 $shadowWidth, XtNframeType, XfwfSunken, XtNborderWidth, 0, NULL);
    if (! $hideVScrollbar) XtManageChild($vscroll);
    if (! $hideHScrollbar) XtManageChild($hscroll);
    compute_sizes($);
    XtAddCallback($vscroll, XtNscrollCallback, scroll_callback, $);
    XtAddCallback($hscroll, XtNscrollCallback, scroll_callback, $);
    XtVaGetValues($vscroll, XtNscrollResponse, &$vscroll_resp, NULL);
    XtVaGetValues($hscroll, XtNscrollResponse, &$hscroll_resp, NULL);
    $initializing = False;
    if ($scrollResponse != scroll_response) {
	$scrollResponse = scroll_response;
	XtWarning("scrollResponse resource may only be queried, not set");
    }
}

@ Changes in the resources cause the scrolled window to recompute the
layout of its three children.

The |scrollResponse| resource may not be changed.

@proc set_values
{
    if ($old$spacing != $spacing
	|| $old$scrollbarWidth != $scrollbarWidth
	|| $old$shadowWidth != $shadowWidth
	|| $old$hideHScrollbar != $hideHScrollbar
	|| $old$hideVScrollbar != $hideVScrollbar)
	compute_sizes($);
    if ($old$hideVScrollbar && ! $hideVScrollbar)
	XtUnmanageChild($vscroll);
    else if (! $old$hideVScrollbar && $hideVScrollbar)
	XtManageChild($vscroll);
    if ($old$hideHScrollbar && ! $hideHScrollbar)
	XtUnmanageChild($hscroll);
    else if (! $old$hideHScrollbar && $hideHScrollbar)
	XtManageChild($hscroll);
    if ($scrollResponse != $old$scrollResponse) {
	$scrollResponse = $old$scrollResponse;
	XtWarning("scrollResponse resource may only be queried, not set");
    }
    return False;
}


@ When the scrolled window is resized, the scrollbars and the frame
should be repositioned. Also, the thumbs in the scrollbars will have
to change size, but for that purpose there is an event handler that
will intercept changes to the configuration of the CW or the board.
The event handler is installed when the CW is inserted (in the
|insert_child| method) and removed again when the child is destroyed
(in the |CW_killed| callback routine).

@proc resize
{
    compute_sizes($);
}


@ The |insert_child| method performs some tricks to ensure that the
three proper children are added normally, that the fourth is passed on
to the board and that any other children are refused.

When the CW is added as a child of the board, the scrollbars are
initialized to the current position and size of the CW relative to the
board.

@proc insert_child
{
    Widget board;
    Position boardx, boardy, gx, gy;
    Dimension boardwd, boardht, gwd, ght;
    float wd, ht, x, y;
    Boolean dummy;

    if ($initializing) {
	#insert_child(child);
    } else if ($CW == NULL) {
	$CW = child;
	$child$parent = $board;
	XtAddCallback(child, XtNdestroyCallback, CW_killed, $);
	#insert_child(child);
	XtAddEventHandler(child, StructureNotifyMask, False, configure, $);
	XtAddEventHandler($board, StructureNotifyMask, False, configure, $);
	$compute_inside($board, &boardx, &boardy, &boardwd, &boardht);
	XtVaGetValues(child, XtNwidth, &gwd, XtNheight, &ght, NULL);
	gx = gwd <= boardwd ? 0 : max($initialX, boardwd - gwd);
	gy = ght <= boardht ? 0 : max($initialY, boardht - ght);
	XtMoveWidget(child, gx, gy);
	configure($, $, NULL, &dummy);
    } else {
	char s[500];
	(void) sprintf(s, "Cannot add <%s>, %s <%s> already has a child\n",
		       XtName(child), "ScrolledWindow", XtName($));
	XtWarning(s);
    }
}


@ When the scrolled window widget is destroyed, the event handler is
removed (if it was installed).

@proc destroy
{
    if ($CW != NULL) {
	XtRemoveEventHandler($CW, StructureNotifyMask, False,
			     configure, $);
	XtRemoveEventHandler($board, StructureNotifyMask, False,
			     configure, $);
    }
}

@ When the ScrolledWindow widget is configured from outside, this is
done through a call to the |scroll_response| method.

@proc scroll_response(Widget w, XtPointer client_data, XtPointer call_data)
{
    Widget $ = (Widget) client_data;
    XfwfScrollInfo *info = (XfwfScrollInfo *) call_data;
    XfwfScrollInfo new;
    Position boardx, boardy, gx, gy, minx, miny;
    Dimension boardwd, boardht, gwd, ght;
    float wd, ht, x, y;

    $compute_inside($board, &boardx, &boardy, &boardwd, &boardht);
    XtVaGetValues($CW, XtNx, &gx, XtNy, &gy, XtNwidth, &gwd,
		  XtNheight, &ght, NULL);
    minx = gwd <= boardwd ? 0 : boardwd - gwd;
    miny = ght <= boardht ? 0 : boardht - ght;

    if (info->flags & XFWF_VPOS) gy = info->vpos * miny;
    if (info->flags & XFWF_HPOS) gx = info->hpos * minx;

    XtMoveWidget($CW, gx, gy);

    if (info->reason != XfwfSNotify) {
	new.reason = XfwfSNotify;
	new.flags = info->flags & (XFWF_VPOS | XFWF_HPOS);
	new.hpos = info->hpos;
	new.vpos = info->vpos;
	XtCallCallbackList($, $scrollCallback, &new);
    }
}
    

@UTILITIES

@ |compute_sizes| is used by |initialize|, |resize| and |set_values|
to configure the children.

@proc compute_sizes($)
{
    Dimension selfw, selfh, framew, frameh, vsheight, hswidth;
    Position selfx, selfy;

    $compute_inside($, &selfx, &selfy, &selfw, &selfh);
    if (! $hideHScrollbar)
	vsheight = selfh - 3 * $spacing - $scrollbarWidth;
    else
	vsheight = selfh - 2 * $spacing;
    if (! $hideVScrollbar)
	hswidth = selfw - 3 * $spacing - $scrollbarWidth;
    else
	hswidth = selfw - 2 * $spacing;
    XtConfigureWidget($vscroll,
		      selfx + selfw - $spacing - $scrollbarWidth,
		      selfy + $spacing,
		      $scrollbarWidth,
		      vsheight,
		      0);
    XtConfigureWidget($hscroll,
		      $spacing,
		      selfy + selfh - $spacing - $scrollbarWidth,
		      hswidth,
		      $scrollbarWidth,
		      0);
    framew = selfw - 2 * $spacing;
    frameh = selfh - 2 * $spacing;
    if (! $hideVScrollbar) framew -= $scrollbarWidth + $spacing;
    if (! $hideHScrollbar) frameh -= $scrollbarWidth + $spacing;
    XtConfigureWidget($frame,
		      selfx + $spacing,
		      selfy + $spacing,
		      framew,
		      frameh,
		      0);
    if ($CW != NULL) XtMoveWidget($CW, 0, 0);
}


@ The |copy_vScrollAmount| routine is a resource default function. It
copies the value of the |vScrollAmount| resource to the
|hScrollAmount| resource.

@proc copy_vScrollAmount($, int offset, XrmValue* value)
{
    value->addr = (XtPointer) &$vScrollAmount;
}


@ When the user interacts with the scrollbar, this callback is called.
In response, the ScrolledWindow moves its CW and -- if it was not a
Notify message -- then calls its own callbacks.

@proc scroll_callback(Widget w, XtPointer client_data, XtPointer call_data)
{
    Widget $ = (Widget) client_data;
    XfwfScrollInfo *info = (XfwfScrollInfo *) call_data;
    XfwfScrollInfo new;
    Position boardx, boardy, gx, gy, minx, miny;
    Dimension boardwd, boardht, gwd, ght;
    float wd, ht, x, y;

    $compute_inside($board, &boardx, &boardy, &boardwd, &boardht);
    XtVaGetValues($CW, XtNx, &gx, XtNy, &gy, XtNwidth, &gwd,
		  XtNheight, &ght, NULL);
    minx = gwd <= boardwd ? 0 : boardwd - gwd;
    miny = ght <= boardht ? 0 : boardht - ght;
    switch (info->reason) {
    case XfwfSUp: gy = min(gy + $vScrollAmount, 0); break;
    case XfwfSDown: gy = max(gy - $vScrollAmount, miny); break;
    case XfwfSLeft: gx = min(gx + $hScrollAmount, 0); break;
    case XfwfSRight: gx = max(gx - $hScrollAmount, minx); break;
    case XfwfSPageUp: gy = min(gy + boardht, 0); break;
    case XfwfSPageDown: gy = max(gy - boardht, miny); break;
    case XfwfSPageLeft: gx = min(gx + boardwd, 0); break;
    case XfwfSPageRight: gx = max(gx - boardwd, minx); break;
    case XfwfSDrag:
	if (w == $vscroll) gy = info->vpos * miny;
	else gx = info->hpos * minx;
	break;
    case XfwfSMove: break;
    case XfwfSTop: gy = 0; break;
    case XfwfSBottom: gy = miny; break;
    case XfwfSLeftSide: gx = 0; break;
    case XfwfSRightSide: gx = minx; break;
    }
    XtMoveWidget($CW, gx, gy);
    if (info->reason != XfwfSNotify) {
	new.reason = XfwfSNotify;
	new.flags = XFWF_VPOS | XFWF_HPOS;
	new.hpos = minx == 0 ? 0.0 : gx/minx;
	new.vpos = miny == 0 ? 0.0 : gy/miny;
	XtCallCallbackList($, $scrollCallback, &new);
    }
}


@ When the CW is destroyed, the private variable |CW|
must be set back to |NULL|. The event handler that was installed to
intercept changes to the board and the CW must also be
removed.  The scrollbars are set to their `resting position'.

@proc CW_killed(Widget w, XtPointer client_data, XtPointer call_data)
{
    Widget $ = (Widget) client_data;

    XtRemoveEventHandler(w, StructureNotifyMask, False, configure, $);
    XtRemoveEventHandler($board, StructureNotifyMask, False, configure, $);
    $CW = NULL;
    XfwfSetScrollbar($vscroll, 0.0, 1.0);
    XfwfSetScrollbar($hscroll, 0.0, 1.0);
}


@ The |configure| routine is called when the CW or the board receive
ConfigureNotify events (and a few others, which are not useful).  It
is also called by |insert_child|, when the CW is first created.  The
changed size of these widgets results in different sizes for the
sliders in the scrollbars.

@proc configure(Widget w, XtPointer client_data, XEvent *event, Boolean *cont)
{
    Widget $ = (Widget) client_data;
    Dimension boardwd, boardht, gwd, ght;
    Position boardx, boardy, gx, gy;
    float wd, ht, x, y;

    if (event != NULL && event->type != ConfigureNotify) return;
    $compute_inside($board, &boardx, &boardy, &boardwd, &boardht);
    XtVaGetValues($CW, XtNx, &gx, XtNy, &gy, XtNwidth, &gwd,
		  XtNheight, &ght, NULL);
    wd = gwd <= boardwd ? 1.0 : (float) boardwd/gwd;
    ht = ght <= boardht ? 1.0 : (float) boardht/ght;
    x = gwd <= boardwd ? 0.0 : gx/(((float) boardwd) - gwd);
    y = ght <= boardht ? 0.0 : gy/(((float) boardht) - ght);
    if (x > 1.0) x = 1.0;
    if (y > 1.0) y = 1.0;
    XfwfSetScrollbar($hscroll, x, wd);
    XfwfSetScrollbar($vscroll, y, ht);
}


@IMPORTS

@incl <stdio.h>
@incl <Xfwf/Frame.h>
@incl <Xfwf/Board.h>
@incl <Xfwf/VScrollb.h>
@incl <Xfwf/HScrollb.h>
@incl <Xfwf/scroll.h>
