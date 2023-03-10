/* Generated by wbuild from "PieMenu.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 512 "PieMenu.w"
#include <stdio.h>
#line 513 "PieMenu.w"
#include <ctype.h>
#line 514 "PieMenu.w"
#include <string.h>
#line 515 "PieMenu.w"
#include <math.h>
#line 516 "PieMenu.w"
#include <X11/Xmu/Converters.h>
#include <Xfwf/PieMenuP.h>
#line 295 "PieMenu.w"
static void select_item(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"select_item", select_item},
};

static char defaultTranslations[] = "\
<BtnUp>: select_item() XtMenuPopdown() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 152 "PieMenu.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 190 "PieMenu.w"
static void realize(
#if NeedFunctionPrototypes
Widget,XtValueMask *,XSetWindowAttributes *
#endif
);
#line 203 "PieMenu.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 263 "PieMenu.w"
static void destroy(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 319 "PieMenu.w"
static void copy_bg(
#if NeedFunctionPrototypes
Widget,int ,XrmValue *
#endif
);
#line 327 "PieMenu.w"
static void copy_fg(
#if NeedFunctionPrototypes
Widget,int ,XrmValue *
#endif
);
#line 335 "PieMenu.w"
static void copy_font(
#if NeedFunctionPrototypes
Widget,int ,XrmValue *
#endif
);
#line 345 "PieMenu.w"
#define emptybm_width 1 


#line 346 "PieMenu.w"
#define emptybm_height 1 


#line 347 "PieMenu.w"
static char  emptybm_bits[] = { 0x00 };
#line 349 "PieMenu.w"
#define stip4_width 2 


#line 350 "PieMenu.w"
#define stip4_height 2 


#line 351 "PieMenu.w"
static char  stip4_bits[] = { 0x01, 0x02 };
#line 359 "PieMenu.w"
static void create_gc(
#if NeedFunctionPrototypes
Widget,GC *,XFontStruct *,Pixel ,Pixel 
#endif
);
#line 376 "PieMenu.w"
static void create_linegc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 390 "PieMenu.w"
static void create_darkgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 413 "PieMenu.w"
static void create_lightgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 437 "PieMenu.w"
static Boolean  trim(
#if NeedFunctionPrototypes
String 
#endif
);
#line 465 "PieMenu.w"
static void parse_menu(
#if NeedFunctionPrototypes
String ,LabelAction *,int *
#endif
);
#line 319 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 319 "PieMenu.w"
static void copy_bg(Widget self,int  offset,XrmValue * value)
#else
#line 319 "PieMenu.w"
static void copy_bg(self,offset,value)Widget self;int  offset;XrmValue * value;
#endif
#line 320 "PieMenu.w"
{
    value->addr = (XtPointer) &((XfwfPieMenuWidget)self)->core.background_pixel;
}
#line 327 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 327 "PieMenu.w"
static void copy_fg(Widget self,int  offset,XrmValue * value)
#else
#line 327 "PieMenu.w"
static void copy_fg(self,offset,value)Widget self;int  offset;XrmValue * value;
#endif
#line 328 "PieMenu.w"
{
    value->addr = (XtPointer) &((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground;
}
#line 335 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 335 "PieMenu.w"
static void copy_font(Widget self,int  offset,XrmValue * value)
#else
#line 335 "PieMenu.w"
static void copy_font(self,offset,value)Widget self;int  offset;XrmValue * value;
#endif
#line 336 "PieMenu.w"
{
    value->addr = (XtPointer) &((XfwfPieMenuWidget)self)->xfwfPieMenu.font;
}
#line 359 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 359 "PieMenu.w"
static void create_gc(Widget self,GC * gc,XFontStruct * fn,Pixel  bg,Pixel  fg)
#else
#line 359 "PieMenu.w"
static void create_gc(self,gc,fn,bg,fg)Widget self;GC * gc;XFontStruct * fn;Pixel  bg;Pixel  fg;
#endif
#line 360 "PieMenu.w"
{
    XGCValues values;

    if (*gc != NULL) XtReleaseGC(self, *gc);
    values.font = fn->fid;
    values.background = bg;
    values.foreground = fg;
    values.fill_style = FillOpaqueStippled;
    values.stipple = ((XfwfPieMenuWidget)self)->xfwfPieMenu.emptystip;
    *gc = XtGetGC(self, GCFont | GCBackground | GCForeground | GCFillStyle
		  | GCStipple, &values);
}
#line 376 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 376 "PieMenu.w"
static void create_linegc(Widget self)
#else
#line 376 "PieMenu.w"
static void create_linegc(self)Widget self;
#endif
#line 377 "PieMenu.w"
{
    XGCValues values;

    if (((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc != NULL) XtReleaseGC(self, ((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc);
    values.background = ((XfwfPieMenuWidget)self)->core.background_pixel;
    values.foreground = ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground;
    values.line_width = 2;
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc = XtGetGC(self, GCBackground | GCForeground | GCLineWidth, &values);
}
#line 390 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 390 "PieMenu.w"
static void create_darkgc(Widget self)
#else
#line 390 "PieMenu.w"
static void create_darkgc(self)Widget self;
#endif
#line 391 "PieMenu.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfPieMenuWidget)self)->xfwfPieMenu.darkgc != NULL) XtReleaseGC(self, ((XfwfPieMenuWidget)self)->xfwfPieMenu.darkgc);
    if (DefaultDepthOfScreen(XtScreen(self)) > 4
	&& choose_color(self, 0.5, ((XfwfPieMenuWidget)self)->core.background_pixel, &values.foreground)) {
	mask = GCForeground;
    } else {
	mask = GCFillStyle | GCBackground | GCForeground | GCStipple;
	values.fill_style = FillOpaqueStippled;
	values.background = ((XfwfPieMenuWidget)self)->core.background_pixel;
	values.foreground = WhitePixelOfScreen(XtScreen(self));
	values.stipple = ((XfwfPieMenuWidget)self)->xfwfPieMenu.stip4;
    }
    mask |= GCLineWidth;
    values.line_width = ((XfwfPieMenuWidget)self)->xfwfPieMenu.frameWidth;
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.darkgc = XtGetGC(self, mask, &values);
}
#line 413 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 413 "PieMenu.w"
static void create_lightgc(Widget self)
#else
#line 413 "PieMenu.w"
static void create_lightgc(self)Widget self;
#endif
#line 414 "PieMenu.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfPieMenuWidget)self)->xfwfPieMenu.lightgc != NULL) XtReleaseGC(self, ((XfwfPieMenuWidget)self)->xfwfPieMenu.lightgc);
    if (DefaultDepthOfScreen(XtScreen(self)) > 4
	&& choose_color(self, 1.35, ((XfwfPieMenuWidget)self)->core.background_pixel, &values.foreground)) {
	mask = GCForeground;
    } else {
	mask = GCFillStyle | GCBackground | GCForeground | GCStipple;
	values.fill_style = FillOpaqueStippled;
	values.background = ((XfwfPieMenuWidget)self)->core.background_pixel;
	values.foreground = WhitePixelOfScreen(XtScreen(self));
	values.stipple = ((XfwfPieMenuWidget)self)->xfwfPieMenu.stip4;
    }
    mask |= GCLineWidth;
    values.line_width = ((XfwfPieMenuWidget)self)->xfwfPieMenu.frameWidth;
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.lightgc = XtGetGC(self, mask, &values);
}
#line 437 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 437 "PieMenu.w"
static Boolean  trim(String  s)
#else
#line 437 "PieMenu.w"
static Boolean  trim(s)String  s;
#endif
#line 438 "PieMenu.w"
{
    int i, j;

    for (i = strlen(s); i > 0 && isspace(s[i-1]); i--) ;
    s[i] = '\0';
    for (i = 0; isspace(s[i]); i++) ;
    if (i != 0) {
	for (j = 0; s[i]; i++, j++) s[j] = s[i];
	s[j] = '\0';
    }
    return s[0] != '\0';
}
#line 465 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 465 "PieMenu.w"
static void parse_menu(String  menu,LabelAction * items,int * nitems)
#else
#line 465 "PieMenu.w"
static void parse_menu(menu,items,nitems)String  menu;LabelAction * items;int * nitems;
#endif
#line 466 "PieMenu.w"
{
    int n, act, parm;
    String p, q, r, s, t;

    if (! menu) {
	*nitems = 0;
	return;
    }

    /* Loop over all items */

    for (n = 0; menu && n < MAXITEMS; n++) {
	if ((p = strchr(menu, '\n'))) *(p++) = '\0'; /* Mark end of item */
	if ((q = strstr(menu, "->"))) *q = '\0', q += 2; /* Start of actions */

	/* Loop over all actions for this item */

	for (act = 0; q && act < MAXACTIONS; act++) {
	    if ((r = strchr(q, ')'))) *(r++) = '\0'; /* End of action */
	    if ((s = strchr(q, '('))) *(s++) = '\0'; /* Start of params */

	    /* Loop over all parameters for this action */

	    for (parm = 0; s && parm < MAXPARAMS; parm++) {
		if ((t = strchr(s, ','))) *(t++) = '\0'; /* End of param */
		if (! trim(s)) parm--;		/* Remove empty param */
		else items[n].params[act][parm] = s;
		s = t;
	    }
	    items[n].num_params[act] = parm;

	    if (! trim(q)) act--;		/* Remove empty action */
	    else items[n].action[act] = q;
	    q = r;				/* Start next action loop */
	}
	items[n].nactions = act;

	if (! trim(menu)) n--;			/* Remove empty item */
	else items[n].label = menu;
	menu = p;				/* Start next item loop */
    }
    *nitems = n;
}

