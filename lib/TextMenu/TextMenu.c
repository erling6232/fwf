/* Generated by wbuild from "TextMenu.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <stdlib.h>
#line 657 "TextMenu.w"
#include <X11/Xmu/CharSet.h>
#line 658 "TextMenu.w"
#include "stip4.bm"
#line 659 "TextMenu.w"
#include <stdio.h>
#line 660 "TextMenu.w"
#include <Xfwf/TabString.h>
#line 661 "TextMenu.w"
#include <Xfwf/Converters.h>
#line 662 "TextMenu.w"
#include <X11/Xmu/Converters.h>
#line 663 "TextMenu.w"
#include <ctype.h>
#include <Xfwf/TextMenuP.h>
#line 296 "TextMenu.w"
static void init(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 301 "TextMenu.w"
static void add_keyboard_grab(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 306 "TextMenu.w"
static void remove_keyboard_grab(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 317 "TextMenu.w"
static void highlight(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 343 "TextMenu.w"
static void notify(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 361 "TextMenu.w"
static void previous(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 380 "TextMenu.w"
static void next(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 405 "TextMenu.w"
static void shortcut(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"init", init},
{"add_keyboard_grab", add_keyboard_grab},
{"remove_keyboard_grab", remove_keyboard_grab},
{"highlight", highlight},
{"notify", notify},
{"previous", previous},
{"next", next},
{"shortcut", shortcut},
};

static char defaultTranslations[] = "\
<EnterWindow>: highlight() \n\
<LeaveWindow>: highlight() \n\
<BtnUp>: XtMenuPopdown() notify() \n\
<BtnMotion>: highlight() \n\
<Key>Return: XtMenuPopdown() notify() \n\
<Key>Escape: XtMenuPopdown() \n\
<Key>Up: previous() \n\
<Key>Down: next() \n\
<Key>: shortcut() \n\
<Map>: init() add_keyboard_grab() \n\
<Unmap>: remove_keyboard_grab() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 167 "TextMenu.w"
static void class_initialize(
#if NeedFunctionPrototypes
void
#endif
);
#line 181 "TextMenu.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 202 "TextMenu.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 239 "TextMenu.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 260 "TextMenu.w"
static void destroy(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 439 "TextMenu.w"
#define is_active(n) (n >=8 *sizeof (((XfwfTextMenuWidget)self)->xfwfTextMenu.active )||(((XfwfTextMenuWidget)self)->xfwfTextMenu.active &(1 <<n )))


#line 445 "TextMenu.w"
#define myrealloc(p, size) ((XtPointer )XtRealloc ((char *)p ,size ))


#line 446 "TextMenu.w"
#define mymalloc(size) ((XtPointer )XtMalloc (size ))


#line 447 "TextMenu.w"
#define myfree(p) XtFree ((XtPointer )p )


#line 452 "TextMenu.w"
#define MARGIN 5 


#line 457 "TextMenu.w"
static void draw_label(
#if NeedFunctionPrototypes
Widget,int ,GC 
#endif
);
#line 488 "TextMenu.w"
static void draw_normal(
#if NeedFunctionPrototypes
Widget,int 
#endif
);
#line 497 "TextMenu.w"
static void draw_highlight(
#if NeedFunctionPrototypes
Widget,int 
#endif
);
#line 506 "TextMenu.w"
static void draw_grayed(
#if NeedFunctionPrototypes
Widget,int 
#endif
);
#line 523 "TextMenu.w"
#define LINEWD 2 


#line 525 "TextMenu.w"
static void parse_menu(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 595 "TextMenu.w"
static void make_gc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 611 "TextMenu.w"
static void make_rvgc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 628 "TextMenu.w"
static void make_graygc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 647 "TextMenu.w"
static void add_cursor_cb(
#if NeedFunctionPrototypes
Widget,XtPointer ,XtPointer 
#endif
);
#line 457 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 457 "TextMenu.w"
static void draw_label(Widget self,int  n,GC  gc)
#else
#line 457 "TextMenu.w"
static void draw_label(self,n,gc)Widget self;int  n;GC  gc;
#endif
#line 458 "TextMenu.w"
{
    Cardinal i, j;
    Dimension w, w1;
    Position y;
    Display *dpy = XtDisplay(self);
    Window win = XtWindow(self);
    String s;

    y = ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[n] + ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->ascent;
    i = 0;
    s = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[n];
    for (j = i; s[j] && s[j] != '\n' && s[j] != '_'; j++) ;
    XfwfDrawImageString(dpy, win, gc, MARGIN, y, s, j - i, ((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs);
    if (s[j] == '_') {
	w = XfwfTextWidth(((XfwfTextMenuWidget)self)->xfwfTextMenu.font, s, j - i, ((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs);
	i = j + 1;
	w1 = XTextWidth(((XfwfTextMenuWidget)self)->xfwfTextMenu.font, s + i, 1);
	for (j = i; s[j] && s[j] != '\n'; j++) ;
	XfwfDrawImageString(dpy, win, gc, MARGIN + w, y, s + i, j - i,
			    ((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs);
	XDrawLine(dpy, win, gc, MARGIN + w, y + 2, MARGIN + w + w1 - 1,
		  y + 2);
    }
}
#line 488 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 488 "TextMenu.w"
static void draw_normal(Widget self,int  n)
#else
#line 488 "TextMenu.w"
static void draw_normal(self,n)Widget self;int  n;
#endif
#line 489 "TextMenu.w"
{
    XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc, MARGIN,
		   ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[n], ((XfwfTextMenuWidget)self)->core.width - 2 * MARGIN, ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight);
    draw_label(self, n, ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc);
}
#line 497 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 497 "TextMenu.w"
static void draw_highlight(Widget self,int  n)
#else
#line 497 "TextMenu.w"
static void draw_highlight(self,n)Widget self;int  n;
#endif
#line 498 "TextMenu.w"
{
    XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc, MARGIN,
		   ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[n], ((XfwfTextMenuWidget)self)->core.width - 2 * MARGIN, ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight);
    draw_label(self, n, ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc);
}
#line 506 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 506 "TextMenu.w"
static void draw_grayed(Widget self,int  n)
#else
#line 506 "TextMenu.w"
static void draw_grayed(self,n)Widget self;int  n;
#endif
#line 507 "TextMenu.w"
{
    draw_label(self, n, ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc);
    XFillRectangle(XtDisplay(self), XtWindow(self), ((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc, MARGIN,
		   ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[n], ((XfwfTextMenuWidget)self)->core.width - 2 * MARGIN, ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight);
}
#line 525 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 525 "TextMenu.w"
static void parse_menu(Widget self)
#else
#line 525 "TextMenu.w"
static void parse_menu(self)Widget self;
#endif
#line 526 "TextMenu.w"
{
    Cardinal i, j, nlines = 0, n, ai, accellen = 0;
    Bool is_line, accel, has_accel;
    char key, h[1024], accelerator[100], *all_accel = NULL;
    Position y = MARGIN;
    Dimension w;

    ((XfwfTextMenuWidget)self)->core.width = 1;
    n = 0;
    i = 0;
    /* fprintf(stderr, "Parsing:\n%s\n", $menu); */
    while (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[i]) {
	is_line = TRUE;
	has_accel = accel = FALSE;
	ai = 0;
	key = '\0';
	for (; isspace(((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[i]); i++) ;
	for (j = i; ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] != '\0' && ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] != '\n'; j++) {
	    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] == ']') accel = FALSE;
	    if (accel) accelerator[ai++] = ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j];
	    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] == '[') has_accel = accel = TRUE;
	    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] == '_') key = ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j+1];
	    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] != '-' && ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] != ' ') is_line = False;
	}
	if (is_line) {
	    nlines++;
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.line = myrealloc(((XfwfTextMenuWidget)self)->xfwfTextMenu.line, (nlines + 1) * sizeof(*((XfwfTextMenuWidget)self)->xfwfTextMenu.line));
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.line[nlines-1] = y + MARGIN;
	    y += LINEWD + 2 * MARGIN;
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.line[nlines] = 0;
	} else {
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.item = myrealloc(((XfwfTextMenuWidget)self)->xfwfTextMenu.item, (n + 1) * sizeof(*((XfwfTextMenuWidget)self)->xfwfTextMenu.item));
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[n] = mymalloc((j - i + 1) * sizeof(*((XfwfTextMenuWidget)self)->xfwfTextMenu.item[n]));
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[n][0] = '\0'; strncat(((XfwfTextMenuWidget)self)->xfwfTextMenu.item[n], &((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[i], j - i);
	    /* fprintf(stderr, "Item %d: %s\n", n, $item[n]); */
	    w = XfwfTextWidth(((XfwfTextMenuWidget)self)->xfwfTextMenu.font, &((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[i], j - i, ((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs);
	    /* The width includes an extra '_'; is that serious? */
	    if (w > ((XfwfTextMenuWidget)self)->core.width) ((XfwfTextMenuWidget)self)->core.width = w;
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset = myrealloc(((XfwfTextMenuWidget)self)->xfwfTextMenu.offset, (n + 1) * sizeof(*((XfwfTextMenuWidget)self)->xfwfTextMenu.offset));
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[n] = y;
	    y += ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight;
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut = myrealloc(((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut, (n + 1) * sizeof(*((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut));
	    ((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut[n] = key;
	    n++;
	}
	if (has_accel) {			/* Create accelerator */
	    int hlen;
	    accelerator[ai] = '\0';
	    hlen = sprintf(h, "%s: notify(\"%d\")\n", accelerator, n - 1);
	    accellen += hlen;
	    all_accel = myrealloc(all_accel, accellen + 1);
	    strcat(all_accel, h);
	    /* fprintf(stderr, "Accelerator: %s\n", h); */
	}
	i = ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu[j] == '\0' ? j : j + 1;
    }
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems = n;
    ((XfwfTextMenuWidget)self)->core.height = y + MARGIN;
    ((XfwfTextMenuWidget)self)->core.width += 2 * MARGIN;
    if (all_accel) {
	XtVaSetValues(self, XtVaTypedArg, XtNaccelerators, XtRString,
		      all_accel, accellen + 1, NULL);
	/* fprintf(stderr, "Accelerators:\n%s\n", all_accel); */
    }
}
#line 595 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 595 "TextMenu.w"
static void make_gc(Widget self)
#else
#line 595 "TextMenu.w"
static void make_gc(self)Widget self;
#endif
#line 596 "TextMenu.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.gc != NULL) XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc);
    values.background = ((XfwfTextMenuWidget)self)->core.background_pixel;
    values.foreground = ((XfwfTextMenuWidget)self)->xfwfTextMenu.foreground;
    values.font = ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->fid;
    values.line_width = LINEWD;
    mask = GCFont | GCBackground | GCForeground | GCLineWidth;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc = XtGetGC(self, mask, &values);
}
#line 611 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 611 "TextMenu.w"
static void make_rvgc(Widget self)
#else
#line 611 "TextMenu.w"
static void make_rvgc(self)Widget self;
#endif
#line 612 "TextMenu.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc != NULL) XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc);
    values.foreground = ((XfwfTextMenuWidget)self)->core.background_pixel;
    values.background = ((XfwfTextMenuWidget)self)->xfwfTextMenu.foreground;
    values.font = ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->fid;
    mask = GCFont | GCBackground | GCForeground;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc = XtGetGC(self, mask, &values);
}
#line 628 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 628 "TextMenu.w"
static void make_graygc(Widget self)
#else
#line 628 "TextMenu.w"
static void make_graygc(self)Widget self;
#endif
#line 629 "TextMenu.w"
{
    XtGCMask mask;
    XGCValues values;

    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc != NULL) XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc);
    values.foreground = ((XfwfTextMenuWidget)self)->core.background_pixel;
    values.stipple =
	XCreateBitmapFromData(XtDisplay(self),
			      RootWindowOfScreen(XtScreen(self)),
			      stip4_bits, stip4_width, stip4_height);
    values.fill_style = FillStippled;
    mask = GCForeground | GCStipple | GCFillStyle;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc = XtGetGC(self, mask, &values);
}
#line 647 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 647 "TextMenu.w"
static void add_cursor_cb(Widget self,XtPointer  client_data,XtPointer  call_data)
#else
#line 647 "TextMenu.w"
static void add_cursor_cb(self,client_data,call_data)Widget self;XtPointer  client_data;XtPointer  call_data;
#endif
#line 648 "TextMenu.w"
{
    XChangeActivePointerGrab(XtDisplay(self), ButtonPressMask |
			     ButtonReleaseMask | EnterWindowMask |
			     LeaveWindowMask | PointerMotionMask, ((XfwfTextMenuWidget)self)->xfwfTextMenu.cursor,
			     XtLastTimestampProcessed(XtDisplay(self)));
}

static XtResource resources[] = {
#line 25 "TextMenu.w"
{XtNfont,XtCFont,XtRFontStruct,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.font),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.font),XtRString,(XtPointer)XtDefaultFont },
#line 29 "TextMenu.w"
{XtNforeground,XtCForeground,XtRPixel,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.foreground),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.foreground),XtRString,(XtPointer)XtDefaultForeground },
#line 36 "TextMenu.w"
{XtNtablist,XtCTablist,XtRString,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.tablist),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.tablist),XtRImmediate,(XtPointer)NULL },
#line 53 "TextMenu.w"
{XtNmenu,XtCMenu,XtRString,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.menu),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.menu),XtRImmediate,(XtPointer)"empty"},
#line 60 "TextMenu.w"
{XtNactive,XtCActive,XtRLong,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.active),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.active),XtRImmediate,(XtPointer)0xFFFFFFFF },
#line 74 "TextMenu.w"
{XtNselection,XtCSelection,XtRInt,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.selection),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.selection),XtRImmediate,(XtPointer)-1 },
#line 80 "TextMenu.w"
{XtNcursor,XtCCursor,XtRCursor,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.cursor),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.cursor),XtRString,(XtPointer)"arrow"},
#line 90 "TextMenu.w"
{XtNactivate,XtCActivate,XtRCallback,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.activate),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.activate),XtRImmediate,(XtPointer)NULL },
#line 99 "TextMenu.w"
{XtNchangeSelection,XtCChangeSelection,XtRCallback,sizeof(((XfwfTextMenuRec*)NULL)->xfwfTextMenu.changeSelection),XtOffsetOf(XfwfTextMenuRec,xfwfTextMenu.changeSelection),XtRImmediate,(XtPointer)NULL },
};

