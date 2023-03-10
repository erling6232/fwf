/* Generated by wbuild from "OptButton.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 82 "OptButton.w"
#include <stdio.h>
#line 83 "OptButton.w"
#include <Xfwf/TextMenu.h>
#include <Xfwf/OptButtonP.h>

static char defaultTranslations[] = "\
<Btn1Down>: prepare() open_menu() \n\
Button1<Enter>: prepare() open_menu() \n\
<Key>Return: prepare() open_menu() \n\
<Btn1Up>: popdown_maybe() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 36 "OptButton.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 45 "OptButton.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 69 "OptButton.w"
static void set_label_cb(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 69 "OptButton.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 69 "OptButton.w"
static void set_label_cb(Widget  menu,XtPointer  client_data,XtPointer  call_data)
#else
#line 69 "OptButton.w"
static void set_label_cb(menu,client_data,call_data)Widget  menu;XtPointer  client_data;XtPointer  call_data;
#endif
#line 70 "OptButton.w"
{
    Widget self = (Widget) client_data;
    XfwfTextMenuData *data = (XfwfTextMenuData *) call_data;

    if (((XfwfOptionButtonWidget)self)->xfwfLabel.label && strcmp(((XfwfOptionButtonWidget)self)->xfwfLabel.label, data->label) == 0) return;
    XtVaSetValues(self, XtNlabel, data->label, NULL);
}

static XtResource resources[] = {
#line 27 "OptButton.w"
{XtNframeWidth,XtCFrameWidth,XtRDimension,sizeof(((XfwfOptionButtonRec*)NULL)->xfwfFrame.frameWidth),XtOffsetOf(XfwfOptionButtonRec,xfwfFrame.frameWidth),XtRImmediate,(XtPointer)2 },
};

XfwfOptionButtonClassRec xfwfOptionButtonClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfPullDownClassRec,
/* class_name   	*/  "XfwfOptionButton",
/* widget_size  	*/  sizeof(XfwfOptionButtonRec),
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
{ /* XfwfPullDown_class part */
 /* dummy */  0
},
{ /* XfwfOptionButton_class part */
 /* dummy */  0
},
};
WidgetClass xfwfOptionButtonWidgetClass = (WidgetClass) &xfwfOptionButtonClassRec;
static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfOptionButtonWidgetClass c = (XfwfOptionButtonWidgetClass) class;
  XfwfOptionButtonWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfOptionButtonWidgetClass) return;
  super = (XfwfOptionButtonWidgetClass)class->core_class.superclass;
}
#line 36 "OptButton.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 36 "OptButton.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 36 "OptButton.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 37 "OptButton.w"
{
    if (((XfwfOptionButtonWidget)self)->xfwfPullDown.own_popup)
	XtAddCallback(((XfwfOptionButtonWidget)self)->xfwfPullDown.popup, XtNactivate, set_label_cb, self);
}
#line 45 "OptButton.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 45 "OptButton.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 45 "OptButton.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 46 "OptButton.w"
{
    if (((XfwfOptionButtonWidget)old)->xfwfPullDown.popup != ((XfwfOptionButtonWidget)self)->xfwfPullDown.popup && ((XfwfOptionButtonWidget)self)->xfwfPullDown.own_popup)
	XtAddCallback(((XfwfOptionButtonWidget)self)->xfwfPullDown.popup, XtNactivate, set_label_cb, self);
    return False;
}
