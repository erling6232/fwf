/* Generated by wbuild from "Slider4.w"
** (generator version $Revision$ of $Date$)
*/
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <Xfwf/Slider4P.h>
#line 83 "Slider4.w"
static void start(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 148 "Slider4.w"
static void finish(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 175 "Slider4.w"
static void drag(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"start", start},
{"finish", finish},
{"drag", drag},
};

static char defaultTranslations[] = "\
<Btn1Down>: start() \n\
<Btn1Motion>: drag() \n\
<Btn1Up>: finish() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 227 "Slider4.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 241 "Slider4.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 334 "Slider4.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 379 "Slider4.w"
static void create_sashgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 398 "Slider4.w"
static void create_sashlightgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 442 "Slider4.w"
static void create_sashdarkgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 379 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 379 "Slider4.w"
static void create_sashgc(Widget self)
#else
#line 379 "Slider4.w"
static void create_sashgc(self)Widget self;
#endif
#line 380 "Slider4.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashPixmap != None) {
        mask = GCTile | GCFillStyle;
        values.tile = ((XfwfSlider4Widget)self)->xfwfSlider4.sashPixmap;
        values.fill_style = FillTiled;
    } else {
        mask = GCForeground;
        values.foreground = ((XfwfSlider4Widget)self)->xfwfSlider4.sashColor;
    }
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashgc = XtGetGC(self, mask, &values);
}
#line 398 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 398 "Slider4.w"
static void create_sashlightgc(Widget self)
#else
#line 398 "Slider4.w"
static void create_sashlightgc(self)Widget self;
#endif
#line 399 "Slider4.w"
{
    XtGCMask mask;
    XGCValues values;

    /* fprintf(stderr, "topShadowStipple = %ld\n", $topShadowStipple); */
    switch (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme) {
    case XfwfColor:
	mask = GCForeground;
	values.foreground = ((XfwfSlider4Widget)self)->xfwfFrame.topShadowColor;
	break;
    case XfwfStipple:
	if (DefaultDepthOfScreen(XtScreen(self)) > 4) {
            mask = GCForeground | GCFillStyle | GCStipple;
            values.foreground = WhitePixelOfScreen(XtScreen(self));
            values.fill_style = FillStippled;
            values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.topShadowStipple;
        } else {
            mask = GCFillStyle | GCStipple | GCForeground | GCBackground;
            values.fill_style = FillOpaqueStippled;
            values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.topShadowStipple;
            values.foreground = BlackPixelOfScreen(XtScreen(self));
            values.background = WhitePixelOfScreen(XtScreen(self));
        }
	break;
    case XfwfAuto:
	if (DefaultDepthOfScreen(XtScreen(self)) > 4
	    && ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfCommon_class.lighter_color(self, ((XfwfSlider4Widget)self)->xfwfCommon.background, &values.foreground)) {
	    mask = GCForeground;
	} else {
	    mask = GCFillStyle | GCBackground | GCForeground | GCStipple;
	    values.fill_style = FillOpaqueStippled;
	    values.background = WhitePixelOfScreen(XtScreen(self));
	    values.foreground = BlackPixelOfScreen(XtScreen(self));
	    values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.lightstipple;
	}
	break;
    }
    /* fprintf(stderr, "values.stipple = %ld\n", values.stipple); */
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc = XtGetGC(self, mask, &values);
}
#line 442 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 442 "Slider4.w"
static void create_sashdarkgc(Widget self)
#else
#line 442 "Slider4.w"
static void create_sashdarkgc(self)Widget self;
#endif
#line 443 "Slider4.w"
{
    XtGCMask mask;
    XGCValues values;

    switch (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme) {
    case XfwfColor:
	mask = GCForeground;
	values.foreground = ((XfwfSlider4Widget)self)->xfwfFrame.bottomShadowColor;
	break;
    case XfwfStipple:
	if (DefaultDepthOfScreen(XtScreen(self)) > 4) {
            mask = GCForeground | GCFillStyle | GCStipple;
            values.foreground = BlackPixelOfScreen(XtScreen(self));
            values.fill_style = FillStippled;
            values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.topShadowStipple;
        } else {
            mask = GCFillStyle | GCStipple | GCForeground | GCBackground;
            values.fill_style = FillOpaqueStippled;
            values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.bottomShadowStipple;
            values.foreground = BlackPixelOfScreen(XtScreen(self));
            values.background = WhitePixelOfScreen(XtScreen(self));
        }
	break;
    case XfwfAuto:
	if (DefaultDepthOfScreen(XtScreen(self)) > 4
	    && ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfCommon_class.darker_color(self, ((XfwfSlider4Widget)self)->xfwfCommon.background, &values.foreground)) {
	    mask = GCForeground;
	} else {
	    mask = GCFillStyle | GCBackground | GCForeground | GCStipple;
	    values.fill_style = FillOpaqueStippled;
	    values.background = WhitePixelOfScreen(XtScreen(self));
	    values.foreground = BlackPixelOfScreen(XtScreen(self));
	    values.stipple = ((XfwfSlider4Widget)self)->xfwfFrame.darkstipple;
	}
	break;
    }
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc = XtGetGC(self, mask, &values);
}

