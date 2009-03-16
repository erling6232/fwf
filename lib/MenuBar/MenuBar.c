/* Generated by wbuild from "MenuBar.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 145 "MenuBar.w"
#include <Xfwf/PullDown.h>
#line 146 "MenuBar.w"
#include <X11/Shell.h>
#line 147 "MenuBar.w"
#include <stdio.h>
#include <Xfwf/MenuBarP.h>
#line 116 "MenuBar.w"
static void menu_popdown(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"menu_popdown", menu_popdown},
};

static char defaultTranslations[] = "\
<Btn1Up>: menu_popdown() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 69 "MenuBar.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 84 "MenuBar.w"
static void process_menu(
#if NeedFunctionPrototypes
Widget,Widget ,Cursor 
#endif
);
#line 130 "MenuBar.w"
static void popdown_cb(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 130 "MenuBar.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 130 "MenuBar.w"
static void popdown_cb(Widget  menu,XtPointer  client_data,XtPointer  call_data)
#else
#line 130 "MenuBar.w"
static void popdown_cb(menu,client_data,call_data)Widget  menu;XtPointer  client_data;XtPointer  call_data;
#endif
#line 131 "MenuBar.w"
{
    Widget self = (Widget) client_data;

    XtRemoveCallback(menu, XtNpopdownCallback, popdown_cb, self);
/*
    XtUngrabKey(menu, AnyKey, AnyModifier);
    XtUngrabButton(menu, AnyButton, AnyModifier);
*/
    XtRemoveGrab(self);
    ((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu = NULL;
}

static XtResource resources[] = {
#line 27 "MenuBar.w"
{XtNframeType,XtCFrameType,XtRFrameType,sizeof(((XfwfMenuBarRec*)NULL)->xfwfFrame.frameType),XtOffsetOf(XfwfMenuBarRec,xfwfFrame.frameType),XtRImmediate,(XtPointer)XfwfRaised },
#line 29 "MenuBar.w"
{XtNtraversalOn,XtCTraversalOn,XtRBoolean,sizeof(((XfwfMenuBarRec*)NULL)->xfwfCommon.traversalOn),XtOffsetOf(XfwfMenuBarRec,xfwfCommon.traversalOn),XtRImmediate,(XtPointer)False },
};

XfwfMenuBarClassRec xfwfMenuBarClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfRowsClassRec,
/* class_name   	*/  "XfwfMenuBar",
/* widget_size  	*/  sizeof(XfwfMenuBarRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  actionsList,
/* num_actions  	*/  1,
/* resources    	*/  resources,
/* num_resources 	*/  2,
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
{ /* XfwfRows_class part */
XtInherit_layout,
},
{ /* XfwfMenuBar_class part */
process_menu,
},
};
WidgetClass xfwfMenuBarWidgetClass = (WidgetClass) &xfwfMenuBarClassRec;
/*ARGSUSED*/
#line 116 "MenuBar.w"
static void menu_popdown(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu != NULL) {
	XtPopdown(((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu);
	((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu = NULL;
    }
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfMenuBarWidgetClass c = (XfwfMenuBarWidgetClass) class;
  XfwfMenuBarWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfMenuBarWidgetClass) return;
  super = (XfwfMenuBarWidgetClass)class->core_class.superclass;
  if (c->xfwfMenuBar_class.process_menu == XtInherit_process_menu)
    c->xfwfMenuBar_class.process_menu = super->xfwfMenuBar_class.process_menu;
}
#line 69 "MenuBar.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 69 "MenuBar.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 69 "MenuBar.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 70 "MenuBar.w"
{
    ((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu = NULL;
}
#line 84 "MenuBar.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 84 "MenuBar.w"
static void process_menu(Widget self,Widget  menu,Cursor  cursor)
#else
#line 84 "MenuBar.w"
static void process_menu(self,menu,cursor)Widget self;Widget  menu;Cursor  cursor;
#endif
#line 85 "MenuBar.w"
{
    if (menu == ((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu) return;
    if (((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu) XtPopdown(((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu);
    XtAddGrab(self, True, False);
/*
    XtGrabButton(menu, AnyButton, AnyModifier, True, ButtonPressMask |
		 ButtonReleaseMask | EnterWindowMask | LeaveWindowMask
		 | PointerMotionMask, GrabModeAsync, GrabModeAsync,
		 None, cursor);
    XtGrabKey(menu, AnyKey, AnyModifier, True, GrabModeAsync,
	      GrabModeAsync);
*/
    XtAddCallback(menu, XtNpopdownCallback, popdown_cb, self);
    ((XfwfMenuBarWidget)self)->xfwfMenuBar.current_menu = menu;
    XtPopup(menu, XtGrabNonexclusive);
}
#line 50 "MenuBar.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 50 "MenuBar.w"
Boolean  XfwfCallProcessMenu(Widget self,Widget  menu,Cursor  cursor)
#else
#line 50 "MenuBar.w"
Boolean  XfwfCallProcessMenu(self,menu,cursor)Widget self;Widget  menu;Cursor  cursor;
#endif
#line 51 "MenuBar.w"
{
    if (XtIsSubclass(self, xfwfMenuBarWidgetClass) && ((XfwfMenuBarWidgetClass)self->core.widget_class)->xfwfMenuBar_class.process_menu) {
	((XfwfMenuBarWidgetClass)self->core.widget_class)->xfwfMenuBar_class.process_menu(self, menu, cursor);
	return True;
    } else
	return False;
}