static XtResource resources[] = {
#line 25 "PieMenu.w"
{XtNholeRadius,XtCHoleRadius,XtRDimension,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.holeRadius),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.holeRadius),XtRImmediate,(XtPointer)8 },
#line 42 "PieMenu.w"
{XtNmenu,XtCMenu,XtRString,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.menu),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.menu),XtRImmediate,(XtPointer)NULL },
#line 49 "PieMenu.w"
{XtNbackground1,XtCBackground1,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background1),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background1),XtRCallProc,(XtPointer)copy_bg },
#line 50 "PieMenu.w"
{XtNbackground2,XtCBackground2,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background2),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background2),XtRCallProc,(XtPointer)copy_bg },
#line 51 "PieMenu.w"
{XtNbackground3,XtCBackground3,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background3),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background3),XtRCallProc,(XtPointer)copy_bg },
#line 52 "PieMenu.w"
{XtNbackground4,XtCBackground4,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background4),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background4),XtRCallProc,(XtPointer)copy_bg },
#line 53 "PieMenu.w"
{XtNbackground5,XtCBackground5,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background5),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background5),XtRCallProc,(XtPointer)copy_bg },
#line 54 "PieMenu.w"
{XtNbackground6,XtCBackground6,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.background6),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.background6),XtRCallProc,(XtPointer)copy_bg },
#line 61 "PieMenu.w"
{XtNforeground,XtCForeground,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground),XtRString,(XtPointer)XtDefaultForeground },
#line 62 "PieMenu.w"
{XtNforeground1,XtCForeground1,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground1),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground1),XtRCallProc,(XtPointer)copy_fg },
#line 63 "PieMenu.w"
{XtNforeground2,XtCForeground2,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground2),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground2),XtRCallProc,(XtPointer)copy_fg },
#line 64 "PieMenu.w"
{XtNforeground3,XtCForeground3,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground3),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground3),XtRCallProc,(XtPointer)copy_fg },
#line 65 "PieMenu.w"
{XtNforeground4,XtCForeground4,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground4),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground4),XtRCallProc,(XtPointer)copy_fg },
#line 66 "PieMenu.w"
{XtNforeground5,XtCForeground5,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground5),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground5),XtRCallProc,(XtPointer)copy_fg },
#line 67 "PieMenu.w"
{XtNforeground6,XtCForeground6,XtRPixel,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.foreground6),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.foreground6),XtRCallProc,(XtPointer)copy_fg },
#line 73 "PieMenu.w"
{XtNfont,XtCFont,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font),XtRString,(XtPointer)XtDefaultFont },
#line 74 "PieMenu.w"
{XtNfont1,XtCFont1,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font1),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font1),XtRCallProc,(XtPointer)copy_font },
#line 75 "PieMenu.w"
{XtNfont2,XtCFont2,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font2),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font2),XtRCallProc,(XtPointer)copy_font },
#line 76 "PieMenu.w"
{XtNfont3,XtCFont3,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font3),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font3),XtRCallProc,(XtPointer)copy_font },
#line 77 "PieMenu.w"
{XtNfont4,XtCFont4,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font4),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font4),XtRCallProc,(XtPointer)copy_font },
#line 78 "PieMenu.w"
{XtNfont5,XtCFont5,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font5),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font5),XtRCallProc,(XtPointer)copy_font },
#line 79 "PieMenu.w"
{XtNfont6,XtCFont6,XtRFontStruct,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.font6),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.font6),XtRCallProc,(XtPointer)copy_font },
#line 85 "PieMenu.w"
{XtNframeWidth,XtCFrameWidth,XtRDimension,sizeof(((XfwfPieMenuRec*)NULL)->xfwfPieMenu.frameWidth),XtOffsetOf(XfwfPieMenuRec,xfwfPieMenu.frameWidth),XtRImmediate,(XtPointer)4 },
#line 90 "PieMenu.w"
{XtNborderWidth,XtCBorderWidth,XtRDimension,sizeof(((XfwfPieMenuRec*)NULL)->core.border_width),XtOffsetOf(XfwfPieMenuRec,core.border_width),XtRImmediate,(XtPointer)0 },
};