static XtResource resources[] = {
#line 29 "Slider4.w"
{XtNsashColor,XtCSashColor,XtRColor,sizeof(((XfwfSlider4Rec*)NULL)->xfwfSlider4.sashColor),XtOffsetOf(XfwfSlider4Rec,xfwfSlider4.sashColor),XtRString,(XtPointer)XtDefaultBackground },
#line 34 "Slider4.w"
{XtNsashPixmap,XtCSashPixmap,XtRPixmap,sizeof(((XfwfSlider4Rec*)NULL)->xfwfSlider4.sashPixmap),XtOffsetOf(XfwfSlider4Rec,xfwfSlider4.sashPixmap),XtRImmediate,(XtPointer)NULL },
#line 41 "Slider4.w"
{XtNsashFrameType,XtCSashFrameType,XtRFrameType,sizeof(((XfwfSlider4Rec*)NULL)->xfwfSlider4.sashFrameType),XtOffsetOf(XfwfSlider4Rec,xfwfSlider4.sashFrameType),XtRImmediate,(XtPointer)XfwfRaised },
#line 45 "Slider4.w"
{XtNsashFrameWidth,XtCSashFrameWidth,XtRDimension,sizeof(((XfwfSlider4Rec*)NULL)->xfwfSlider4.sashFrameWidth),XtOffsetOf(XfwfSlider4Rec,xfwfSlider4.sashFrameWidth),XtRImmediate,(XtPointer)2 },
};

