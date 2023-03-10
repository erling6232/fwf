/* Generated by wbuild from "RadioGrp.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 84 "RadioGrp.w"
#include <Xfwf/Toggle.h>
#include <Xfwf/RadioGrpP.h>
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 39 "RadioGrp.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 49 "RadioGrp.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 65 "RadioGrp.w"
static void create_toggles(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 65 "RadioGrp.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 65 "RadioGrp.w"
static void create_toggles(Widget self)
#else
#line 65 "RadioGrp.w"
static void create_toggles(self)Widget self;
#endif
#line 66 "RadioGrp.w"
{
    Cardinal i;
    StringArray s;

    for (i = 0; i < ((XfwfRadioGroupWidget)self)->composite.num_children; i++) 
	XtDestroyWidget(((XfwfRadioGroupWidget)self)->composite.children[i]);

    if (((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels == NULL) return;

    for (s = ((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels, i = 0; s[i] != NULL; i++) {
	(void) XtVaCreateManagedWidget
	    (s[i], xfwfToggleWidgetClass, self, XtNlabel, s[i], XtNshrinkToFit,
	     True, XtNborderWidth, 0, XtNframeWidth, 0, NULL);
    }
}

static XtResource resources[] = {
#line 30 "RadioGrp.w"
{XtNlabels,XtCLabels,XtRStringArray,sizeof(((XfwfRadioGroupRec*)NULL)->xfwfRadioGroup.labels),XtOffsetOf(XfwfRadioGroupRec,xfwfRadioGroup.labels),XtRImmediate,(XtPointer)NULL },
};

XfwfRadioGroupClassRec xfwfRadioGroupClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfGroupClassRec,
/* class_name   	*/  "XfwfRadioGroup",
/* widget_size  	*/  sizeof(XfwfRadioGroupRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
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
{ /* XfwfRowCol_class part */
XtInherit_layout,
},
{ /* XfwfGroup_class part */
 /* dummy */  0
},
{ /* XfwfRadioGroup_class part */
 /* dummy */  0
},
};
WidgetClass xfwfRadioGroupWidgetClass = (WidgetClass) &xfwfRadioGroupClassRec;
static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfRadioGroupWidgetClass c = (XfwfRadioGroupWidgetClass) class;
  XfwfRadioGroupWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfRadioGroupWidgetClass) return;
  super = (XfwfRadioGroupWidgetClass)class->core_class.superclass;
}
#line 39 "RadioGrp.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 39 "RadioGrp.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 39 "RadioGrp.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 40 "RadioGrp.w"
{
    ((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels = newStringArray(((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels);
    create_toggles(self);
}
#line 49 "RadioGrp.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 49 "RadioGrp.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 49 "RadioGrp.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 50 "RadioGrp.w"
{
    if (((XfwfRadioGroupWidget)old)->xfwfRadioGroup.labels != ((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels) {
	freeStringArray(((XfwfRadioGroupWidget)old)->xfwfRadioGroup.labels);
	((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels = newStringArray(((XfwfRadioGroupWidget)self)->xfwfRadioGroup.labels);
	create_toggles(self);
    }
    return False;
}
#line 88 "RadioGrp.w"