XfwfTextMenuClassRec xfwfTextMenuClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &overrideShellClassRec,
/* class_name   	*/  "XfwfTextMenu",
/* widget_size  	*/  sizeof(XfwfTextMenuRec),
/* class_initialize 	*/  class_initialize,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  actionsList,
/* num_actions  	*/  8,
/* resources    	*/  resources,
/* num_resources 	*/  9,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  False ,
/* compress_exposure 	*/  FALSE ,
/* compress_enterleave 	*/  False ,
/* visible_interest 	*/  False ,
/* destroy      	*/  destroy,
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
{ /* Shell_class part */
 /* dummy */  0
},
{ /* OverrideShell_class part */
 /* dummy */  0
},
{ /* XfwfTextMenu_class part */
 /* dummy */  0
},
};
WidgetClass xfwfTextMenuWidgetClass = (WidgetClass) &xfwfTextMenuClassRec;
/*ARGSUSED*/
#line 296 "TextMenu.w"
static void init(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.selection < 0) XtVaSetValues(self, XtNselection, 0, NULL);
}

/*ARGSUSED*/
#line 301 "TextMenu.w"
static void add_keyboard_grab(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    XtGrabKeyboard(self, False, GrabModeAsync, GrabModeAsync, CurrentTime);
}

/*ARGSUSED*/
#line 306 "TextMenu.w"
static void remove_keyboard_grab(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    XtUngrabKeyboard(self, CurrentTime);
}