XfwfSlider4ClassRec xfwfSlider4ClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfSlider2ClassRec,
/* class_name   	*/  "XfwfSlider4",
/* widget_size  	*/  sizeof(XfwfSlider4Rec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  actionsList,
/* num_actions  	*/  3,
/* resources    	*/  resources,
/* num_resources 	*/  4,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple |XtExposeGraphicsExpose ,
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
/* tm_table      	*/  defaultTranslations,
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
XtInherit_set_label,
},
{ /* XfwfSlider2_class part */
XtInherit_compute_thumb,
XtInherit_move_thumb,
XtInherit_compute_info,
XtInherit_scroll_response,
},
{ /* XfwfSlider4_class part */
 /* dummy */  0
},
};
WidgetClass xfwfSlider4WidgetClass = (WidgetClass) &xfwfSlider4ClassRec;
/*ARGSUSED*/
#line 83 "Slider4.w"
static void start(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    Dimension w, h;
    Position x, y;
    float b;
    Boolean outside = False;
    XfwfScrollInfo info;

    if (event->type != ButtonPress && event->type != ButtonRelease
        && event->type != MotionNotify)
        XtError("The start action must be bound to a mouse event");

    ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.compute_thumb(self, &x, &y, &w, &h);

    if (event->xbutton.x < x) {			/* Left of thumb */
	info.reason = XfwfSPageLeft;
	info.flags = XFWF_HPOS;			/* Suggest a value: */
	info.hpos = max(0.0, ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_x - ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_wd);
	outside = True;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }
    if (event->xbutton.x >= x + w) {		/* Right of thumb */
	info.reason = XfwfSPageRight;
	info.flags = XFWF_HPOS;			/* Suggest a value: */
	info.hpos = min(1.0, ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_x + ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_wd);
	outside = True;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }
    if (event->xbutton.y < y) {			/* Above thumb */
	info.reason = XfwfSPageUp;
	info.flags = XFWF_VPOS;			/* Suggest a value: */
	info.vpos = max(0.0, ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_y - ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_ht);
	outside = True;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }
    if (event->xbutton.y >= y + h) {		/* Below thumb */
	info.reason = XfwfSPageDown;
	info.flags = XFWF_VPOS;			/* Suggest a value: */
	info.vpos = min(1.0, ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_y + ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_ht);
	outside = True;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }

    if (! outside) {				/* Mouse inside the thumb */
        b = y + x + h + w - 2*((XfwfSlider4Widget)self)->xfwfSlider2.thumbFrameWidth
	    - (min(h, w) - 2 * ((XfwfSlider4Widget)self)->xfwfSlider2.thumbFrameWidth)/2;
        if (event->xbutton.y >= -event->xbutton.x + b) {
            ((XfwfSlider4Widget)self)->xfwfSlider4.resize_in_progress = True;		/* Inside the triangle */
            ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_x = w - event->xbutton.x;
            ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_y = h - event->xbutton.y;
        } else {
            ((XfwfSlider4Widget)self)->xfwfSlider2.drag_in_progress = True;		/* Outside the triangle */
            ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_x = x - event->xbutton.x;
            ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_y = y - event->xbutton.y;
        }
    }
}

/*ARGSUSED*/
#line 148 "Slider4.w"
static void finish(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    XfwfScrollInfo info;

    if (((XfwfSlider4Widget)self)->xfwfSlider2.drag_in_progress) {
        ((XfwfSlider4Widget)self)->xfwfSlider2.drag_in_progress = False;
	info.reason = XfwfSMove;
	info.flags = XFWF_VPOS | XFWF_HPOS;
	info.hpos = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_x;
	info.vpos = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_y;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    } else if (((XfwfSlider4Widget)self)->xfwfSlider4.resize_in_progress) {
        ((XfwfSlider4Widget)self)->xfwfSlider4.resize_in_progress = False;
	info.reason = XfwfSZoom;
	info.flags = XFWF_VSIZE | XFWF_HSIZE;
	info.vsize = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_ht;
	info.hsize = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_wd;
	XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }
}

