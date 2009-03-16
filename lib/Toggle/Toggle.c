/* Generated by wbuild from "Toggle.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 250 "Toggle.w"
#include <Xfwf/Converters.h>
#include <Xfwf/ToggleP.h>
#line 64 "Toggle.w"
static void toggle(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 75 "Toggle.w"
static void switch_on(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 88 "Toggle.w"
static void switch_off(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"toggle", toggle},
{"switch_on", switch_on},
{"switch_off", switch_off},
};

static char defaultTranslations[] = "\
<Btn1Down>: set_shadow(sunken) \n\
<Btn1Up>: toggle() set_shadow() \n\
<Key>Return: toggle() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 120 "Toggle.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 141 "Toggle.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 178 "Toggle.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 208 "Toggle.w"
static void create_on_gc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 228 "Toggle.w"
static void create_off_gc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 208 "Toggle.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 208 "Toggle.w"
static void create_on_gc(Widget self)
#else
#line 208 "Toggle.w"
static void create_on_gc(self)Widget self;
#endif
#line 209 "Toggle.w"
{
    XtGCMask mask = GCFillStyle;
    XGCValues values;

    if (((XfwfToggleWidget)self)->xfwfToggle.on_gc != NULL) XtReleaseGC(self, ((XfwfToggleWidget)self)->xfwfToggle.on_gc);
    if (((XfwfToggleWidget)self)->xfwfToggle.onIcon && ((XfwfToggleWidget)self)->xfwfToggle.onIcon->pixmap != None) {
	values.tile = ((XfwfToggleWidget)self)->xfwfToggle.onIcon->pixmap;
	mask |= GCTile;
    }
    if (((XfwfToggleWidget)self)->xfwfToggle.onIcon && ((XfwfToggleWidget)self)->xfwfToggle.onIcon->mask != None) {
	values.clip_mask = ((XfwfToggleWidget)self)->xfwfToggle.onIcon->mask;
	mask |= GCClipMask;
    }
    values.fill_style = FillTiled;
    ((XfwfToggleWidget)self)->xfwfToggle.on_gc = XtGetGC(self, mask, &values);
}
#line 228 "Toggle.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 228 "Toggle.w"
static void create_off_gc(Widget self)
#else
#line 228 "Toggle.w"
static void create_off_gc(self)Widget self;
#endif
#line 229 "Toggle.w"
{
    XtGCMask mask = GCFillStyle;
    XGCValues values;

    if (((XfwfToggleWidget)self)->xfwfToggle.off_gc != NULL) XtReleaseGC(self, ((XfwfToggleWidget)self)->xfwfToggle.off_gc);
    if (((XfwfToggleWidget)self)->xfwfToggle.offIcon && ((XfwfToggleWidget)self)->xfwfToggle.offIcon->pixmap != None) {
	values.tile = ((XfwfToggleWidget)self)->xfwfToggle.offIcon->pixmap;
	mask |= GCTile;
    }
    if (((XfwfToggleWidget)self)->xfwfToggle.offIcon && ((XfwfToggleWidget)self)->xfwfToggle.offIcon->mask != None) {
	values.clip_mask = ((XfwfToggleWidget)self)->xfwfToggle.offIcon->mask;
	mask |= GCClipMask;
    }
    values.fill_style = FillTiled;
    ((XfwfToggleWidget)self)->xfwfToggle.off_gc = XtGetGC(self, mask, &values);
}

static XtResource resources[] = {
#line 22 "Toggle.w"
{XtNonCallback,XtCOnCallback,XtRCallback,sizeof(((XfwfToggleRec*)NULL)->xfwfToggle.onCallback),XtOffsetOf(XfwfToggleRec,xfwfToggle.onCallback),XtRImmediate,(XtPointer)NULL },
#line 28 "Toggle.w"
{XtNoffCallback,XtCOffCallback,XtRCallback,sizeof(((XfwfToggleRec*)NULL)->xfwfToggle.offCallback),XtOffsetOf(XfwfToggleRec,xfwfToggle.offCallback),XtRImmediate,(XtPointer)NULL },
#line 33 "Toggle.w"
{XtNon,XtCOn,XtRBoolean,sizeof(((XfwfToggleRec*)NULL)->xfwfToggle.on),XtOffsetOf(XfwfToggleRec,xfwfToggle.on),XtRImmediate,(XtPointer)False },
#line 40 "Toggle.w"
{XtNonIcon,XtCOnIcon,XtRIcon,sizeof(((XfwfToggleRec*)NULL)->xfwfToggle.onIcon),XtOffsetOf(XfwfToggleRec,xfwfToggle.onIcon),XtRString,(XtPointer)"filledsquare"},
#line 45 "Toggle.w"
{XtNoffIcon,XtCOffIcon,XtRIcon,sizeof(((XfwfToggleRec*)NULL)->xfwfToggle.offIcon),XtOffsetOf(XfwfToggleRec,xfwfToggle.offIcon),XtRString,(XtPointer)"emptysquare"},
};

XfwfToggleClassRec xfwfToggleClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfButtonClassRec,
/* class_name   	*/  "XfwfToggle",
/* widget_size  	*/  sizeof(XfwfToggleRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  actionsList,
/* num_actions  	*/  3,
/* resources    	*/  resources,
/* num_resources 	*/  5,
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
{ /* XfwfButton_class part */
 /* dummy */  0
},
{ /* XfwfToggle_class part */
 /* dummy */  0
},
};
WidgetClass xfwfToggleWidgetClass = (WidgetClass) &xfwfToggleClassRec;
/*ARGSUSED*/
#line 64 "Toggle.w"
static void toggle(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    XtVaSetValues(self, "on", !((XfwfToggleWidget)self)->xfwfToggle.on, NULL);
    XtCallCallbackList(self, ((XfwfToggleWidget)self)->xfwfToggle.on ? ((XfwfToggleWidget)self)->xfwfToggle.onCallback : ((XfwfToggleWidget)self)->xfwfToggle.offCallback, event);
}