/*ARGSUSED*/
#line 317 "TextMenu.w"
static void highlight(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int newsel, x = event->xbutton.x, y = event->xbutton.y;
    XfwfTextMenuData data;

    if (x < 0 || x >= ((XfwfTextMenuWidget)self)->core.width)			/* Pointer outside menu */
	newsel = -1;
    else					/* Pointer inside menu */
	for (newsel = ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems - 1; newsel >= 0; newsel--)
	    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[newsel] <= y && y < ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset[newsel] + ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight)
		break;
    if (newsel != ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection) {
	if (((XfwfTextMenuWidget)self)->xfwfTextMenu.selection >= 0 && is_active(((XfwfTextMenuWidget)self)->xfwfTextMenu.selection))
	    draw_normal(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection);
	if (newsel >= 0 && is_active(newsel))
	    draw_highlight(self, newsel);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.selection = newsel;
	data.n = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection;
	data.label = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[((XfwfTextMenuWidget)self)->xfwfTextMenu.selection];
	XtCallCallbackList(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.changeSelection, &data);
    }
}

/*ARGSUSED*/
#line 343 "TextMenu.w"
static void notify(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    XfwfTextMenuData data;

    if (*num_params != 0)
	sscanf(params[0], "%d", &((XfwfTextMenuWidget)self)->xfwfTextMenu.selection);
    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.selection >= 0 && is_active(((XfwfTextMenuWidget)self)->xfwfTextMenu.selection)) {
	data.n = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection;
	data.label = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[((XfwfTextMenuWidget)self)->xfwfTextMenu.selection];
	XtCallCallbackList(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.activate, &data);
    }
}

