/* Generated by wbuild from "Label.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 469 "Label.w"
#include "stip4.bm"
#line 471 "Label.w"
#include <stdio.h>
#line 472 "Label.w"
#include <Xfwf/TabString.h>
#include <Xfwf/LabelP.h>
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 174 "Label.w"
static void set_label(
#if NeedFunctionPrototypes
Widget,String 
#endif
);
#line 206 "Label.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 269 "Label.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 336 "Label.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 393 "Label.w"
static void make_gc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 424 "Label.w"
static void make_graygc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 443 "Label.w"
static void count_lines(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 393 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 393 "Label.w"
static void make_gc(Widget self)
#else
#line 393 "Label.w"
static void make_gc(self)Widget self;
#endif
#line 394 "Label.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfLabelWidget)self)->xfwfLabel.gc != NULL) XtReleaseGC(self, ((XfwfLabelWidget)self)->xfwfLabel.gc);
    values.background = ((XfwfLabelWidget)self)->xfwfCommon.background;
    values.foreground = ((XfwfLabelWidget)self)->xfwfLabel.foreground;
    values.font = ((XfwfLabelWidget)self)->xfwfLabel.font->fid;
    mask = GCFont | GCBackground | GCForeground;
    ((XfwfLabelWidget)self)->xfwfLabel.gc = XtGetGC(self, mask, &values);

    if (((XfwfLabelWidget)self)->xfwfLabel.rv_gc != NULL) XtReleaseGC(self, ((XfwfLabelWidget)self)->xfwfLabel.rv_gc);
    values.foreground = ((XfwfLabelWidget)self)->xfwfCommon.background;
    values.background = ((XfwfLabelWidget)self)->xfwfLabel.foreground;
    values.font = ((XfwfLabelWidget)self)->xfwfLabel.font->fid;
    mask = GCFont | GCBackground | GCForeground;
    ((XfwfLabelWidget)self)->xfwfLabel.rv_gc = XtGetGC(self, mask, &values);

    if (((XfwfLabelWidget)self)->xfwfLabel.hl_gc != NULL) XtReleaseGC(self, ((XfwfLabelWidget)self)->xfwfLabel.hl_gc);
    values.background = ((XfwfLabelWidget)self)->xfwfCommon.background;
    values.foreground = ((XfwfLabelWidget)self)->xfwfLabel.hlForeground;
    values.font = ((XfwfLabelWidget)self)->xfwfLabel.font->fid;
    values.function = GXcopy;
    ((XfwfLabelWidget)self)->xfwfLabel.hl_gc = XtGetGC(self, mask, &values);
}
#line 424 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 424 "Label.w"
static void make_graygc(Widget self)
#else
#line 424 "Label.w"
static void make_graygc(self)Widget self;
#endif
#line 425 "Label.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfLabelWidget)self)->xfwfLabel.graygc != NULL) XtReleaseGC(self, ((XfwfLabelWidget)self)->xfwfLabel.graygc);
    values.foreground = ((XfwfLabelWidget)self)->xfwfCommon.background;
    values.stipple =
	XCreateBitmapFromData(XtDisplay(self),
			      RootWindowOfScreen(XtScreen(self)),
			      stip4_bits, stip4_width, stip4_height);
    values.fill_style = FillStippled;
    mask = GCForeground | GCStipple | GCFillStyle;
    ((XfwfLabelWidget)self)->xfwfLabel.graygc = XtGetGC(self, mask, &values);
}
#line 443 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 443 "Label.w"
static void count_lines(Widget self)
#else
#line 443 "Label.w"
static void count_lines(self)Widget self;
#endif
#line 444 "Label.w"
{
    String p, s;
    int w;

    ((XfwfLabelWidget)self)->xfwfLabel.nlines = 0;
    ((XfwfLabelWidget)self)->xfwfLabel.label_width = 0;
    if (((XfwfLabelWidget)self)->xfwfLabel.label) {
	for (p = ((XfwfLabelWidget)self)->xfwfLabel.label, ((XfwfLabelWidget)self)->xfwfLabel.nlines = 1, s = ((XfwfLabelWidget)self)->xfwfLabel.label; *s; s++) {
	    if (*s == '\n') {
		((XfwfLabelWidget)self)->xfwfLabel.nlines++;
		w = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, p, s - p, ((XfwfLabelWidget)self)->xfwfLabel.tabs);
		p = s + 1;
		if (w > ((XfwfLabelWidget)self)->xfwfLabel.label_width) ((XfwfLabelWidget)self)->xfwfLabel.label_width = w;
	    }
	}
	w = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, p, s - p, ((XfwfLabelWidget)self)->xfwfLabel.tabs);
	if (w > ((XfwfLabelWidget)self)->xfwfLabel.label_width) ((XfwfLabelWidget)self)->xfwfLabel.label_width = w;
    }
    ((XfwfLabelWidget)self)->xfwfLabel.label_height = ((XfwfLabelWidget)self)->xfwfLabel.nlines * (((XfwfLabelWidget)self)->xfwfLabel.font->ascent + ((XfwfLabelWidget)self)->xfwfLabel.font->descent);
    ((XfwfLabelWidget)self)->xfwfLabel.label_width += ((XfwfLabelWidget)self)->xfwfLabel.leftMargin + ((XfwfLabelWidget)self)->xfwfLabel.rightMargin;
    ((XfwfLabelWidget)self)->xfwfLabel.label_height += ((XfwfLabelWidget)self)->xfwfLabel.topMargin + ((XfwfLabelWidget)self)->xfwfLabel.bottomMargin;
}

static XtResource resources[] = {
#line 29 "Label.w"
{XtNlabel,XtCLabel,XtRString,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.label),XtOffsetOf(XfwfLabelRec,xfwfLabel.label),XtRImmediate,(XtPointer)NULL },
#line 34 "Label.w"
{XtNtablist,XtCTablist,XtRString,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.tablist),XtOffsetOf(XfwfLabelRec,xfwfLabel.tablist),XtRImmediate,(XtPointer)NULL },
#line 38 "Label.w"
{XtNfont,XtCFont,XtRFontStruct,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.font),XtOffsetOf(XfwfLabelRec,xfwfLabel.font),XtRString,(XtPointer)XtDefaultFont },
#line 43 "Label.w"
{XtNforeground,XtCForeground,XtRColor,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.foreground),XtOffsetOf(XfwfLabelRec,xfwfLabel.foreground),XtRString,(XtPointer)XtDefaultForeground },
#line 44 "Label.w"
{XtNhlForeground,XtCHlForeground,XtRColor,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.hlForeground),XtOffsetOf(XfwfLabelRec,xfwfLabel.hlForeground),XtRString,(XtPointer)XtDefaultForeground },
#line 56 "Label.w"
{XtNalignment,XtCAlignment,XtRAlignment,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.alignment),XtOffsetOf(XfwfLabelRec,xfwfLabel.alignment),XtRImmediate,(XtPointer)0 },
#line 61 "Label.w"
{XtNtopMargin,XtCTopMargin,XtRDimension,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.topMargin),XtOffsetOf(XfwfLabelRec,xfwfLabel.topMargin),XtRImmediate,(XtPointer)2 },
#line 66 "Label.w"
{XtNbottomMargin,XtCBottomMargin,XtRDimension,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.bottomMargin),XtOffsetOf(XfwfLabelRec,xfwfLabel.bottomMargin),XtRImmediate,(XtPointer)2 },
#line 73 "Label.w"
{XtNleftMargin,XtCLeftMargin,XtRDimension,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.leftMargin),XtOffsetOf(XfwfLabelRec,xfwfLabel.leftMargin),XtRImmediate,(XtPointer)2 },
#line 78 "Label.w"
{XtNrightMargin,XtCRightMargin,XtRDimension,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.rightMargin),XtOffsetOf(XfwfLabelRec,xfwfLabel.rightMargin),XtRImmediate,(XtPointer)2 },
#line 85 "Label.w"
{XtNshrinkToFit,XtCShrinkToFit,XtRBoolean,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.shrinkToFit),XtOffsetOf(XfwfLabelRec,xfwfLabel.shrinkToFit),XtRImmediate,(XtPointer)False },
#line 91 "Label.w"
{XtNrvStart,XtCRvStart,XtRInt,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.rvStart),XtOffsetOf(XfwfLabelRec,xfwfLabel.rvStart),XtRImmediate,(XtPointer)0 },
#line 96 "Label.w"
{XtNrvLength,XtCRvLength,XtRInt,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.rvLength),XtOffsetOf(XfwfLabelRec,xfwfLabel.rvLength),XtRImmediate,(XtPointer)0 },
#line 101 "Label.w"
{XtNtraversalOn,XtCTraversalOn,XtRBoolean,sizeof(((XfwfLabelRec*)NULL)->xfwfCommon.traversalOn),XtOffsetOf(XfwfLabelRec,xfwfCommon.traversalOn),XtRImmediate,(XtPointer)False },
#line 106 "Label.w"
{XtNhlStart,XtCHlStart,XtRInt,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.hlStart),XtOffsetOf(XfwfLabelRec,xfwfLabel.hlStart),XtRImmediate,(XtPointer)0 },
#line 107 "Label.w"
{XtNhlLength,XtCHlLength,XtRInt,sizeof(((XfwfLabelRec*)NULL)->xfwfLabel.hlLength),XtOffsetOf(XfwfLabelRec,xfwfLabel.hlLength),XtRImmediate,(XtPointer)0 },
};

XfwfLabelClassRec xfwfLabelClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfBoardClassRec,
/* class_name   	*/  "XfwfLabel",
/* widget_size  	*/  sizeof(XfwfLabelRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  NULL,
/* num_actions  	*/  0,
/* resources    	*/  resources,
/* num_resources 	*/  16,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple ,
/* compress_enterleave 	*/  True ,
/* visible_interest 	*/  TRUE ,
/* destroy      	*/  NULL,
/* resize       	*/  XtInheritResize,
/* expose       	*/  expose,
/* set_values   	*/  set_values,
/* set_values_hook 	*/  NULL,
/* set_values_almost 	*/  XtInheritSetValuesAlmost,
/* get_values+hook 	*/  NULL,
/* accept_focus 	*/  XtInheritAcceptFocus,
/* version      	*/  XtVersion,
/* callback_private 	*/  NULL,
/* tm_table      	*/  NULL,
/* query_geometry 	*/  XtInheritQueryGeometry,
/* display_acceleator 	*/  XtInheritDisplayAccelerator,
/* extension    	*/  NULL 
},
{ /* composite_class part */
XtInheritGeometryManager,
XtInheritChangeManaged,
XtInheritInsertChild,
XtInheritDeleteChild,
NULL
},
{ /* XfwfCommon_class part */
XtInherit_compute_inside,
XtInherit_total_frame_width,
XtInherit_highlight_border,
XtInherit_unhighlight_border,
XtInherit_would_accept_focus,
XtInherit_traverse,
XtInherit_lighter_color,
XtInherit_darker_color,
/* traversal_trans */  NULL ,
},
{ /* XfwfFrame_class part */
 /* dummy */  0
},
{ /* XfwfBoard_class part */
XtInherit_set_abs_location,
},
{ /* XfwfLabel_class part */
set_label,
},
};
WidgetClass xfwfLabelWidgetClass = (WidgetClass) &xfwfLabelClassRec;
static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfLabelWidgetClass c = (XfwfLabelWidgetClass) class;
  XfwfLabelWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfLabelWidgetClass) return;
  super = (XfwfLabelWidgetClass)class->core_class.superclass;
  if (c->xfwfLabel_class.set_label == XtInherit_set_label)
    c->xfwfLabel_class.set_label = super->xfwfLabel_class.set_label;
}
#line 174 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 174 "Label.w"
static void set_label(Widget self,String  newlabel)
#else
#line 174 "Label.w"
static void set_label(self,newlabel)Widget self;String  newlabel;
#endif
#line 175 "Label.w"
{
    XRectangle rect;
    Region clip;

    if (((XfwfLabelWidget)self)->xfwfLabel.shrinkToFit) {
	XtVaSetValues(self, XtNlabel, newlabel, NULL);
    } else {
	XtFree(((XfwfLabelWidget)self)->xfwfLabel.label);
	((XfwfLabelWidget)self)->xfwfLabel.label = XtNewString(newlabel);
	count_lines(self);
	if (XtIsRealized(self)) {
	    ((XfwfLabelWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &rect.x, &rect.y, &rect.width, &rect.height);
	    clip = XCreateRegion();
	    XUnionRectWithRegion(&rect, clip, clip);
	    XClearArea(XtDisplay(self), XtWindow(self), rect.x, rect.y,
		       rect.width, rect.height, FALSE);
	    ((XfwfLabelWidgetClass)self->core.widget_class)->core_class.expose(self, NULL, clip);
	    XDestroyRegion(clip);
	}
    }
}
#line 206 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 206 "Label.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 206 "Label.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 207 "Label.w"
{
    Boolean need_redisplay = False, need_count = False;
    Position x, y;
    Dimension w, h, wd, ht;

    if (((XfwfLabelWidget)self)->xfwfCommon.background != ((XfwfLabelWidget)old)->xfwfCommon.background)
	make_graygc(self);

    if (((XfwfLabelWidget)self)->xfwfLabel.tablist != ((XfwfLabelWidget)old)->xfwfLabel.tablist) {
	XtFree((String) ((XfwfLabelWidget)old)->xfwfLabel.tabs);
	((XfwfLabelWidget)self)->xfwfLabel.tabs = XfwfTablist2Tabs(((XfwfLabelWidget)self)->xfwfLabel.tablist);
	if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) need_count = True;
    }

    if (((XfwfLabelWidget)self)->xfwfLabel.font != ((XfwfLabelWidget)old)->xfwfLabel.font) {
	make_gc(self);
	if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) need_count = True;
    }
    if (((XfwfLabelWidget)self)->xfwfLabel.foreground != ((XfwfLabelWidget)old)->xfwfLabel.foreground
 	|| ((XfwfLabelWidget)self)->xfwfLabel.hlForeground != ((XfwfLabelWidget)self)->xfwfLabel.hlForeground
	|| ((XfwfLabelWidget)self)->xfwfCommon.background != ((XfwfLabelWidget)old)->xfwfCommon.background) {
	make_gc(self);
	if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) need_redisplay = True;
    }
    if (((XfwfLabelWidget)self)->xfwfLabel.topMargin != ((XfwfLabelWidget)old)->xfwfLabel.topMargin
	|| ((XfwfLabelWidget)self)->xfwfLabel.bottomMargin != ((XfwfLabelWidget)old)->xfwfLabel.bottomMargin
	|| ((XfwfLabelWidget)self)->xfwfLabel.leftMargin != ((XfwfLabelWidget)old)->xfwfLabel.leftMargin
	|| ((XfwfLabelWidget)self)->xfwfLabel.rightMargin != ((XfwfLabelWidget)old)->xfwfLabel.rightMargin)
	need_count = True;

    if (((XfwfLabelWidget)self)->core.sensitive != ((XfwfLabelWidget)old)->core.sensitive)
	if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) need_redisplay = True;

    if (((XfwfLabelWidget)self)->xfwfLabel.rvStart != ((XfwfLabelWidget)old)->xfwfLabel.rvStart || ((XfwfLabelWidget)self)->xfwfLabel.rvLength != ((XfwfLabelWidget)old)->xfwfLabel.rvLength
 	|| ((XfwfLabelWidget)self)->xfwfLabel.hlStart != ((XfwfLabelWidget)old)->xfwfLabel.hlStart || ((XfwfLabelWidget)self)->xfwfLabel.hlLength != ((XfwfLabelWidget)old)->xfwfLabel.hlLength)
	if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) need_redisplay = True;

    if (((XfwfLabelWidget)self)->xfwfLabel.label != ((XfwfLabelWidget)old)->xfwfLabel.label) {
	XtFree(((XfwfLabelWidget)old)->xfwfLabel.label);
	((XfwfLabelWidget)self)->xfwfLabel.label = XtNewString(((XfwfLabelWidget)self)->xfwfLabel.label);
	need_count = True;
    }
    if (need_count) {
	count_lines(self);
	need_redisplay = True;
    }
    if (need_count && ((XfwfLabelWidget)self)->xfwfLabel.shrinkToFit) {
	((XfwfLabelWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
	wd = ((XfwfLabelWidget)self)->xfwfLabel.label_width + ((XfwfLabelWidget)self)->core.width - w;
	ht = ((XfwfLabelWidget)self)->xfwfLabel.label_height + ((XfwfLabelWidget)self)->core.height - h;
	if (wd != ((XfwfLabelWidget)self)->core.width || ht != ((XfwfLabelWidget)self)->core.height) {
	    ((XfwfLabelWidgetClass)self->core.widget_class)->xfwfBoard_class.set_abs_location(self, CWWidth | CWHeight, 0, 0, wd, ht);
	    need_redisplay = True;              /* or False? [BB 951207] */
	}
    }
    return need_redisplay;
}
#line 269 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 269 "Label.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 269 "Label.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 270 "Label.w"
{
    Position x, y;
    Dimension w, h, wd, ht;

    if (((XfwfLabelWidget)self)->xfwfLabel.label) ((XfwfLabelWidget)self)->xfwfLabel.label = XtNewString(((XfwfLabelWidget)self)->xfwfLabel.label);
    ((XfwfLabelWidget)self)->xfwfLabel.tabs = XfwfTablist2Tabs(((XfwfLabelWidget)self)->xfwfLabel.tablist);
    count_lines(self);
    ((XfwfLabelWidget)self)->xfwfLabel.gc = NULL;
    ((XfwfLabelWidget)self)->xfwfLabel.rv_gc = NULL;
    ((XfwfLabelWidget)self)->xfwfLabel.graygc = NULL;
    ((XfwfLabelWidget)self)->xfwfLabel.hl_gc = NULL;
    make_gc(self);
    make_graygc(self);
    if (((XfwfLabelWidget)self)->xfwfLabel.shrinkToFit) {
	((XfwfLabelWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
	wd = ((XfwfLabelWidget)self)->xfwfLabel.label_width + ((XfwfLabelWidget)self)->core.width - w;
	ht = ((XfwfLabelWidget)self)->xfwfLabel.label_height + ((XfwfLabelWidget)self)->core.height - h;
	((XfwfLabelWidgetClass)self->core.widget_class)->xfwfBoard_class.set_abs_location(self, CWWidth | CWHeight, 0, 0, wd, ht);
    }
}
#define draw_line(dpy, win, from, to) do {\
	if (((XfwfLabelWidget)self)->xfwfLabel.hlStart >= to) hstart = to;\
 	else hstart = max(((XfwfLabelWidget)self)->xfwfLabel.hlStart, from);\
	if (((XfwfLabelWidget)self)->xfwfLabel.hlStart + ((XfwfLabelWidget)self)->xfwfLabel.hlLength <= from) hend = hstart;\
 	else hend = min(((XfwfLabelWidget)self)->xfwfLabel.hlStart + ((XfwfLabelWidget)self)->xfwfLabel.hlLength, to);\
        if (((XfwfLabelWidget)self)->xfwfLabel.rvStart >= to) rstart = to;\
	else rstart = max(((XfwfLabelWidget)self)->xfwfLabel.rvStart, from);\
	if (((XfwfLabelWidget)self)->xfwfLabel.rvStart + ((XfwfLabelWidget)self)->xfwfLabel.rvLength <= from) rend = rstart;\
	else rend = min(((XfwfLabelWidget)self)->xfwfLabel.rvStart + ((XfwfLabelWidget)self)->xfwfLabel.rvLength, to);\
	w1 = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, ((XfwfLabelWidget)self)->xfwfLabel.label + from, rstart - from, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
	w2 = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, ((XfwfLabelWidget)self)->xfwfLabel.label + rstart, rend - rstart, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
	w3 = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, ((XfwfLabelWidget)self)->xfwfLabel.label + rend, to - rend, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
 	w4 = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, ((XfwfLabelWidget)self)->xfwfLabel.label + hstart, hend - hstart, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
 	w5 = XfwfTextWidth(((XfwfLabelWidget)self)->xfwfLabel.font, ((XfwfLabelWidget)self)->xfwfLabel.label + from, hstart - from, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
	if (((XfwfLabelWidget)self)->xfwfLabel.alignment & XfwfLeft)\
	    x = rect.x;\
	else if (((XfwfLabelWidget)self)->xfwfLabel.alignment & XfwfRight)\
	    x = rect.x + rect.width - w1 - w2 - w3;\
	else\
	    x = rect.x + (rect.width - w1 - w2 - w3)/2;\
	if (w1)\
	    XfwfDrawString(dpy, win, ((XfwfLabelWidget)self)->xfwfLabel.gc, x, y, ((XfwfLabelWidget)self)->xfwfLabel.label + from,\
			     rstart - from, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
	if (w2)\
	    XfwfDrawImageString(dpy, win, ((XfwfLabelWidget)self)->xfwfLabel.rv_gc, x + w1, y, ((XfwfLabelWidget)self)->xfwfLabel.label\
			     + rstart, rend - rstart, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
	if (w3)\
	    XfwfDrawString(dpy, win, ((XfwfLabelWidget)self)->xfwfLabel.gc, x + w1 + w2, y, ((XfwfLabelWidget)self)->xfwfLabel.label +\
			     rend, to - rend, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
 	if (w4)\
 	    XfwfDrawString(dpy, win, ((XfwfLabelWidget)self)->xfwfLabel.hl_gc, x + w5, y, ((XfwfLabelWidget)self)->xfwfLabel.label\
 			     + hstart, hend - hstart, ((XfwfLabelWidget)self)->xfwfLabel.tabs);\
    }while (0 )


#line 336 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 336 "Label.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 336 "Label.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 337 "Label.w"
{
    Region reg;
    XRectangle rect;
    int baseline;
    int w1, w2, w3, w4, w5;
    int x, y, i, j, rstart, rend, hstart, hend;

    if (! XtIsRealized(self)) return;
    xfwfBoardClassRec.core_class.expose(self, event, region);
    if (((XfwfLabelWidget)self)->xfwfLabel.label != NULL) {
	baseline = ((XfwfLabelWidget)self)->xfwfLabel.font->ascent + ((XfwfLabelWidget)self)->xfwfLabel.font->descent;
	((XfwfLabelWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &rect.x, &rect.y, &rect.width, &rect.height);
	rect.x += ((XfwfLabelWidget)self)->xfwfLabel.leftMargin;  rect.width -= ((XfwfLabelWidget)self)->xfwfLabel.leftMargin + ((XfwfLabelWidget)self)->xfwfLabel.rightMargin;
	rect.y += ((XfwfLabelWidget)self)->xfwfLabel.topMargin;  rect.height -= ((XfwfLabelWidget)self)->xfwfLabel.topMargin + ((XfwfLabelWidget)self)->xfwfLabel.bottomMargin;
	reg = XCreateRegion();
	XUnionRectWithRegion(&rect, reg, reg);
	if (region != NULL) XIntersectRegion(region, reg, reg);
	XSetRegion(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.gc, reg);
	XSetRegion(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.rv_gc, reg);
 	XSetRegion(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.hl_gc, reg);
	if (((XfwfLabelWidget)self)->xfwfLabel.alignment & XfwfTop)
	    y = rect.y + ((XfwfLabelWidget)self)->xfwfLabel.font->ascent;
	else if (((XfwfLabelWidget)self)->xfwfLabel.alignment & XfwfBottom)
	    y = rect.y + rect.height - ((XfwfLabelWidget)self)->xfwfLabel.nlines * baseline + ((XfwfLabelWidget)self)->xfwfLabel.font->ascent;
	else
	    y = rect.y + (rect.height - ((XfwfLabelWidget)self)->xfwfLabel.nlines * baseline)/2 + ((XfwfLabelWidget)self)->xfwfLabel.font->ascent;
	for (i = 0, j = 0; ((XfwfLabelWidget)self)->xfwfLabel.label[i]; i++) {
	    if (((XfwfLabelWidget)self)->xfwfLabel.label[i] == '\n') {
		draw_line(XtDisplay(self), XtWindow(self), j, i);
		j = i + 1;
		y += baseline;
	    }
	}
	draw_line(XtDisplay(self), XtWindow(self), j, i);

	/* Gray out if not sensitive */
	if (! ((XfwfLabelWidget)self)->core.sensitive) {
	    XSetRegion(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.graygc, reg);
	    XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfLabelWidget)self)->xfwfLabel.graygc, rect.x,
			   rect.y, rect.width, rect.height);
	    XSetClipMask(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.graygc, None);
	}
	XSetClipMask(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.gc, None);
	XSetClipMask(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.rv_gc, None);
 	XSetClipMask(XtDisplay(self), ((XfwfLabelWidget)self)->xfwfLabel.hl_gc, None);
    }
}
#line 153 "Label.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 153 "Label.w"
void XfwfLabelSetLabel(Widget self,String  newlabel)
#else
#line 153 "Label.w"
void XfwfLabelSetLabel(self,newlabel)Widget self;String  newlabel;
#endif
#line 154 "Label.w"
{
    if (! XtIsSubclass(self, xfwfLabelWidgetClass))
	XtError("XfwfLabelSetLabel called with incorrect widget type");
    ((XfwfLabelWidgetClass)self->core.widget_class)->xfwfLabel_class.set_label(self, newlabel);
}
