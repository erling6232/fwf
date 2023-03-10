/* Generated by wbuild from "HScrollb.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <Xfwf/HScrollbP.h>

static char defaultTranslations[] = "\
Ctrl<Key>Left: Scroll(pageLeft) \n\
Ctrl<Key>Right: Scroll(pageRight) \n\
<Key>Left: Scroll(left) \n\
<Key>Right: Scroll(right) \n\
Shift<Key>Home: Scroll(rightSide) \n\
<Key>Home: Scroll(leftSide) \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);

static XtResource resources[] = {
#line 19 "HScrollb.w"
{XtNvertical,XtCVertical,XtRBoolean,sizeof(((XfwfHScrollbarRec*)NULL)->xfwfScrollbar.vertical),XtOffsetOf(XfwfHScrollbarRec,xfwfScrollbar.vertical),XtRImmediate,(XtPointer)False },
};

XfwfHScrollbarClassRec xfwfHScrollbarClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfScrollbarClassRec,
/* class_name   	*/  "XfwfHScrollbar",
/* widget_size  	*/  sizeof(XfwfHScrollbarRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  NULL,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  NULL,
/* num_actions  	*/  0,
/* resources    	*/  resources,
/* num_resources 	*/  1,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple ,
/* compress_enterleave 	*/  True ,
/* visible_interest 	*/  TRUE ,
/* destroy      	*/  NULL,
/* resize       	*/  XtInheritResize,
/* expose       	*/  XtInheritExpose,
/* set_values   	*/  NULL,
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
{ /* XfwfScrollbar_class part */
XtInherit_scroll_response,
},
{ /* XfwfHScrollbar_class part */
 /* dummy */  0
},
};
WidgetClass xfwfHScrollbarWidgetClass = (WidgetClass) &xfwfHScrollbarClassRec;
static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfHScrollbarWidgetClass c = (XfwfHScrollbarWidgetClass) class;
  XfwfHScrollbarWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfHScrollbarWidgetClass) return;
  super = (XfwfHScrollbarWidgetClass)class->core_class.superclass;
}