/*ARGSUSED*/
#line 361 "TextMenu.w"
static void previous(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int newsel;
    XfwfTextMenuData data;

    for (newsel = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection - 1; newsel >= 0; newsel--)
	if (is_active(newsel)) break;
    if (newsel >= 0) {
	if (is_active(((XfwfTextMenuWidget)self)->xfwfTextMenu.selection)) draw_normal(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection);
	draw_highlight(self, newsel);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.selection = newsel;
	data.n = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection;
	data.label = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[((XfwfTextMenuWidget)self)->xfwfTextMenu.selection];
	XtCallCallbackList(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.changeSelection, &data);
    }
}

/*ARGSUSED*/
#line 380 "TextMenu.w"
static void next(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int newsel;
    XfwfTextMenuData data;

    for (newsel = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection + 1; newsel < ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems; newsel++)
	if (is_active(newsel)) break;
    if (newsel < ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems) {
	if (((XfwfTextMenuWidget)self)->xfwfTextMenu.selection >= 0 && is_active(((XfwfTextMenuWidget)self)->xfwfTextMenu.selection))
	    draw_normal(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection);
	draw_highlight(self, newsel);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.selection = newsel;
	data.n = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection;
	data.label = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[((XfwfTextMenuWidget)self)->xfwfTextMenu.selection];
	XtCallCallbackList(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.changeSelection, &data);
    }
}

