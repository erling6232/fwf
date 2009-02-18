/* Generated by wbuild from "Enforcer.w"
** (generator version $Revision$ of $Date$)
*/
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <Xfwf/EnforcerP.h>
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 20 "Enforcer.w"
static void resize(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 39 "Enforcer.w"
static void change_managed(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 55 "Enforcer.w"
static XtGeometryResult  geometry_manager(
#if NeedFunctionPrototypes
Widget ,XtWidgetGeometry *,XtWidgetGeometry *
#endif
);

XfwfEnforcerClassRec xfwfEnforcerClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfBoardClassRec,
/* class_name   	*/  "XfwfEnforcer",
/* widget_size  	*/  sizeof(XfwfEnforcerRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  NULL,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  NULL,
/* num_actions  	*/  0,
/* resources    	*/  NULL,
/* num_resources 	*/  0,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple ,
/* compress_enterleave 	*/  True ,
/* visible_interest 	*/  TRUE ,
/* destroy      	*/  NULL,
/* resize       	*/  resize,
/* expose       	*/  XtInheritExpose,
/* set_values   	*/  NULL,
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
geometry_manager,
change_managed,
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
{ /* XfwfEnforcer_class part */
 /* dummy */  0
},
};
WidgetClass xfwfEnforcerWidgetClass = (WidgetClass) &xfwfEnforcerClassRec;
static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfEnforcerWidgetClass c = (XfwfEnforcerWidgetClass) class;
  XfwfEnforcerWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfEnforcerWidgetClass) return;
  super = (XfwfEnforcerWidgetClass)class->core_class.superclass;
}
#line 20 "Enforcer.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 20 "Enforcer.w"
static void resize(Widget self)
#else
#line 20 "Enforcer.w"
static void resize(self)Widget self;
#endif
#line 21 "Enforcer.w"
{
    Position x, y;
    Dimension w, h;
    Widget child;

    if (((XfwfEnforcerWidget)self)->composite.num_children == 0) return;
    ((XfwfEnforcerWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
    child = ((XfwfEnforcerWidget)self)->composite.children[0];
    w -= 2 * ((XfwfEnforcerWidget)child)->core.border_width;
    h -= 2 * ((XfwfEnforcerWidget)child)->core.border_width;
    XtConfigureWidget(child, x, y, w, h, ((XfwfEnforcerWidget)child)->core.border_width);
}
#line 39 "Enforcer.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 39 "Enforcer.w"
static void change_managed(Widget self)
#else
#line 39 "Enforcer.w"
static void change_managed(self)Widget self;
#endif
#line 40 "Enforcer.w"
{
    Position x, y;
    Dimension w, h;
    Widget child;

    if (((XfwfEnforcerWidget)self)->composite.num_children == 0) return;
    ((XfwfEnforcerWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
    child = ((XfwfEnforcerWidget)self)->composite.children[0];
    w -= 2 * ((XfwfEnforcerWidget)child)->core.border_width;
    h -= 2 * ((XfwfEnforcerWidget)child)->core.border_width;
    XtConfigureWidget(child, x, y, w, h, ((XfwfEnforcerWidget)child)->core.border_width);
}
#line 55 "Enforcer.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 167 "Enforcer.w"
static XtGeometryResult  geometry_manager(Widget  child,XtWidgetGeometry * request,XtWidgetGeometry * reply)
#else
#line 167 "Enforcer.w"
static XtGeometryResult  geometry_manager(child,request,reply)Widget  child;XtWidgetGeometry * request;XtWidgetGeometry * reply;
#endif
{ Widget self = XtParent(child); {
    return XtGeometryNo;
}
}