XfwfPieMenuClassRec xfwfPieMenuClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &overrideShellClassRec,
/* class_name   	*/  "XfwfPieMenu",
/* widget_size  	*/  sizeof(XfwfPieMenuRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  realize,
/* actions      	*/  actionsList,
/* num_actions  	*/  1,
/* resources    	*/  resources,
/* num_resources 	*/  24,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  False ,
/* compress_exposure 	*/  FALSE ,
/* compress_enterleave 	*/  False ,
/* visible_interest 	*/  False ,
/* destroy      	*/  destroy,
/* resize       	*/  XtInheritResize,
/* expose       	*/  expose,
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
{ /* Shell_class part */
 /* dummy */  0
},
{ /* OverrideShell_class part */
 /* dummy */  0
},
{ /* XfwfPieMenu_class part */
 /* dummy */  0
},
};
WidgetClass xfwfPieMenuWidgetClass = (WidgetClass) &xfwfPieMenuClassRec;
/*ARGSUSED*/
#line 295 "PieMenu.w"
static void select_item(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int n, i, dx, dy, dist, nparm;
    double angle;

    dx = event->xbutton.x - ((XfwfPieMenuWidget)self)->core.width/2;
    dy = ((XfwfPieMenuWidget)self)->core.height/2 - event->xbutton.y;
    dist = dx * dx + dy * dy;
    if (dist > ((XfwfPieMenuWidget)self)->core.width * ((XfwfPieMenuWidget)self)->core.width/4) return;	/* Outside */
    if (dist <= ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius * ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius) return; /* In hole */
    angle = atan2((double) dy, (double) dx) - M_PI/4;
    if (angle < 0.0) angle += 2 * M_PI;
    n = (int) (angle / (2 * M_PI/((XfwfPieMenuWidget)self)->xfwfPieMenu.nitems));
    for (i = 0; i < ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[n].nactions; i++)
	XtCallActionProc(self, ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[n].action[i], event, ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[n].params[i],
			 ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[n].num_params[i]);
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfPieMenuWidgetClass c = (XfwfPieMenuWidgetClass) class;
  XfwfPieMenuWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfPieMenuWidgetClass) return;
  super = (XfwfPieMenuWidgetClass)class->core_class.superclass;
}
#line 152 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 152 "PieMenu.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 152 "PieMenu.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 153 "PieMenu.w"
{
    int i;

    if (((XfwfPieMenuWidget)self)->core.width < ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius + 10)
	((XfwfPieMenuWidget)self)->core.width = ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius + 10;
    if (((XfwfPieMenuWidget)self)->core.height < ((XfwfPieMenuWidget)self)->core.width)
	((XfwfPieMenuWidget)self)->core.height = ((XfwfPieMenuWidget)self)->core.width;
    else if (((XfwfPieMenuWidget)self)->core.width < ((XfwfPieMenuWidget)self)->core.height)
	((XfwfPieMenuWidget)self)->core.width = ((XfwfPieMenuWidget)self)->core.height;

    ((XfwfPieMenuWidget)self)->xfwfPieMenu.emptystip = XCreateBitmapFromData
	(XtDisplay(self), RootWindowOfScreen(XtScreen(self)), emptybm_bits,
	 emptybm_width, emptybm_height);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.stip4 = XCreateBitmapFromData
	(XtDisplay(self), RootWindowOfScreen(XtScreen(self)), stip4_bits,
	 stip4_width, stip4_height);

    ((XfwfPieMenuWidget)self)->xfwfPieMenu.lightgc = NULL; create_lightgc(self);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.darkgc = NULL; create_darkgc(self);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc = NULL; create_linegc(self);

    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[0] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[0], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font1, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background1, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground1);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[1] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[1], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font2, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background2, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground2);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[2] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[2], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font3, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background3, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground3);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[3] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[3], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font4, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background4, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground4);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[4] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[4], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font5, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background5, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground5);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[5] = NULL; create_gc(self, &((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[5], ((XfwfPieMenuWidget)self)->xfwfPieMenu.font6, ((XfwfPieMenuWidget)self)->xfwfPieMenu.background6, ((XfwfPieMenuWidget)self)->xfwfPieMenu.foreground6);

    ((XfwfPieMenuWidget)self)->xfwfPieMenu.menu = XtNewString(((XfwfPieMenuWidget)self)->xfwfPieMenu.menu);
    ((XfwfPieMenuWidget)self)->xfwfPieMenu.menu_copy = XtNewString(((XfwfPieMenuWidget)self)->xfwfPieMenu.menu);
    parse_menu(((XfwfPieMenuWidget)self)->xfwfPieMenu.menu_copy, ((XfwfPieMenuWidget)self)->xfwfPieMenu.items, &((XfwfPieMenuWidget)self)->xfwfPieMenu.nitems);
}
#line 190 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 190 "PieMenu.w"
static void realize(Widget self,XtValueMask * mask,XSetWindowAttributes * attributes)
#else
#line 190 "PieMenu.w"
static void realize(self,mask,attributes)Widget self;XtValueMask * mask;XSetWindowAttributes * attributes;
#endif
#line 191 "PieMenu.w"
{
    overrideShellClassRec.core_class.realize(self, mask, attributes);
    (void) XmuReshapeWidget(self, XmuShapeEllipse, -1, -1);
}
#line 203 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 203 "PieMenu.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 203 "PieMenu.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 204 "PieMenu.w"
{
    int i, x, y, len, angle, angle1;
    XFontStruct *fn;
    double a;

    if (! XtIsRealized(self)) return;

    /*
     * Draw the segments and the labels
     */
    angle = 360 * 64/((XfwfPieMenuWidget)self)->xfwfPieMenu.nitems;
    for (i = 0, angle1 = 45 * 64; i < ((XfwfPieMenuWidget)self)->xfwfPieMenu.nitems; i++, angle1 += angle) {
	XFillArc(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[i], 0, 0, ((XfwfPieMenuWidget)self)->core.width, ((XfwfPieMenuWidget)self)->core.height,
		 angle1, angle);
	fn = (i == 0 ? ((XfwfPieMenuWidget)self)->xfwfPieMenu.font1
	      : (i == 1 ? ((XfwfPieMenuWidget)self)->xfwfPieMenu.font2
		 : (i == 2 ? ((XfwfPieMenuWidget)self)->xfwfPieMenu.font3
		    : (i == 3 ? ((XfwfPieMenuWidget)self)->xfwfPieMenu.font4
		       : (i == 4 ? ((XfwfPieMenuWidget)self)->xfwfPieMenu.font5
			  : ((XfwfPieMenuWidget)self)->xfwfPieMenu.font6)))));
	len = strlen(((XfwfPieMenuWidget)self)->xfwfPieMenu.items[i].label);
	a = (angle1 + angle/2) * 2 * M_PI/360/64;
	x = ((XfwfPieMenuWidget)self)->core.width/2 - XTextWidth(fn, ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[i].label, len)/2
	    + (int) (cos(a) * ((XfwfPieMenuWidget)self)->core.width * 0.3);
	y = ((XfwfPieMenuWidget)self)->core.height/2 - (fn->ascent + fn->descent)/2 + fn->ascent
	    - (int) (sin(a) * ((XfwfPieMenuWidget)self)->core.height * 0.3);
	XDrawImageString(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[i], x, y,
		    ((XfwfPieMenuWidget)self)->xfwfPieMenu.items[i].label, len);
    }
    /*
     * Draw central `hole'
     */
    XFillArc(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc, ((XfwfPieMenuWidget)self)->core.width/2 - ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius,
	     ((XfwfPieMenuWidget)self)->core.height/2 - ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius, 2 * ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius, 2 * ((XfwfPieMenuWidget)self)->xfwfPieMenu.holeRadius,
	     0, 360 * 64);

    /*
     * Draw lines separating the segments
     */
    for (i = 0, angle1 = 45 * 64; i < ((XfwfPieMenuWidget)self)->xfwfPieMenu.nitems; i++, angle1 += angle) {
	a = angle1 * 2 * M_PI/360/64;
	x = (int) (cos(a) * ((XfwfPieMenuWidget)self)->core.width/2) + ((XfwfPieMenuWidget)self)->core.width/2;
	y = ((XfwfPieMenuWidget)self)->core.height/2 - (int) (sin(a) * ((XfwfPieMenuWidget)self)->core.height/2);
	XDrawLine(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.linegc, ((XfwfPieMenuWidget)self)->core.width/2, ((XfwfPieMenuWidget)self)->core.height/2,
		  x, y);
    }
    /*
     * Draw shadow border
     */
    XDrawArc(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.lightgc, 0, 0, ((XfwfPieMenuWidget)self)->core.width, ((XfwfPieMenuWidget)self)->core.height,
	     45 * 64, 180 * 64);
    XDrawArc(XtDisplay(self), XtWindow(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.darkgc, 0, 0, ((XfwfPieMenuWidget)self)->core.width, ((XfwfPieMenuWidget)self)->core.height,
	     225 * 64, 180 * 64);
}
#line 263 "PieMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 263 "PieMenu.w"
static void destroy(Widget self)
#else
#line 263 "PieMenu.w"
static void destroy(self)Widget self;
#endif
#line 264 "PieMenu.w"
{
    int i;

    for (i = 0; i < MAXITEMS; i++)
	XtReleaseGC(self, ((XfwfPieMenuWidget)self)->xfwfPieMenu.gc[i]);
    XFreePixmap(XtDisplay(self), ((XfwfPieMenuWidget)self)->xfwfPieMenu.emptystip);
    XtFree(((XfwfPieMenuWidget)self)->xfwfPieMenu.menu_copy);
    XtFree(((XfwfPieMenuWidget)self)->xfwfPieMenu.menu);
}
