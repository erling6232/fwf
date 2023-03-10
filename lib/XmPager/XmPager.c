/* Generated by wbuild from "XmPager.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 721 "XmPager.w"
#include "flip_back.xpm"
#line 722 "XmPager.w"
#include "flip_forward.xpm"
#line 723 "XmPager.w"
#include <Xfwf/XmIcon.h>
#line 724 "XmPager.w"
#include <stdlib.h>
#line 725 "XmPager.w"
#include <fcntl.h>
#line 726 "XmPager.w"
#include <stdio.h>
#line 727 "XmPager.w"
#include <Xfwf/TabString.h>
#line 728 "XmPager.w"
#include <X11/Xmu/Converters.h>
#include <Xfwf/XmPagerP.h>
#line 392 "XmPager.w"
static void previous_page(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 397 "XmPager.w"
static void next_page(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"previous_page", previous_page},
{"next_page", next_page},
};

static char defaultTranslations[] = "\
<Key>Prior: previous_page() \n\
<Key>BackSpace: previous_page() \n\
<Key>minus: previous_page() \n\
<Key>Next: next_page() \n\
<Key>space: next_page() \n\
<Key>plus: next_page() \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 168 "XmPager.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 240 "XmPager.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 284 "XmPager.w"
static void resize(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 302 "XmPager.w"
static void realize(
#if NeedFunctionPrototypes
Widget,XtValueMask *,XSetWindowAttributes *
#endif
);
#line 328 "XmPager.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 374 "XmPager.w"
static XtGeometryResult  query_geometry(
#if NeedFunctionPrototypes
Widget,XtWidgetGeometry *,XtWidgetGeometry *
#endif
);
#line 408 "XmPager.w"
#define INCREMENT 2048 


#line 409 "XmPager.w"
#define mrealloc(ptr, size) (void *)XtRealloc ((char *)ptr ,size )


#line 411 "XmPager.w"
static void read_from_file(
#if NeedFunctionPrototypes
Widget,String 
#endif
);
#line 432 "XmPager.w"
static void read_from_pipe(
#if NeedFunctionPrototypes
Widget,String 
#endif
);
#line 455 "XmPager.w"
static void init_text(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 476 "XmPager.w"
static void split_text(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 527 "XmPager.w"
#define F_FOUNDRY 1 


#line 528 "XmPager.w"
#define F_FAMILY 2 


#line 529 "XmPager.w"
#define F_WEIGHT 3 


#line 530 "XmPager.w"
#define F_SLANT 4 


#line 531 "XmPager.w"
#define F_SET_WIDTH 5 


#line 532 "XmPager.w"
#define F_SANS 6 


#line 533 "XmPager.w"
#define F_PIXELS 7 


#line 534 "XmPager.w"
#define F_POINTS 8 


#line 535 "XmPager.w"
#define F_HRESOLUTION 9 


#line 536 "XmPager.w"
#define F_VRESOLUTION 10 


#line 537 "XmPager.w"
#define F_SPACING 11 


#line 538 "XmPager.w"
#define F_AVG_WITH 12 


#line 539 "XmPager.w"
#define F_CHARSET 13 


#line 541 "XmPager.w"
static void scale_font(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 577 "XmPager.w"
static void create_romangc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 597 "XmPager.w"
static Boolean  infer_roman(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 630 "XmPager.w"
static void guess_roman(
#if NeedFunctionPrototypes
Widget,int ,XrmValue *
#endif
);
#line 648 "XmPager.w"
static Boolean  is_scalable_font(
#if NeedFunctionPrototypes
String 
#endif
);
#line 670 "XmPager.w"
static Boolean  parse_font_name(
#if NeedFunctionPrototypes
String ,String *
#endif
);
#line 691 "XmPager.w"
static void forward_CB(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 706 "XmPager.w"
static void backwards_CB(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 411 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 411 "XmPager.w"
static void read_from_file(Widget self,String  filename)
#else
#line 411 "XmPager.w"
static void read_from_file(self,filename)Widget self;String  filename;
#endif
#line 412 "XmPager.w"
{
    int fd, len = 0, nbytes;

    if ((fd = open(filename, O_RDONLY)) < 0) {
	perror(filename);
	return;
    }
    do {
	((XmPagerWidget)self)->xmPager.fulltext = mrealloc(((XmPagerWidget)self)->xmPager.fulltext, len + INCREMENT + 1);
	nbytes = read(fd, ((XmPagerWidget)self)->xmPager.fulltext + len, INCREMENT);
	if (nbytes < 0) perror(filename); else len += nbytes;
    } while (nbytes > 0);
    ((XmPagerWidget)self)->xmPager.fulltext[len] = '\0';
    (void) close(fd);
}
#line 432 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 432 "XmPager.w"
static void read_from_pipe(Widget self,String  cmd)
#else
#line 432 "XmPager.w"
static void read_from_pipe(self,cmd)Widget self;String  cmd;
#endif
#line 433 "XmPager.w"
{
    int len = 0, nbytes;
    FILE *stream;

    if ((stream = popen(cmd, "r")) == NULL) {
	perror(cmd);
	return;
    }
    do {
	((XmPagerWidget)self)->xmPager.fulltext = mrealloc(((XmPagerWidget)self)->xmPager.fulltext, sizeof(char) * (len + INCREMENT + 1));
	nbytes = fread(((XmPagerWidget)self)->xmPager.fulltext + len, sizeof(char), INCREMENT, stream);
	if (nbytes < 0) perror(cmd); else len += nbytes;
    } while (nbytes > 0);
    ((XmPagerWidget)self)->xmPager.fulltext[len] = '\0';
    (void) pclose(stream);
}
#line 455 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 455 "XmPager.w"
static void init_text(Widget self)
#else
#line 455 "XmPager.w"
static void init_text(self)Widget self;
#endif
#line 456 "XmPager.w"
{
    XtFree(((XmPagerWidget)self)->xmPager.fulltext); ((XmPagerWidget)self)->xmPager.fulltext = NULL;
    XtFree((char*) ((XmPagerWidget)self)->xmPager.page); ((XmPagerWidget)self)->xmPager.page = NULL;
    if (((XmPagerWidget)self)->xmPager.text == NULL) return;
    /*
     * Initialize $fulltext
     */
    switch (((XmPagerWidget)self)->xmPager.text[0]) {
    case '@': read_from_file(self, ((XmPagerWidget)self)->xmPager.text + 1); break;
    case '`': read_from_pipe(self, ((XmPagerWidget)self)->xmPager.text + 1); break;
    default: ((XmPagerWidget)self)->xmPager.fulltext = XtNewString(((XmPagerWidget)self)->xmPager.text);
    }
}
#line 476 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 476 "XmPager.w"
static void split_text(Widget self)
#else
#line 476 "XmPager.w"
static void split_text(self)Widget self;
#endif
#line 477 "XmPager.w"
{
    int i, j, n, h;
    Position x, y;
    Dimension wd, ht;
    char prev = '\0';

    ((XmPagerWidget)self)->xmPager.page = mrealloc(((XmPagerWidget)self)->xmPager.page, 3 * sizeof(((XmPagerWidget)self)->xmPager.page[0]));
    ((XmPagerWidget)self)->xmPager.page[1] = 0;
    j = 2;
    /* Wrapping is not implemented yet */
    if (((XmPagerWidget)self)->xmPager.lines > 0 && ((XmPagerWidget)self)->xmPager.fulltext != NULL) {
	/* Count lines until n == $lines */
	n = 0;
	for (i = 0; ((XmPagerWidget)self)->xmPager.fulltext[i]; prev = ((XmPagerWidget)self)->xmPager.fulltext[i], i++) {
	    if (prev == '\n') {
		n++;
		if (n == ((XmPagerWidget)self)->xmPager.lines) {
		    ((XmPagerWidget)self)->xmPager.page = mrealloc(((XmPagerWidget)self)->xmPager.page, (j+2) * sizeof(((XmPagerWidget)self)->xmPager.page[0]));
		    ((XmPagerWidget)self)->xmPager.page[j++] = i;
		    n = 0;
		}
	    }
	}
    } else if (((XmPagerWidget)self)->xmPager.fulltext != NULL) {
	/* Determine page length with actual height of the text */
	x = ((XmPagerWidget)self)->xmManager.shadow_thickness; y = ((XmPagerWidget)self)->xmManager.shadow_thickness;
	wd = ((XmPagerWidget)self)->core.width - 2 * x; ht = ((XmPagerWidget)self)->core.height - 2 * y;
	h = y + ((XmPagerWidget)self)->xmPager.margin + ((XmPagerWidget)self)->xmPager.baselineskip;
	ht = y + ht - 50;
	for (i = 0; ((XmPagerWidget)self)->xmPager.fulltext[i]; prev = ((XmPagerWidget)self)->xmPager.fulltext[i], i++) {
	    if (prev == '\n') {
		h += ((XmPagerWidget)self)->xmPager.baselineskip;
		if (h + ((XmPagerWidget)self)->xmPager.roman->descent >= ht) {
		    ((XmPagerWidget)self)->xmPager.page[j++] = i;
		    h = y + ((XmPagerWidget)self)->xmPager.margin + ((XmPagerWidget)self)->xmPager.baselineskip;
		}
	    }
	}
    }
    ((XmPagerWidget)self)->xmPager.page[j] = -1;
    ((XmPagerWidget)self)->xmPager.pageno = 1;
}
#line 541 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 541 "XmPager.w"
static void scale_font(Widget self)
#else
#line 541 "XmPager.w"
static void scale_font(self)Widget self;
#endif
#line 542 "XmPager.w"
{
    Position x, y;
    Dimension w, h;
    int pixels;
    char s[250];
    XFontStruct *fs;
    String info[15];

    x = ((XmPagerWidget)self)->xmManager.shadow_thickness; y = ((XmPagerWidget)self)->xmManager.shadow_thickness;
    w = ((XmPagerWidget)self)->core.width - 2 * x; h = ((XmPagerWidget)self)->core.height - 2 * y;
    ((XmPagerWidget)self)->xmPager.baselineskip = (h - 50 - ((XmPagerWidget)self)->xmPager.margin) / ((XmPagerWidget)self)->xmPager.lines;
    if (((XmPagerWidget)self)->xmPager.roman_name == NULL			/* Font name is unknown */
	|| ! parse_font_name(((XmPagerWidget)self)->xmPager.roman_name, info)
	|| ! is_scalable_font(((XmPagerWidget)self)->xmPager.roman_name)) {
	((XmPagerWidget)self)->xmPager.baseline = ((XmPagerWidget)self)->xmPager.baselineskip / (float) (((XmPagerWidget)self)->xmPager.roman->ascent + ((XmPagerWidget)self)->xmPager.roman->descent);
        return;
    }

    pixels = ((XmPagerWidget)self)->xmPager.baselineskip/((XmPagerWidget)self)->xmPager.baseline;

    (void) sprintf(s, "-%s-%s-%s-%s-%s-%s-%d-*-%s-%s-%s-*-%s",
		   info[F_FOUNDRY], info[F_FAMILY], info[F_WEIGHT],
		   info[F_SLANT], info[F_SET_WIDTH], info[F_SANS],
		   pixels, info[F_HRESOLUTION], info[F_VRESOLUTION],
		   info[F_SPACING], info[F_CHARSET]);
    /* (void) fprintf(stderr, "scaled roman = %s\n", s); */
    if ((fs = XLoadQueryFont(XtDisplay(self), s)) != NULL) {
        XFreeFont(XtDisplay(self), ((XmPagerWidget)self)->xmPager.roman);
        ((XmPagerWidget)self)->xmPager.roman = fs;
        create_romangc(self);
    }

    XtFree(info[0]);
}
#line 577 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 577 "XmPager.w"
static void create_romangc(Widget self)
#else
#line 577 "XmPager.w"
static void create_romangc(self)Widget self;
#endif
#line 578 "XmPager.w"
{
    XGCValues val;
    XtGCMask mask = GCForeground | GCBackground | GCFont;

    if (((XmPagerWidget)self)->xmPager.romangc != NULL) XtReleaseGC(self, ((XmPagerWidget)self)->xmPager.romangc);
    val.foreground = ((XmPagerWidget)self)->xmManager.foreground;
    val.background = ((XmPagerWidget)self)->core.background_pixel;
    val.font = ((XmPagerWidget)self)->xmPager.roman->fid;
    ((XmPagerWidget)self)->xmPager.romangc = XtGetGC(self, mask, &val);
}
#line 597 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 597 "XmPager.w"
static Boolean  infer_roman(Widget self)
#else
#line 597 "XmPager.w"
static Boolean  infer_roman(self)Widget self;
#endif
#line 598 "XmPager.w"
{
    char **fonts;
    int n, i;

    XtFree(((XmPagerWidget)self)->xmPager.roman_name); ((XmPagerWidget)self)->xmPager.roman_name = NULL;
    if (((XmPagerWidget)self)->xmPager.fontFamily == NULL) return False;
    fonts = XListFonts(XtDisplay(self), ((XmPagerWidget)self)->xmPager.fontFamily, 1000, &n);
    if (n == 0) return False;
    for (i = 0; i < n; i++)
	if (strstr(fonts[i], "normal-r") || strstr(fonts[i], "medium-r")) {
	    ((XmPagerWidget)self)->xmPager.roman_name = XtNewString(fonts[i]);
	    break;
	}
    if (((XmPagerWidget)self)->xmPager.roman_name == NULL)
	for (i = 0; i < n; i++)
	    if (strstr(fonts[i], "-r-")) {
		((XmPagerWidget)self)->xmPager.roman_name = XtNewString(fonts[i]);
		break;
	    }
    if (((XmPagerWidget)self)->xmPager.roman_name == NULL)
	((XmPagerWidget)self)->xmPager.roman_name = XtNewString(fonts[0]);
    ((XmPagerWidget)self)->xmPager.roman = XLoadQueryFont(XtDisplay(self), ((XmPagerWidget)self)->xmPager.roman_name);
    XFreeFontNames(fonts);
    /* (void) fprintf(stderr, "roman name = %s\n", $roman_name); */
    return True;
}
#line 630 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 630 "XmPager.w"
static void guess_roman(Widget self,int  offset,XrmValue * value)
#else
#line 630 "XmPager.w"
static void guess_roman(self,offset,value)Widget self;int  offset;XrmValue * value;
#endif
#line 631 "XmPager.w"
{
    static XFontStruct *fixed;

    ((XmPagerWidget)self)->xmPager.roman_name = NULL;
    if (infer_roman(self))
	value->addr = (XtPointer) &((XmPagerWidget)self)->xmPager.roman;
    else {
	fixed = XLoadQueryFont(XtDisplay(self), "fixed");
	value->addr = (XtPointer) &fixed;
    }
}
#line 648 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 648 "XmPager.w"
static Boolean  is_scalable_font(String  name)
#else
#line 648 "XmPager.w"
static Boolean  is_scalable_font(name)String  name;
#endif
#line 649 "XmPager.w"
{
    int i, field;

    if (name == NULL || name[0] != '-') return False;
    for (i = field = 0; name[i] != '\0'; i++) {
	if (name[i] == '-') {
	    field++;
	    if (field == 7 || field == 8 || field == 12)
		if (name[i+1] != '0' || name[i+2] != '-')
		    return False;
	}
    }
    return (field == 14);
}
#line 670 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 670 "XmPager.w"
static Boolean  parse_font_name(String  name,String * table)
#else
#line 670 "XmPager.w"
static Boolean  parse_font_name(name,table)String  name;String * table;
#endif
#line 671 "XmPager.w"
{
    int i, field;

    if (name == NULL || name[0] != '-') return False;
    table[0] = XtNewString(name);
    for (i = field = 0; name[i] != '\0'; i++) {
	if (name[i] == '-') {
	    field++;
	    table[0][i] = '\0';
	    table[field] = &table[0][i+1];
	    if (field == 13) break;		/* No more fields */
	}
    }
    return True;
}
#line 691 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 691 "XmPager.w"
static void forward_CB(Widget  w,XtPointer  client_data,XtPointer  call_data)
#else
#line 691 "XmPager.w"
static void forward_CB(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
#endif
#line 692 "XmPager.w"
{
    Widget self = (Widget) client_data;

    if (((XmPagerWidget)self)->xmPager.page[((XmPagerWidget)self)->xmPager.pageno+1] >= 0) {
	((XmPagerWidget)self)->xmPager.pageno++;
	XClearWindow(XtDisplay(self), XtWindow(self));
	((XmPagerWidgetClass)self->core.widget_class)->core_class.expose(self, NULL, NULL);
    }
}
#line 706 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 706 "XmPager.w"
static void backwards_CB(Widget  w,XtPointer  client_data,XtPointer  call_data)
#else
#line 706 "XmPager.w"
static void backwards_CB(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
#endif
#line 707 "XmPager.w"
{
    Widget self = (Widget) client_data;

    if (((XmPagerWidget)self)->xmPager.pageno > 1) {
	((XmPagerWidget)self)->xmPager.pageno--;
	XClearWindow(XtDisplay(self), XtWindow(self));
	((XmPagerWidgetClass)self->core.widget_class)->core_class.expose(self, NULL, NULL);
    }
}

static XtResource resources[] = {
#line 36 "XmPager.w"
{XtNtext,XtCText,XtRString,sizeof(((XmPagerRec*)NULL)->xmPager.text),XtOffsetOf(XmPagerRec,xmPager.text),XtRImmediate,(XtPointer)NULL },
#line 43 "XmPager.w"
{XtNfontFamily,XtCFontFamily,XtRString,sizeof(((XmPagerRec*)NULL)->xmPager.fontFamily),XtOffsetOf(XmPagerRec,xmPager.fontFamily),XtRImmediate,(XtPointer)NULL },
#line 52 "XmPager.w"
{XtNroman,XtCRoman,XtRFontStruct,sizeof(((XmPagerRec*)NULL)->xmPager.roman),XtOffsetOf(XmPagerRec,xmPager.roman),XtRCallProc,(XtPointer)guess_roman },
#line 59 "XmPager.w"
{XtNlines,XtCLines,XtRInt,sizeof(((XmPagerRec*)NULL)->xmPager.lines),XtOffsetOf(XmPagerRec,xmPager.lines),XtRImmediate,(XtPointer)0 },
#line 66 "XmPager.w"
{XtNwrap,XtCWrap,XtRBoolean,sizeof(((XmPagerRec*)NULL)->xmPager.wrap),XtOffsetOf(XmPagerRec,xmPager.wrap),XtRImmediate,(XtPointer)False },
#line 77 "XmPager.w"
{XtNbaseline,XtCBaseline,XtRFloat,sizeof(((XmPagerRec*)NULL)->xmPager.baseline),XtOffsetOf(XmPagerRec,xmPager.baseline),XtRString,(XtPointer)"1.2"},
#line 82 "XmPager.w"
{XtNmargin,XtCMargin,XtRInt,sizeof(((XmPagerRec*)NULL)->xmPager.margin),XtOffsetOf(XmPagerRec,xmPager.margin),XtRImmediate,(XtPointer)5 },
#line 87 "XmPager.w"
{XtNtablist,XtCTablist,XtRString,sizeof(((XmPagerRec*)NULL)->xmPager.tablist),XtOffsetOf(XmPagerRec,xmPager.tablist),XtRImmediate,(XtPointer)"8 16 24 32 40 48 56 64 72 80 88 96 104 112 120 128 136 144 152 160"},
};

XmPagerClassRec xmPagerClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xmManagerClassRec,
/* class_name   	*/  "XmPager",
/* widget_size  	*/  sizeof(XmPagerRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  realize,
/* actions      	*/  actionsList,
/* num_actions  	*/  2,
/* resources    	*/  resources,
/* num_resources 	*/  8,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple ,
/* compress_enterleave 	*/  True ,
/* visible_interest 	*/  False ,
/* destroy      	*/  NULL,
/* resize       	*/  resize,
/* expose       	*/  expose,
/* set_values   	*/  set_values,
/* set_values_hook 	*/  NULL,
/* set_values_almost 	*/  XtInheritSetValuesAlmost,
/* get_values+hook 	*/  NULL,
/* accept_focus 	*/  XtInheritAcceptFocus,
/* version      	*/  XtVersion,
/* callback_private 	*/  NULL,
/* tm_table      	*/  defaultTranslations,
/* query_geometry 	*/  query_geometry,
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
{ /* constraint_class part */
/* constraint_resources     */  NULL,
/* num_constraint_resources */  0,
/* constraint_size          */  sizeof(XmPagerConstraintRec),
/* constraint_initialize    */  NULL,
/* constraint_destroy       */  NULL,
/* constraint_set_values    */  NULL,
/* constraint_extension     */  NULL 
},
{ /* XmManager class part */
#define manager_extension extension
/* translations                 */  XtInheritTranslations ,
/* syn_resources                */  NULL ,
/* num_syn_resources            */  0 ,
/* syn_constraint_resources     */  NULL ,
/* num_syn_constraint_resources */  0 ,
/* parent_process               */  XmInheritParentProcess,
/* manager_extension            */  NULL ,
},
{ /* XmPager_class part */
 /* dummy */  0
},
};
WidgetClass xmPagerWidgetClass = (WidgetClass) &xmPagerClassRec;
/*ARGSUSED*/
#line 392 "XmPager.w"
static void previous_page(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    backwards_CB(self, self, NULL);
}

/*ARGSUSED*/
#line 397 "XmPager.w"
static void next_page(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    forward_CB(self, self, NULL);
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XmPagerWidgetClass c = (XmPagerWidgetClass) class;
  XmPagerWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xmPagerWidgetClass) return;
  super = (XmPagerWidgetClass)class->core_class.superclass;
}
#line 168 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 168 "XmPager.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 168 "XmPager.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 169 "XmPager.w"
{
    int status;
    static char trans[] = "<Btn1Down>,<Btn1Up>: activate()";

    ((XmPagerWidget)self)->xmPager.tabs = XfwfTablist2Tabs(((XmPagerWidget)self)->xmPager.tablist);

    ((XmPagerWidget)self)->xmPager.f_back.attributes.valuemask = XpmSize;
    status = XpmCreatePixmapFromData
	(XtDisplay(self), DefaultRootWindow(XtDisplay(self)), flip_back,
	 &((XmPagerWidget)self)->xmPager.f_back.pixmap, &((XmPagerWidget)self)->xmPager.f_back.mask, &((XmPagerWidget)self)->xmPager.f_back.attributes);
    switch (status) {
    case XpmNoMemory: XtAppError(XtWidgetToApplicationContext(self),
				 "Out of memory");
    case XpmColorFailed: XtAppError(XtWidgetToApplicationContext(self),
				    "Failed to allocate color for pixmap");
    case XpmColorError: XtAppWarning(XtWidgetToApplicationContext(self),
				     "Not all pixmap colors found");
    default: ; /* skip */
    }
    ((XmPagerWidget)self)->xmPager.flip_back = XtVaCreateManagedWidget
	("_flip_back", xmIconWidgetClass, self,
	 XtNimage, &((XmPagerWidget)self)->xmPager.f_back,
	 XmNhighlightThickness, 0, XmNtraversalOn, False,
	 XtVaTypedArg, XtNtranslations, XtRString, trans,
	 strlen(trans)+1, NULL);
    XtMoveWidget(((XmPagerWidget)self)->xmPager.flip_back, ((XmPagerWidget)self)->core.width - ((XmPagerWidget)self)->xmPager.f_back.attributes.width,
		 ((XmPagerWidget)self)->core.height - ((XmPagerWidget)self)->xmPager.f_back.attributes.height);
    XtAddCallback(((XmPagerWidget)self)->xmPager.flip_back, XtNactivate, backwards_CB, self);

    ((XmPagerWidget)self)->xmPager.f_forward.attributes.valuemask = XpmSize;
    status = XpmCreatePixmapFromData
	(XtDisplay(self), DefaultRootWindow(XtDisplay(self)), flip_forward,
	 &((XmPagerWidget)self)->xmPager.f_forward.pixmap, &((XmPagerWidget)self)->xmPager.f_forward.mask, &((XmPagerWidget)self)->xmPager.f_forward.attributes);
    switch (status) {
    case XpmNoMemory: XtAppError(XtWidgetToApplicationContext(self),
				 "Out of memory");
    case XpmColorFailed: XtAppError(XtWidgetToApplicationContext(self),
				    "Failed to allocate color for pixmap");
    case XpmColorError: XtAppWarning(XtWidgetToApplicationContext(self),
				     "Not all pixmap colors found");
    default: ; /* skip */
    }
    ((XmPagerWidget)self)->xmPager.flip_forward = XtVaCreateManagedWidget
	("_flip_forward", xmIconWidgetClass, self,
	 XtNimage, &((XmPagerWidget)self)->xmPager.f_forward,
	 XmNhighlightThickness, 0, XmNtraversalOn, False,
	 XtVaTypedArg, XtNtranslations, XtRString, trans,
	 strlen(trans)+1, NULL);
    XtMoveWidget(((XmPagerWidget)self)->xmPager.flip_forward, ((XmPagerWidget)self)->core.width - ((XmPagerWidget)self)->xmPager.f_forward.attributes.width,
		 ((XmPagerWidget)self)->core.height - ((XmPagerWidget)self)->xmPager.f_forward.attributes.height);
    XtAddCallback(((XmPagerWidget)self)->xmPager.flip_forward, XtNactivate, forward_CB, self);

    create_romangc(self);
    ((XmPagerWidget)self)->xmPager.baselineskip = 0.5 + ((XmPagerWidget)self)->xmPager.baseline * (((XmPagerWidget)self)->xmPager.roman->ascent + ((XmPagerWidget)self)->xmPager.roman->descent);
    ((XmPagerWidget)self)->xmPager.text = XtNewString(((XmPagerWidget)self)->xmPager.text);
    ((XmPagerWidget)self)->xmPager.fontFamily = XtNewString(((XmPagerWidget)self)->xmPager.fontFamily);
    ((XmPagerWidget)self)->xmPager.tablist = XtNewString(((XmPagerWidget)self)->xmPager.tablist);
    ((XmPagerWidget)self)->xmPager.fulltext = NULL;
    ((XmPagerWidget)self)->xmPager.page = NULL;
    init_text(self);
    split_text(self);
    if (((XmPagerWidget)self)->xmPager.lines > 0) scale_font(self);
}
#line 240 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 240 "XmPager.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 240 "XmPager.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 241 "XmPager.w"
{
    Boolean need_redisplay = False;

    if (((XmPagerWidget)self)->xmPager.tablist != ((XmPagerWidget)old)->xmPager.tablist) {
	XtFree(((XmPagerWidget)old)->xmPager.tablist);
	XtFree((String) ((XmPagerWidget)old)->xmPager.tabs);
	((XmPagerWidget)self)->xmPager.tablist = XtNewString(((XmPagerWidget)self)->xmPager.tablist);
	((XmPagerWidget)self)->xmPager.tabs = XfwfTablist2Tabs(((XmPagerWidget)self)->xmPager.tablist);
	need_redisplay = True;
    }
    if (((XmPagerWidget)old)->xmPager.fontFamily != ((XmPagerWidget)self)->xmPager.fontFamily) {
	XtFree(((XmPagerWidget)old)->xmPager.fontFamily);
	((XmPagerWidget)self)->xmPager.fontFamily = XtNewString(((XmPagerWidget)self)->xmPager.fontFamily);
	XFreeFont(XtDisplay(self), ((XmPagerWidget)self)->xmPager.roman);
	(void) infer_roman(self);
    }
    if (((XmPagerWidget)old)->xmPager.text != ((XmPagerWidget)self)->xmPager.text) {
	XtFree(((XmPagerWidget)old)->xmPager.text);
	((XmPagerWidget)self)->xmPager.text = XtNewString(((XmPagerWidget)self)->xmPager.text);
	init_text(self);
	split_text(self);
	need_redisplay = True;
    }
    if (((XmPagerWidget)old)->xmPager.roman != ((XmPagerWidget)self)->xmPager.roman
	|| ((XmPagerWidget)old)->xmPager.lines != ((XmPagerWidget)self)->xmPager.lines
	|| ((XmPagerWidget)old)->xmPager.wrap != ((XmPagerWidget)self)->xmPager.wrap
	|| ((XmPagerWidget)old)->xmPager.baseline != ((XmPagerWidget)self)->xmPager.baseline
	|| (((XmPagerWidget)old)->core.width != ((XmPagerWidget)self)->core.width && ((XmPagerWidget)self)->xmPager.lines == 0)
	|| (((XmPagerWidget)old)->core.height != ((XmPagerWidget)self)->core.height && ((XmPagerWidget)self)->xmPager.lines == 0)) {
	split_text(self);
	need_redisplay = True;
    }
    if (((XmPagerWidget)old)->core.height != ((XmPagerWidget)self)->core.height && ((XmPagerWidget)self)->xmPager.lines > 0) {
	scale_font(self);
	need_redisplay = True;
    }
    return need_redisplay;
}
#line 284 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 284 "XmPager.w"
static void resize(Widget self)
#else
#line 284 "XmPager.w"
static void resize(self)Widget self;
#endif
#line 285 "XmPager.w"
{
    if (xmManagerClassRec.core_class.resize) xmManagerClassRec.core_class.resize(self);
    if (((XmPagerWidget)self)->xmPager.lines > 0) scale_font(self); else split_text(self);
    XtMoveWidget(((XmPagerWidget)self)->xmPager.flip_back, ((XmPagerWidget)self)->core.width - ((XmPagerWidget)self)->xmPager.f_back.attributes.width,
		 ((XmPagerWidget)self)->core.height - ((XmPagerWidget)self)->xmPager.f_back.attributes.height);
    XtMoveWidget(((XmPagerWidget)self)->xmPager.flip_forward, ((XmPagerWidget)self)->core.width - ((XmPagerWidget)self)->xmPager.f_forward.attributes.width,
		 ((XmPagerWidget)self)->core.height - ((XmPagerWidget)self)->xmPager.f_forward.attributes.height);
    if (XtIsRealized(self))
	XClearArea(XtDisplay(self), XtWindow(self), 0, 0, 0, 0, TRUE);
}
#line 302 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 302 "XmPager.w"
static void realize(Widget self,XtValueMask * mask,XSetWindowAttributes * attributes)
#else
#line 302 "XmPager.w"
static void realize(self,mask,attributes)Widget self;XtValueMask * mask;XSetWindowAttributes * attributes;
#endif
#line 303 "XmPager.w"
{
    *mask |= CWBitGravity;
    attributes->bit_gravity = ForgetGravity;
    xmManagerClassRec.core_class.realize(self, mask, attributes);
}
#line 328 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 328 "XmPager.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 328 "XmPager.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 329 "XmPager.w"
{
    Region reg;
    XRectangle rect;
    Position y;
    char *p, *q, h[20];
    Display *dpy = XtDisplay(self);
    Window win = XtWindow(self);

    if (! XtIsRealized(self)) return;
    if (! ((XmPagerWidget)self)->xmPager.fulltext) {
	if (xmManagerClassRec.core_class.expose) xmManagerClassRec.core_class.expose(self, event, region);
	return;
    }
    rect.x = ((XmPagerWidget)self)->xmManager.shadow_thickness;
    rect.y = ((XmPagerWidget)self)->xmManager.shadow_thickness;
    rect.width = ((XmPagerWidget)self)->core.width - 2 * rect.x;
    rect.height = ((XmPagerWidget)self)->core.height - 2 * rect.y;
    reg = XCreateRegion();
    XUnionRectWithRegion(&rect, reg, reg);
    if (region) XIntersectRegion(reg, region, reg);
    XSetRegion(dpy, ((XmPagerWidget)self)->xmPager.romangc, reg);
    y = ((XmPagerWidget)self)->xmPager.margin + ((XmPagerWidget)self)->xmPager.baselineskip - ((XmPagerWidget)self)->xmPager.roman->descent;
    if (((XmPagerWidget)self)->xmPager.wrap) {
        /* wrapping mode not implemented yet */
    } else {
        p = ((XmPagerWidget)self)->xmPager.fulltext + ((XmPagerWidget)self)->xmPager.page[((XmPagerWidget)self)->xmPager.pageno];
        for (;;) {
            if (y + ((XmPagerWidget)self)->xmPager.roman->descent >= rect.y + rect.height - 50) break;
            for (q = p; *q != '\0' && *q != '\n' && *q != '\f'; q++) ;
            XfwfDrawImageString(dpy, win, ((XmPagerWidget)self)->xmPager.romangc, rect.x+((XmPagerWidget)self)->xmPager.margin, y,
				p, q - p, ((XmPagerWidget)self)->xmPager.tabs);
            if (*q == '\0' || *q == '\f') break;
            y += ((XmPagerWidget)self)->xmPager.baselineskip;
            p = q + 1;
        }
    }
    /* Draw page number */
    sprintf(h, "%d", ((XmPagerWidget)self)->xmPager.pageno);
    XfwfDrawImageString(dpy, win, ((XmPagerWidget)self)->xmPager.romangc, rect.x + rect.width/2, rect.y +
		     rect.height - ((XmPagerWidget)self)->xmPager.roman->descent, h, strlen(h), ((XmPagerWidget)self)->xmPager.tabs);

    XSetClipMask(dpy, ((XmPagerWidget)self)->xmPager.romangc, None);
    if (xmManagerClassRec.core_class.expose) xmManagerClassRec.core_class.expose(self, event, region);
}
#line 374 "XmPager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 374 "XmPager.w"
static XtGeometryResult  query_geometry(Widget self,XtWidgetGeometry * request,XtWidgetGeometry * reply)
#else
#line 374 "XmPager.w"
static XtGeometryResult  query_geometry(self,request,reply)Widget self;XtWidgetGeometry * request;XtWidgetGeometry * reply;
#endif
#line 375 "XmPager.w"
{
    return XtGeometryYes;
}