/*ARGSUSED*/
#line 75 "Toggle.w"
static void switch_on(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (! ((XfwfToggleWidget)self)->xfwfToggle.on) {
        XtVaSetValues(self, "on", True, NULL);
        XtCallCallbackList(self, ((XfwfToggleWidget)self)->xfwfToggle.onCallback, event);
    }
}

/*ARGSUSED*/
#line 88 "Toggle.w"
static void switch_off(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (((XfwfToggleWidget)self)->xfwfToggle.on) {
        XtVaSetValues(self, "on", False, NULL);
        XtCallCallbackList(self, ((XfwfToggleWidget)self)->xfwfToggle.offCallback, event);
    }
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfToggleWidgetClass c = (XfwfToggleWidgetClass) class;
  XfwfToggleWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfToggleWidgetClass) return;
  super = (XfwfToggleWidgetClass)class->core_class.superclass;
}
#line 120 "Toggle.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 120 "Toggle.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 120 "Toggle.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 121 "Toggle.w"
{
    Dimension w1, w2, w;

    ((XfwfToggleWidget)self)->xfwfToggle.on_gc = NULL;
    ((XfwfToggleWidget)self)->xfwfToggle.off_gc = NULL;
    create_on_gc(self);
    create_off_gc(self);

    w1 = ((XfwfToggleWidget)self)->xfwfToggle.onIcon ? ((XfwfToggleWidget)self)->xfwfToggle.onIcon->attributes.width : 0;
    w2 = ((XfwfToggleWidget)self)->xfwfToggle.offIcon ? ((XfwfToggleWidget)self)->xfwfToggle.offIcon->attributes.width : 0;
    w = max(w1, w2);
    if (w != 0) XtVaSetValues(self, XtNleftMargin, ((XfwfToggleWidget)self)->xfwfLabel.leftMargin + w, NULL);
}
#line 141 "Toggle.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 141 "Toggle.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 141 "Toggle.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 142 "Toggle.w"
{
    Boolean redraw = False, compute_margin = False;
    Dimension w1, w2, w;

    if (((XfwfToggleWidget)self)->xfwfToggle.onIcon != ((XfwfToggleWidget)old)->xfwfToggle.onIcon) {
	create_on_gc(self);
	compute_margin = True;
    }
    if (((XfwfToggleWidget)self)->xfwfToggle.offIcon != ((XfwfToggleWidget)old)->xfwfToggle.offIcon) {
	create_off_gc(self);
	compute_margin = True;
    }
    if (((XfwfToggleWidget)self)->xfwfToggle.on != ((XfwfToggleWidget)old)->xfwfToggle.on) {
        redraw = True;
    }
    if (compute_margin) {
	/* Compute w = old margin between icons and text */
	w1 = ((XfwfToggleWidget)old)->xfwfToggle.onIcon ? ((XfwfToggleWidget)old)->xfwfToggle.onIcon->attributes.width : 0;
	w2 = ((XfwfToggleWidget)old)->xfwfToggle.offIcon ? ((XfwfToggleWidget)old)->xfwfToggle.offIcon->attributes.width : 0;
	w = ((XfwfToggleWidget)old)->xfwfLabel.leftMargin - max(w1, w2);
	/* Compute new left margin w = w + width of icons */
	w1 = ((XfwfToggleWidget)self)->xfwfToggle.onIcon ? ((XfwfToggleWidget)self)->xfwfToggle.onIcon->attributes.width : 0;
	w2 = ((XfwfToggleWidget)self)->xfwfToggle.offIcon ? ((XfwfToggleWidget)self)->xfwfToggle.offIcon->attributes.width : 0;
	w = w + max(w1, w2);
	if (((XfwfToggleWidget)old)->xfwfLabel.leftMargin != w) {
	    XtVaSetValues(self, XtNleftMargin, w, NULL);
	    redraw = False;
	} else
	    redraw = True;
    }
    return redraw;
}
#line 178 "Toggle.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 178 "Toggle.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 178 "Toggle.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 179 "Toggle.w"
{
    Position x, y;
    Dimension w, h;

    if (! XtIsRealized(self)) return;
    xfwfButtonClassRec.core_class.expose(self, event, region);
    ((XfwfToggleWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
    if (((XfwfToggleWidget)self)->xfwfToggle.on && ((XfwfToggleWidget)self)->xfwfToggle.onIcon) {
	y = y + (h - ((XfwfToggleWidget)self)->xfwfToggle.onIcon->attributes.height)/2;
	XSetTSOrigin(XtDisplay(self), ((XfwfToggleWidget)self)->xfwfToggle.on_gc, x, y);
	XSetClipOrigin(XtDisplay(self), ((XfwfToggleWidget)self)->xfwfToggle.on_gc, x, y);
	XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfToggleWidget)self)->xfwfToggle.on_gc, x, y,
		       ((XfwfToggleWidget)self)->xfwfToggle.onIcon->attributes.width,
		       ((XfwfToggleWidget)self)->xfwfToggle.onIcon->attributes.height);
    } else if (((XfwfToggleWidget)self)->xfwfToggle.offIcon) {
	y = y + (h - ((XfwfToggleWidget)self)->xfwfToggle.offIcon->attributes.height)/2;
	XSetTSOrigin(XtDisplay(self), ((XfwfToggleWidget)self)->xfwfToggle.off_gc, x, y);
	XSetClipOrigin(XtDisplay(self), ((XfwfToggleWidget)self)->xfwfToggle.off_gc, x, y);
	XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfToggleWidget)self)->xfwfToggle.off_gc, x, y,
		       ((XfwfToggleWidget)self)->xfwfToggle.offIcon->attributes.width,
		       ((XfwfToggleWidget)self)->xfwfToggle.offIcon->attributes.height);
    }
}