/*ARGSUSED*/
#line 405 "TextMenu.w"
static void shortcut(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int newsel, n;
    XfwfTextMenuData data;
    char buf[3];

    if (*num_params == 1) {
	newsel = atol(params[0]);
	if (newsel < 0 || newsel >= ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems) {
	    XtWarning("Incorrect arguments for shortcut action");
	    return;
	}
	if (newsel == ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection || ! is_active(newsel)) return;
    } else if (*num_params == 0) {
	n = XLookupString(&event->xkey, buf, sizeof(buf), NULL, NULL);
	if (n != 1) return;
	for (newsel = 0; newsel < ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems; newsel++)
	    if (toupper(((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut[newsel]) == toupper(buf[0])) break;
	if (newsel == ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems || ! is_active(newsel)) return;
    } else {
	XtWarning("Incorrect arguments for shortcut action");
	return;
    }
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection = newsel;
    XtPopdown(self);
    data.n = ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection;
    data.label = ((XfwfTextMenuWidget)self)->xfwfTextMenu.item[((XfwfTextMenuWidget)self)->xfwfTextMenu.selection];
    XtCallCallbackList(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.activate, &data);
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfTextMenuWidgetClass c = (XfwfTextMenuWidgetClass) class;
  XfwfTextMenuWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfTextMenuWidgetClass) return;
  super = (XfwfTextMenuWidgetClass)class->core_class.superclass;
}
#line 167 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 167 "TextMenu.w"
static void class_initialize(void)
#else
#line 167 "TextMenu.w"
static void class_initialize()
#endif
#line 168 "TextMenu.w"
{
    XtAddConverter(XtRString, XtRLong, XmuCvtStringToLong, NULL, 0);
    XtSetTypeConverter(XtRLong, XtRString, XfwfCvtLongToString,
		       NULL, 0, XtCacheNone, NULL);
}
#line 181 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 181 "TextMenu.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 181 "TextMenu.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 182 "TextMenu.w"
{
    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.menu) ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu = XtNewString(((XfwfTextMenuWidget)self)->xfwfTextMenu.menu);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight = ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->ascent + ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->descent;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist = XtNewString(((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs = XfwfTablist2Tabs(((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.offset = NULL;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.item = NULL;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.line = NULL;
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut = NULL;
    parse_menu(self);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc = NULL; make_gc(self);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc = NULL; make_rvgc(self);
    ((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc = NULL; make_graygc(self);
    XtAddCallback(self, XtNpopupCallback, add_cursor_cb, NULL);
}
#line 202 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 202 "TextMenu.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 202 "TextMenu.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 203 "TextMenu.w"
{
    Boolean need_redraw = False;

    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.font != ((XfwfTextMenuWidget)self)->xfwfTextMenu.font) {
	((XfwfTextMenuWidget)self)->xfwfTextMenu.itemheight = ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->ascent + ((XfwfTextMenuWidget)self)->xfwfTextMenu.font->descent;
	need_redraw = True;
    }
    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.foreground != ((XfwfTextMenuWidget)self)->xfwfTextMenu.foreground) {
	need_redraw = True;
    }
    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.tablist != ((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist) {
	myfree(((XfwfTextMenuWidget)old)->xfwfTextMenu.tablist);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist = XtNewString(((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist);
	myfree(((XfwfTextMenuWidget)old)->xfwfTextMenu.tabs);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs = XfwfTablist2Tabs(((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist);
	need_redraw = True;
    }
    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.menu != ((XfwfTextMenuWidget)self)->xfwfTextMenu.menu) {
	myfree(((XfwfTextMenuWidget)old)->xfwfTextMenu.menu);
	((XfwfTextMenuWidget)self)->xfwfTextMenu.menu = XtNewString(((XfwfTextMenuWidget)self)->xfwfTextMenu.menu);
	parse_menu(self);
	need_redraw = True;
    }
    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.active != ((XfwfTextMenuWidget)self)->xfwfTextMenu.active) {
	need_redraw = True;
    }
    if (((XfwfTextMenuWidget)old)->xfwfTextMenu.selection != ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection) {
	need_redraw = True;
    }
    return need_redraw;
}
#line 239 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 239 "TextMenu.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 239 "TextMenu.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 240 "TextMenu.w"
{
    Cardinal i;

    if (! XtIsRealized(self)) return;
    for (i = 0; i < ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems; i++)
	if (! is_active(i)) draw_grayed(self, i);
	else if (i == ((XfwfTextMenuWidget)self)->xfwfTextMenu.selection) draw_highlight(self, i);
	else draw_label(self, i, ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc);
    if (((XfwfTextMenuWidget)self)->xfwfTextMenu.line)
	for (i = 0; ((XfwfTextMenuWidget)self)->xfwfTextMenu.line[i]; i++)
	    XDrawLine(XtDisplay(self), XtWindow(self), ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc, 0, ((XfwfTextMenuWidget)self)->xfwfTextMenu.line[i],
		      ((XfwfTextMenuWidget)self)->core.width, ((XfwfTextMenuWidget)self)->xfwfTextMenu.line[i]);
}
#line 260 "TextMenu.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 260 "TextMenu.w"
static void destroy(Widget self)
#else
#line 260 "TextMenu.w"
static void destroy(self)Widget self;
#endif
#line 261 "TextMenu.w"
{
    int i;

    for (i = 0; i < ((XfwfTextMenuWidget)self)->xfwfTextMenu.nitems; i++) myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.item[i]);
    myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.tablist); myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.tabs); myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.menu); myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.shortcut);
    myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.offset); myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.item); myfree(((XfwfTextMenuWidget)self)->xfwfTextMenu.line);
    XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.gc); XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.rvgc); XtReleaseGC(self, ((XfwfTextMenuWidget)self)->xfwfTextMenu.graygc);
}
#line 108 "TextMenu.w"