/*ARGSUSED*/
#line 175 "Slider4.w"
static void drag(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    Dimension oldw, oldh, neww, newh, fw, fh, wd, ht;
    Position newx, newy, x, y, oldx, oldy, fx, fy;
    float dum1, dum2;
    XfwfScrollInfo info;
    XEvent pseudoevent;
    XRectangle rect;
    Region reg;

    if (event->type != ButtonPress && event->type != ButtonRelease
        && event->type != MotionNotify)
        XtError("The drag action must be bound to a mouse event");
    if (((XfwfSlider4Widget)self)->xfwfSlider2.drag_in_progress) {
        ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.compute_thumb(self, &oldx, &oldy, &wd, &ht);
        newx = event->xbutton.x + ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_x;
        newy = event->xbutton.y + ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_y;
        ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.compute_info(self, &newx, &newy,&wd,&ht,&((XfwfSlider4Widget)self)->xfwfSlider2.thumb_x,&((XfwfSlider4Widget)self)->xfwfSlider2.thumb_y,&dum1,&dum2);
        ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.move_thumb(self, oldx, oldy, wd, ht, newx, newy);
	info.reason = XfwfSDrag;
	info.flags = XFWF_VPOS | XFWF_HPOS;
        info.hpos = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_x;
        info.vpos = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_y;
        XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    } else if (((XfwfSlider4Widget)self)->xfwfSlider4.resize_in_progress) {
        ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.compute_thumb(self, &x, &y, &oldw, &oldh);
        neww = event->xbutton.x + ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_x;
        newh = event->xbutton.y + ((XfwfSlider4Widget)self)->xfwfSlider2.m_delta_y;
        ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfSlider2_class.compute_info(self, &x, &y,&neww,&newh,&dum1,&dum2,&((XfwfSlider4Widget)self)->xfwfSlider2.thumb_wd,&((XfwfSlider4Widget)self)->xfwfSlider2.thumb_ht);
        rect.x = pseudoevent.xexpose.x = x;
        rect.y = pseudoevent.xexpose.y = y;
	rect.height = pseudoevent.xexpose.height = max(oldh, newh);
	rect.width = pseudoevent.xexpose.width = max(oldw, neww);
	XClearArea(XtDisplay(self), XtWindow(self), x, y, rect.width,
		   rect.height, False);
        reg = XCreateRegion();
        XUnionRectWithRegion(&rect, reg, reg);
        ((XfwfSlider4WidgetClass)self->core.widget_class)->core_class.expose(self, &pseudoevent, reg);
        XDestroyRegion(reg);
	info.reason= XfwfSStretch;
	info.flags = XFWF_VSIZE | XFWF_HSIZE;
        info.hsize = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_wd;
        info.vsize = ((XfwfSlider4Widget)self)->xfwfSlider2.thumb_ht;
        XtCallCallbackList(self, ((XfwfSlider4Widget)self)->xfwfSlider2.scrollCallback, &info);
    }
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfSlider4WidgetClass c = (XfwfSlider4WidgetClass) class;
  XfwfSlider4WidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfSlider4WidgetClass) return;
  super = (XfwfSlider4WidgetClass)class->core_class.superclass;
}
#line 227 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 227 "Slider4.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 227 "Slider4.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 228 "Slider4.w"
{
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashgc = NULL; create_sashgc(self);
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc = NULL; create_sashlightgc(self);
    ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc = NULL; create_sashdarkgc(self);
    ((XfwfSlider4Widget)self)->xfwfSlider4.resize_in_progress = False;
}
#line 241 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 241 "Slider4.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 241 "Slider4.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 242 "Slider4.w"
{
    Position x, y;
    Dimension w, h, b;
    XPoint p[9];

    if (! XtIsRealized(self)) return;
    xfwfSlider2ClassRec.core_class.expose(self, event, region);
    ((XfwfSlider4WidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
    b = min(h, w)/2;
    p[0].x = x + w - b;
    p[0].y = y + h;
    p[1].x = x + w;
    p[1].y = p[0].y;
    p[2].x = p[1].x;
    p[2].y = y + h - b;
    XFillPolygon(XtDisplay(self), XtWindow(self), ((XfwfSlider4Widget)self)->xfwfSlider4.sashgc, p, 3, Convex,
		 CoordModeOrigin);
    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfRaised || ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfSunken) {
	p[0].x = x + w - b + 2 * ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[0].y = y + h - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[1].x = x + w - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[1].y = p[0].y;
	p[2].x = p[1].x;
	p[2].y = y + h - b + 2 * ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[3].x = x + w;
        p[3].y = y + h - b;
        p[4].x = p[3].x;
        p[4].y = y + h;
        p[5].x = x + w - b;
        p[5].y = p[4].y;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfRaised ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc,
		     p, 6, Nonconvex, CoordModeOrigin);
	p[1].x = p[2].x;
	p[1].y = p[2].y;
	p[2].x = p[3].x;
	p[2].y = p[3].y;
	p[3].x = p[5].x;
	p[3].y = p[5].y;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfSunken ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc,
		     p, 4, Nonconvex, CoordModeOrigin);
    } else {
	p[0].x = x + w - b + 2 * ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[0].y = y + h - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[1].x = x + w - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
	p[1].y = p[0].y;
	p[2].x = p[1].x;
	p[2].y = y + h - b + 2 * ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[3].x = x + w - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth/2;
        p[3].y = y + h - b + ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[4].x = p[3].x;
        p[4].y = y + h - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth/2;
        p[5].x = x + w - b + ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[5].y = p[4].y;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfChiseled ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc,
		     p, 6, Nonconvex, CoordModeOrigin);
        p[2].x = x + w;
        p[2].y = y + h - b;
        p[1].x = p[2].x;
        p[1].y = y + h;
        p[0].x = x + w - b;
        p[0].y = p[1].y;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfChiseled ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc,
		     p, 6, Nonconvex, CoordModeOrigin);
        p[0].x = x + w - b + 2 * ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[0].y = y + h - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[1].x = x + w - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[1].y = p[0].y;
        p[2].x = x + w - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth/2;
        p[2].y = y + h - b + ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[3].x = x + w - b + ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth;
        p[3].y = y + h - ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth/2;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfChiseled ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc,
		     p, 4, Convex, CoordModeOrigin);
        p[0].x = x + w - b;
        p[0].y = y + h;
        p[1].x = x + w;
        p[1].y = y + h - b;
        XFillPolygon(XtDisplay(self), XtWindow(self),
		     ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfChiseled ? ((XfwfSlider4Widget)self)->xfwfSlider4.sashdarkgc : ((XfwfSlider4Widget)self)->xfwfSlider4.sashlightgc,
		     p, 4, Convex, CoordModeOrigin);
    }
}
#line 334 "Slider4.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 334 "Slider4.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 334 "Slider4.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 335 "Slider4.w"
{
    Boolean need_redisplay = False;

    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashPixmap != ((XfwfSlider4Widget)old)->xfwfSlider4.sashPixmap) {
        XFreePixmap(XtDisplay(self), ((XfwfSlider4Widget)old)->xfwfSlider4.sashPixmap);
        create_sashgc(self);
        need_redisplay = True;
    } else if (((XfwfSlider4Widget)self)->xfwfSlider4.sashColor != ((XfwfSlider4Widget)old)->xfwfSlider4.sashColor) {
        XFreePixmap(XtDisplay(self), ((XfwfSlider4Widget)self)->xfwfSlider4.sashPixmap);
        ((XfwfSlider4Widget)self)->xfwfSlider4.sashPixmap = None;
        create_sashgc(self);
        need_redisplay = True;
    }
    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType != ((XfwfSlider4Widget)old)->xfwfSlider4.sashFrameType)
        need_redisplay = True;
    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfChiseled || ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameType == XfwfLedged)
        ((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth = 2 * (((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth/2);
    if (((XfwfSlider4Widget)self)->xfwfSlider4.sashFrameWidth != ((XfwfSlider4Widget)old)->xfwfSlider4.sashFrameWidth)
        need_redisplay = True;
    if (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme != ((XfwfSlider4Widget)old)->xfwfFrame.shadowScheme
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfAuto && ((XfwfSlider4Widget)self)->xfwfSlider4.sashColor != ((XfwfSlider4Widget)old)->xfwfSlider4.sashColor)
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfStipple
	    && ((XfwfSlider4Widget)self)->xfwfFrame.topShadowStipple != ((XfwfSlider4Widget)old)->xfwfFrame.topShadowStipple)
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfColor
	    && ((XfwfSlider4Widget)self)->xfwfFrame.topShadowColor != ((XfwfSlider4Widget)old)->xfwfFrame.topShadowColor)) {
        create_sashlightgc(self);
        need_redisplay = True;
    }
    if (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme != ((XfwfSlider4Widget)old)->xfwfFrame.shadowScheme
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfAuto && ((XfwfSlider4Widget)self)->xfwfSlider4.sashColor != ((XfwfSlider4Widget)old)->xfwfSlider4.sashColor)
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfStipple
	    && ((XfwfSlider4Widget)self)->xfwfFrame.bottomShadowStipple != ((XfwfSlider4Widget)old)->xfwfFrame.bottomShadowStipple)
        || (((XfwfSlider4Widget)self)->xfwfFrame.shadowScheme == XfwfColor
	    && ((XfwfSlider4Widget)self)->xfwfFrame.bottomShadowColor != ((XfwfSlider4Widget)old)->xfwfFrame.bottomShadowColor)) {
        create_sashdarkgc(self);
        need_redisplay = True;
    }
    return need_redisplay = True;
}
