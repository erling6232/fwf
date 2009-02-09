/* Generated by wbuild from "Pager.w"
** (generator version $Revision$ of $Date$)
*/
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 683 "Pager.w"
#include "flip_back.xpm"
#line 684 "Pager.w"
#include "flip_forward.xpm"
#line 685 "Pager.w"
#include <Xfwf/Icon.h>
#line 686 "Pager.w"
#include <stdlib.h>
#line 687 "Pager.w"
#include <fcntl.h>
#line 688 "Pager.w"
#include <stdio.h>
#line 689 "Pager.w"
#include <Xfwf/TabString.h>
#line 690 "Pager.w"
#include <X11/Xmu/Converters.h>
#include <Xfwf/PagerP.h>
#line 356 "Pager.w"
static void previous_page(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 361 "Pager.w"
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
#line 170 "Pager.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 232 "Pager.w"
static Boolean  set_values(
#if NeedFunctionPrototypes
Widget ,Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 276 "Pager.w"
static void resize(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 302 "Pager.w"
static void expose(
#if NeedFunctionPrototypes
Widget,XEvent *,Region 
#endif
);
#line 372 "Pager.w"
#define INCREMENT 2048 


#line 373 "Pager.w"
#define mrealloc(ptr, size) (void *)XtRealloc ((char *)ptr ,size )


#line 375 "Pager.w"
static void read_from_file(
#if NeedFunctionPrototypes
Widget,String 
#endif
);
#line 396 "Pager.w"
static void read_from_pipe(
#if NeedFunctionPrototypes
Widget,String 
#endif
);
#line 419 "Pager.w"
static void init_text(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 440 "Pager.w"
static void split_text(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 490 "Pager.w"
#define F_FOUNDRY 1 


#line 491 "Pager.w"
#define F_FAMILY 2 


#line 492 "Pager.w"
#define F_WEIGHT 3 


#line 493 "Pager.w"
#define F_SLANT 4 


#line 494 "Pager.w"
#define F_SET_WIDTH 5 


#line 495 "Pager.w"
#define F_SANS 6 


#line 496 "Pager.w"
#define F_PIXELS 7 


#line 497 "Pager.w"
#define F_POINTS 8 


#line 498 "Pager.w"
#define F_HRESOLUTION 9 


#line 499 "Pager.w"
#define F_VRESOLUTION 10 


#line 500 "Pager.w"
#define F_SPACING 11 


#line 501 "Pager.w"
#define F_AVG_WITH 12 


#line 502 "Pager.w"
#define F_CHARSET 13 


#line 504 "Pager.w"
static void scale_font(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 539 "Pager.w"
static void create_romangc(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 559 "Pager.w"
static Boolean  infer_roman(
#if NeedFunctionPrototypes
Widget
#endif
);
#line 592 "Pager.w"
static void guess_roman(
#if NeedFunctionPrototypes
Widget,int ,XrmValue *
#endif
);
#line 610 "Pager.w"
static Boolean  is_scalable_font(
#if NeedFunctionPrototypes
String 
#endif
);
#line 632 "Pager.w"
static Boolean  parse_font_name(
#if NeedFunctionPrototypes
String ,String *
#endif
);
#line 653 "Pager.w"
static void forward_CB(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 668 "Pager.w"
static void backwards_CB(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 375 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 375 "Pager.w"
static void read_from_file(Widget self,String  filename)
#else
#line 375 "Pager.w"
static void read_from_file(self,filename)Widget self;String  filename;
#endif
#line 376 "Pager.w"
{
    int fd, len = 0, nbytes;

    if ((fd = open(filename, O_RDONLY)) < 0) {
	perror(filename);
	return;
    }
    do {
	((XfwfPagerWidget)self)->xfwfPager.fulltext = mrealloc(((XfwfPagerWidget)self)->xfwfPager.fulltext, len + INCREMENT + 1);
	nbytes = read(fd, ((XfwfPagerWidget)self)->xfwfPager.fulltext + len, INCREMENT);
	if (nbytes < 0) perror(filename); else len += nbytes;
    } while (nbytes > 0);
    ((XfwfPagerWidget)self)->xfwfPager.fulltext[len] = '\0';
    (void) close(fd);
}
#line 396 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 396 "Pager.w"
static void read_from_pipe(Widget self,String  cmd)
#else
#line 396 "Pager.w"
static void read_from_pipe(self,cmd)Widget self;String  cmd;
#endif
#line 397 "Pager.w"
{
    int len = 0, nbytes;
    FILE *stream;

    if ((stream = popen(cmd, "r")) == NULL) {
	perror(cmd);
	return;
    }
    do {
	((XfwfPagerWidget)self)->xfwfPager.fulltext = mrealloc(((XfwfPagerWidget)self)->xfwfPager.fulltext, sizeof(char) * (len + INCREMENT + 1));
	nbytes = fread(((XfwfPagerWidget)self)->xfwfPager.fulltext + len, sizeof(char), INCREMENT, stream);
	if (nbytes < 0) perror(cmd); else len += nbytes;
    } while (nbytes > 0);
    ((XfwfPagerWidget)self)->xfwfPager.fulltext[len] = '\0';
    (void) pclose(stream);
}
#line 419 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 419 "Pager.w"
static void init_text(Widget self)
#else
#line 419 "Pager.w"
static void init_text(self)Widget self;
#endif
#line 420 "Pager.w"
{
    XtFree(((XfwfPagerWidget)self)->xfwfPager.fulltext); ((XfwfPagerWidget)self)->xfwfPager.fulltext = NULL;
    XtFree((char*) ((XfwfPagerWidget)self)->xfwfPager.page); ((XfwfPagerWidget)self)->xfwfPager.page = NULL;
    if (((XfwfPagerWidget)self)->xfwfPager.text == NULL) return;
    /*
     * Initialize $fulltext
     */
    switch (((XfwfPagerWidget)self)->xfwfPager.text[0]) {
    case '@': read_from_file(self, ((XfwfPagerWidget)self)->xfwfPager.text + 1); break;
    case '`': read_from_pipe(self, ((XfwfPagerWidget)self)->xfwfPager.text + 1); break;
    default: ((XfwfPagerWidget)self)->xfwfPager.fulltext = XtNewString(((XfwfPagerWidget)self)->xfwfPager.text);
    }
}
#line 440 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 440 "Pager.w"
static void split_text(Widget self)
#else
#line 440 "Pager.w"
static void split_text(self)Widget self;
#endif
#line 441 "Pager.w"
{
    int i, j, n, h;
    Position x, y;
    Dimension wd, ht;
    char prev = '\0';

    ((XfwfPagerWidget)self)->xfwfPager.page = mrealloc(((XfwfPagerWidget)self)->xfwfPager.page, 3 * sizeof(((XfwfPagerWidget)self)->xfwfPager.page[0]));
    ((XfwfPagerWidget)self)->xfwfPager.page[1] = 0;
    j = 2;
    /* Wrapping is not implemented yet */
    if (((XfwfPagerWidget)self)->xfwfPager.lines > 0 && ((XfwfPagerWidget)self)->xfwfPager.fulltext != NULL) {
	/* Count lines until n == $lines */
	n = 0;
	for (i = 0; ((XfwfPagerWidget)self)->xfwfPager.fulltext[i]; prev = ((XfwfPagerWidget)self)->xfwfPager.fulltext[i], i++) {
	    if (prev == '\n') {
		n++;
		if (n == ((XfwfPagerWidget)self)->xfwfPager.lines) {
		    ((XfwfPagerWidget)self)->xfwfPager.page = mrealloc(((XfwfPagerWidget)self)->xfwfPager.page, (j+2) * sizeof(((XfwfPagerWidget)self)->xfwfPager.page[0]));
		    ((XfwfPagerWidget)self)->xfwfPager.page[j++] = i;
		    n = 0;
		}
	    }
	}
    } else if (((XfwfPagerWidget)self)->xfwfPager.fulltext != NULL) {
	/* Determine page length with actual height of the text */
	((XfwfPagerWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &wd, &ht);
	h = y + ((XfwfPagerWidget)self)->xfwfPager.margin + ((XfwfPagerWidget)self)->xfwfPager.baselineskip;
	ht = y + ht - 50;
	for (i = 0; ((XfwfPagerWidget)self)->xfwfPager.fulltext[i]; prev = ((XfwfPagerWidget)self)->xfwfPager.fulltext[i], i++) {
	    if (prev == '\n') {
		h += ((XfwfPagerWidget)self)->xfwfPager.baselineskip;
		if (h + ((XfwfPagerWidget)self)->xfwfPager.roman->descent >= ht) {
		    ((XfwfPagerWidget)self)->xfwfPager.page[j++] = i;
		    h = y + ((XfwfPagerWidget)self)->xfwfPager.margin + ((XfwfPagerWidget)self)->xfwfPager.baselineskip;
		}
	    }
	}
    }
    ((XfwfPagerWidget)self)->xfwfPager.page[j] = -1;
    ((XfwfPagerWidget)self)->xfwfPager.pageno = 1;
}
#line 504 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 504 "Pager.w"
static void scale_font(Widget self)
#else
#line 504 "Pager.w"
static void scale_font(self)Widget self;
#endif
#line 505 "Pager.w"
{
    Position x, y;
    Dimension w, h;
    int pixels;
    char s[250];
    XFontStruct *fs;
    String info[15];

    ((XfwfPagerWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &x, &y, &w, &h);
    ((XfwfPagerWidget)self)->xfwfPager.baselineskip = (h - 50 - ((XfwfPagerWidget)self)->xfwfPager.margin) / ((XfwfPagerWidget)self)->xfwfPager.lines;
    if (((XfwfPagerWidget)self)->xfwfPager.roman_name == NULL			/* Font name is unknown */
	|| ! parse_font_name(((XfwfPagerWidget)self)->xfwfPager.roman_name, info)
	|| ! is_scalable_font(((XfwfPagerWidget)self)->xfwfPager.roman_name)) {
	((XfwfPagerWidget)self)->xfwfPager.baseline = ((XfwfPagerWidget)self)->xfwfPager.baselineskip / (float) (((XfwfPagerWidget)self)->xfwfPager.roman->ascent + ((XfwfPagerWidget)self)->xfwfPager.roman->descent);
        return;
    }

    pixels = ((XfwfPagerWidget)self)->xfwfPager.baselineskip/((XfwfPagerWidget)self)->xfwfPager.baseline;

    (void) sprintf(s, "-%s-%s-%s-%s-%s-%s-%d-*-%s-%s-%s-*-%s",
		   info[F_FOUNDRY], info[F_FAMILY], info[F_WEIGHT],
		   info[F_SLANT], info[F_SET_WIDTH], info[F_SANS],
		   pixels, info[F_HRESOLUTION], info[F_VRESOLUTION],
		   info[F_SPACING], info[F_CHARSET]);
    /* (void) fprintf(stderr, "scaled roman = %s\n", s); */
    if ((fs = XLoadQueryFont(XtDisplay(self), s)) != NULL) {
        XFreeFont(XtDisplay(self), ((XfwfPagerWidget)self)->xfwfPager.roman);
        ((XfwfPagerWidget)self)->xfwfPager.roman = fs;
        create_romangc(self);
    }

    XtFree(info[0]);
}
#line 539 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 539 "Pager.w"
static void create_romangc(Widget self)
#else
#line 539 "Pager.w"
static void create_romangc(self)Widget self;
#endif
#line 540 "Pager.w"
{
    XGCValues val;
    XtGCMask mask = GCForeground | GCBackground | GCFont;

    if (((XfwfPagerWidget)self)->xfwfPager.romangc != NULL) XtReleaseGC(self, ((XfwfPagerWidget)self)->xfwfPager.romangc);
    val.foreground = ((XfwfPagerWidget)self)->xfwfPager.foreground;
    val.background = ((XfwfPagerWidget)self)->core.background_pixel;
    val.font = ((XfwfPagerWidget)self)->xfwfPager.roman->fid;
    ((XfwfPagerWidget)self)->xfwfPager.romangc = XtGetGC(self, mask, &val);
}
#line 559 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 559 "Pager.w"
static Boolean  infer_roman(Widget self)
#else
#line 559 "Pager.w"
static Boolean  infer_roman(self)Widget self;
#endif
#line 560 "Pager.w"
{
    char **fonts;
    int n, i;

    XtFree(((XfwfPagerWidget)self)->xfwfPager.roman_name); ((XfwfPagerWidget)self)->xfwfPager.roman_name = NULL;
    if (((XfwfPagerWidget)self)->xfwfPager.fontFamily == NULL) return False;
    fonts = XListFonts(XtDisplay(self), ((XfwfPagerWidget)self)->xfwfPager.fontFamily, 1000, &n);
    if (n == 0) return False;
    for (i = 0; i < n; i++)
	if (strstr(fonts[i], "normal-r") || strstr(fonts[i], "medium-r")) {
	    ((XfwfPagerWidget)self)->xfwfPager.roman_name = XtNewString(fonts[i]);
	    break;
	}
    if (((XfwfPagerWidget)self)->xfwfPager.roman_name == NULL)
	for (i = 0; i < n; i++)
	    if (strstr(fonts[i], "-r-")) {
		((XfwfPagerWidget)self)->xfwfPager.roman_name = XtNewString(fonts[i]);
		break;
	    }
    if (((XfwfPagerWidget)self)->xfwfPager.roman_name == NULL)
	((XfwfPagerWidget)self)->xfwfPager.roman_name = XtNewString(fonts[0]);
    ((XfwfPagerWidget)self)->xfwfPager.roman = XLoadQueryFont(XtDisplay(self), ((XfwfPagerWidget)self)->xfwfPager.roman_name);
    XFreeFontNames(fonts);
    /* (void) fprintf(stderr, "roman name = %s\n", $roman_name); */
    return True;
}
#line 592 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 592 "Pager.w"
static void guess_roman(Widget self,int  offset,XrmValue * value)
#else
#line 592 "Pager.w"
static void guess_roman(self,offset,value)Widget self;int  offset;XrmValue * value;
#endif
#line 593 "Pager.w"
{
    static XFontStruct *fixed;

    ((XfwfPagerWidget)self)->xfwfPager.roman_name = NULL;
    if (infer_roman(self))
	value->addr = (XtPointer) &((XfwfPagerWidget)self)->xfwfPager.roman;
    else {
	fixed = XLoadQueryFont(XtDisplay(self), "fixed");
	value->addr = (XtPointer) &fixed;
    }
}
#line 610 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 610 "Pager.w"
static Boolean  is_scalable_font(String  name)
#else
#line 610 "Pager.w"
static Boolean  is_scalable_font(name)String  name;
#endif
#line 611 "Pager.w"
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
#line 632 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 632 "Pager.w"
static Boolean  parse_font_name(String  name,String * table)
#else
#line 632 "Pager.w"
static Boolean  parse_font_name(name,table)String  name;String * table;
#endif
#line 633 "Pager.w"
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
#line 653 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 653 "Pager.w"
static void forward_CB(Widget  w,XtPointer  client_data,XtPointer  call_data)
#else
#line 653 "Pager.w"
static void forward_CB(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
#endif
#line 654 "Pager.w"
{
    Widget self = (Widget) client_data;

    if (((XfwfPagerWidget)self)->xfwfPager.page[((XfwfPagerWidget)self)->xfwfPager.pageno+1] >= 0) {
	((XfwfPagerWidget)self)->xfwfPager.pageno++;
	XClearWindow(XtDisplay(self), XtWindow(self));
	((XfwfPagerWidgetClass)self->core.widget_class)->core_class.expose(self, NULL, NULL);
    }
}
#line 668 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 668 "Pager.w"
static void backwards_CB(Widget  w,XtPointer  client_data,XtPointer  call_data)
#else
#line 668 "Pager.w"
static void backwards_CB(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
#endif
#line 669 "Pager.w"
{
    Widget self = (Widget) client_data;

    if (((XfwfPagerWidget)self)->xfwfPager.pageno > 1) {
	((XfwfPagerWidget)self)->xfwfPager.pageno--;
	XClearWindow(XtDisplay(self), XtWindow(self));
	((XfwfPagerWidgetClass)self->core.widget_class)->core_class.expose(self, NULL, NULL);
    }
}

static XtResource resources[] = {
#line 35 "Pager.w"
{XtNtext,XtCText,XtRString,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.text),XtOffsetOf(XfwfPagerRec,xfwfPager.text),XtRImmediate,(XtPointer)NULL },
#line 42 "Pager.w"
{XtNfontFamily,XtCFontFamily,XtRString,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.fontFamily),XtOffsetOf(XfwfPagerRec,xfwfPager.fontFamily),XtRImmediate,(XtPointer)NULL },
#line 51 "Pager.w"
{XtNroman,XtCRoman,XtRFontStruct,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.roman),XtOffsetOf(XfwfPagerRec,xfwfPager.roman),XtRCallProc,(XtPointer)guess_roman },
#line 58 "Pager.w"
{XtNlines,XtCLines,XtRInt,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.lines),XtOffsetOf(XfwfPagerRec,xfwfPager.lines),XtRImmediate,(XtPointer)0 },
#line 65 "Pager.w"
{XtNwrap,XtCWrap,XtRBoolean,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.wrap),XtOffsetOf(XfwfPagerRec,xfwfPager.wrap),XtRImmediate,(XtPointer)False },
#line 76 "Pager.w"
{XtNbaseline,XtCBaseline,XtRFloat,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.baseline),XtOffsetOf(XfwfPagerRec,xfwfPager.baseline),XtRString,(XtPointer)"1.2"},
#line 81 "Pager.w"
{XtNmargin,XtCMargin,XtRInt,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.margin),XtOffsetOf(XfwfPagerRec,xfwfPager.margin),XtRImmediate,(XtPointer)5 ;},
#line 86 "Pager.w"
{XtNtablist,XtCTablist,XtRString,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.tablist),XtOffsetOf(XfwfPagerRec,xfwfPager.tablist),XtRImmediate,(XtPointer)NULL },
#line 91 "Pager.w"
{XtNforeground,XtCForeground,XtRPixel,sizeof(((XfwfPagerRec*)NULL)->xfwfPager.foreground),XtOffsetOf(XfwfPagerRec,xfwfPager.foreground),XtRString,(XtPointer)"black"},
#line 97 "Pager.w"
{XtNbackground,XtCBackground,XtRPixel,sizeof(((XfwfPagerRec*)NULL)->core.background_pixel),XtOffsetOf(XfwfPagerRec,core.background_pixel),XtRString,(XtPointer)"white"},
#line 101 "Pager.w"
{XtNframeType,XtCFrameType,XtRFrameType,sizeof(((XfwfPagerRec*)NULL)->xfwfFrame.frameType),XtOffsetOf(XfwfPagerRec,xfwfFrame.frameType),XtRImmediate,(XtPointer)XfwfSunken },
};

XfwfPagerClassRec xfwfPagerClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &xfwfBoardClassRec,
/* class_name   	*/  "XfwfPager",
/* widget_size  	*/  sizeof(XfwfPagerRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  XtInheritRealize,
/* actions      	*/  actionsList,
/* num_actions  	*/  2,
/* resources    	*/  resources,
/* num_resources 	*/  11,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  True ,
/* compress_exposure 	*/  XtExposeCompressMultiple ,
/* compress_enterleave 	*/  True ,
/* visible_interest 	*/  TRUE ,
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
{ /* XfwfPager_class part */
 /* dummy */  0
},
};
WidgetClass xfwfPagerWidgetClass = (WidgetClass) &xfwfPagerClassRec;
/*ARGSUSED*/
#line 356 "Pager.w"
static void previous_page(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    backwards_CB(self, self, NULL);
}

/*ARGSUSED*/
#line 361 "Pager.w"
static void next_page(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    forward_CB(self, self, NULL);
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfPagerWidgetClass c = (XfwfPagerWidgetClass) class;
  XfwfPagerWidgetClass super;
  static CompositeClassExtensionRec extension_rec = {
    NULL, NULLQUARK, XtCompositeExtensionVersion,
    sizeof(CompositeClassExtensionRec), True};
  CompositeClassExtensionRec *ext;
  ext = (XtPointer)XtMalloc(sizeof(*ext));
  *ext = extension_rec;
  ext->next_extension = c->composite_class.extension;
  c->composite_class.extension = ext;
  if (class == xfwfPagerWidgetClass) return;
  super = (XfwfPagerWidgetClass)class->core_class.superclass;
}
#line 170 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 170 "Pager.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 170 "Pager.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 171 "Pager.w"
{
    int status;
    static char trans[] = "<Btn1Down>,<Btn1Up>: activate()";

    ((XfwfPagerWidget)self)->xfwfPager.tabs = XfwfTablist2Tabs(((XfwfPagerWidget)self)->xfwfPager.tablist);

    ((XfwfPagerWidget)self)->xfwfPager.f_back.attributes.valuemask = XpmSize;
    status = XpmCreatePixmapFromData
	(XtDisplay(self), DefaultRootWindow(XtDisplay(self)), flip_back,
	 &((XfwfPagerWidget)self)->xfwfPager.f_back.pixmap, &((XfwfPagerWidget)self)->xfwfPager.f_back.mask, &((XfwfPagerWidget)self)->xfwfPager.f_back.attributes);
    switch (status) {
    case XpmNoMemory: XtError("Out of memory");
    case XpmColorFailed: XtError("Failed to allocate color for pixmap");
    case XpmColorError: XtWarning("Not all pixmap colors found");
    default: ; /* skip */
    }
    ((XfwfPagerWidget)self)->xfwfPager.flip_back = XtVaCreateManagedWidget
	("_flip_back", xfwfIconWidgetClass, self,
	 XtNlocation, "1.0-50 1.0-50 50 50", XtNimage, &((XfwfPagerWidget)self)->xfwfPager.f_back,
	 XtNhighlightThickness, 0, XtNtraversalOn, False,
	 XtVaTypedArg, XtNtranslations, XtRString, trans,
	 strlen(trans)+1, NULL);
    XtAddCallback(((XfwfPagerWidget)self)->xfwfPager.flip_back, XtNactivate, backwards_CB, self);

    ((XfwfPagerWidget)self)->xfwfPager.f_forward.attributes.valuemask = XpmSize;
    status = XpmCreatePixmapFromData
	(XtDisplay(self), DefaultRootWindow(XtDisplay(self)), flip_forward,
	 &((XfwfPagerWidget)self)->xfwfPager.f_forward.pixmap, &((XfwfPagerWidget)self)->xfwfPager.f_forward.mask, &((XfwfPagerWidget)self)->xfwfPager.f_forward.attributes);
    switch (status) {
    case XpmNoMemory: XtError("Out of memory");
    case XpmColorFailed: XtError("Failed to allocate color for pixmap");
    case XpmColorError: XtWarning("Not all pixmap colors found");
    default: ; /* skip */
    }
    ((XfwfPagerWidget)self)->xfwfPager.flip_forward = XtVaCreateManagedWidget
	("_flip_forward", xfwfIconWidgetClass, self,
	 XtNlocation, "1.0-50 1.0-50 50 50", XtNimage, &((XfwfPagerWidget)self)->xfwfPager.f_forward,
	 XtNhighlightThickness, 0, XtNtraversalOn, False,
	 XtVaTypedArg, XtNtranslations, XtRString, trans,
	 strlen(trans)+1, NULL);
    XtAddCallback(((XfwfPagerWidget)self)->xfwfPager.flip_forward, XtNactivate, forward_CB, self);

    create_romangc(self);
    ((XfwfPagerWidget)self)->xfwfPager.baselineskip = 0.5 + ((XfwfPagerWidget)self)->xfwfPager.baseline * (((XfwfPagerWidget)self)->xfwfPager.roman->ascent + ((XfwfPagerWidget)self)->xfwfPager.roman->descent);
    ((XfwfPagerWidget)self)->xfwfPager.text = XtNewString(((XfwfPagerWidget)self)->xfwfPager.text);
    ((XfwfPagerWidget)self)->xfwfPager.fontFamily = XtNewString(((XfwfPagerWidget)self)->xfwfPager.fontFamily);
    ((XfwfPagerWidget)self)->xfwfPager.tablist = XtNewString(((XfwfPagerWidget)self)->xfwfPager.tablist);
    ((XfwfPagerWidget)self)->xfwfPager.fulltext = NULL;
    ((XfwfPagerWidget)self)->xfwfPager.page = NULL;
    init_text(self);
    split_text(self);
    if (((XfwfPagerWidget)self)->xfwfPager.lines > 0) scale_font(self);
}
#line 232 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 232 "Pager.w"
static Boolean  set_values(Widget  old,Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 232 "Pager.w"
static Boolean  set_values(old,request,self,args,num_args)Widget  old;Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 233 "Pager.w"
{
    Boolean need_redisplay = False;

    if (((XfwfPagerWidget)self)->xfwfPager.tablist != ((XfwfPagerWidget)old)->xfwfPager.tablist) {
	XtFree(((XfwfPagerWidget)old)->xfwfPager.tablist);
	XtFree((String) ((XfwfPagerWidget)old)->xfwfPager.tabs);
	((XfwfPagerWidget)self)->xfwfPager.tablist = XtNewString(((XfwfPagerWidget)self)->xfwfPager.tablist);
	((XfwfPagerWidget)self)->xfwfPager.tabs = XfwfTablist2Tabs(((XfwfPagerWidget)self)->xfwfPager.tablist);
	need_redisplay = True;
    }
    if (((XfwfPagerWidget)old)->xfwfPager.fontFamily != ((XfwfPagerWidget)self)->xfwfPager.fontFamily) {
	XtFree(((XfwfPagerWidget)old)->xfwfPager.fontFamily);
	((XfwfPagerWidget)self)->xfwfPager.fontFamily = XtNewString(((XfwfPagerWidget)self)->xfwfPager.fontFamily);
	XFreeFont(XtDisplay(self), ((XfwfPagerWidget)self)->xfwfPager.roman);
	(void) infer_roman(self);
    }
    if (((XfwfPagerWidget)old)->xfwfPager.text != ((XfwfPagerWidget)self)->xfwfPager.text) {
	XtFree(((XfwfPagerWidget)old)->xfwfPager.text);
	((XfwfPagerWidget)self)->xfwfPager.text = XtNewString(((XfwfPagerWidget)self)->xfwfPager.text);
	init_text(self);
	split_text(self);
	need_redisplay = True;
    }
    if (((XfwfPagerWidget)old)->xfwfPager.roman != ((XfwfPagerWidget)self)->xfwfPager.roman
	|| ((XfwfPagerWidget)old)->xfwfPager.lines != ((XfwfPagerWidget)self)->xfwfPager.lines
	|| ((XfwfPagerWidget)old)->xfwfPager.wrap != ((XfwfPagerWidget)self)->xfwfPager.wrap
	|| ((XfwfPagerWidget)old)->xfwfPager.baseline != ((XfwfPagerWidget)self)->xfwfPager.baseline
	|| (((XfwfPagerWidget)old)->core.width != ((XfwfPagerWidget)self)->core.width && ((XfwfPagerWidget)self)->xfwfPager.lines == 0)
	|| (((XfwfPagerWidget)old)->core.height != ((XfwfPagerWidget)self)->core.height && ((XfwfPagerWidget)self)->xfwfPager.lines == 0)) {
	split_text(self);
	need_redisplay = True;
    }
    if (((XfwfPagerWidget)old)->core.height != ((XfwfPagerWidget)self)->core.height && ((XfwfPagerWidget)self)->xfwfPager.lines > 0) {
	scale_font(self);
	need_redisplay = True;
    }
    return need_redisplay;
}
#line 276 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 276 "Pager.w"
static void resize(Widget self)
#else
#line 276 "Pager.w"
static void resize(self)Widget self;
#endif
#line 277 "Pager.w"
{
    xfwfBoardClassRec.core_class.resize(self);
    if (((XfwfPagerWidget)self)->xfwfPager.lines > 0) scale_font(self); else split_text(self);
}
#line 302 "Pager.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 302 "Pager.w"
static void expose(Widget self,XEvent * event,Region  region)
#else
#line 302 "Pager.w"
static void expose(self,event,region)Widget self;XEvent * event;Region  region;
#endif
#line 303 "Pager.w"
{
    Region reg;
    XRectangle rect;
    Position y;
    char *p, *q, h[20];
    Display *dpy = XtDisplay(self);
    Window win = XtWindow(self);

    if (! XtIsRealized(self)) return;
    if (! ((XfwfPagerWidget)self)->xfwfPager.fulltext) { xfwfBoardClassRec.core_class.expose(self, event, region); return; }
    ((XfwfPagerWidgetClass)self->core.widget_class)->xfwfCommon_class.compute_inside(self, &rect.x, &rect.y, &rect.width, &rect.height);
    reg = XCreateRegion();
    XUnionRectWithRegion(&rect, reg, reg);
    if (region) XIntersectRegion(reg, region, reg);
    XSetRegion(dpy, ((XfwfPagerWidget)self)->xfwfPager.romangc, reg);
    y = ((XfwfPagerWidget)self)->xfwfPager.margin + ((XfwfPagerWidget)self)->xfwfPager.baselineskip - ((XfwfPagerWidget)self)->xfwfPager.roman->descent;
    if (((XfwfPagerWidget)self)->xfwfPager.wrap) {
        /* wrapping mode not implemented yet */
    } else {
        p = ((XfwfPagerWidget)self)->xfwfPager.fulltext + ((XfwfPagerWidget)self)->xfwfPager.page[((XfwfPagerWidget)self)->xfwfPager.pageno];
        while (True) {
            if (y + ((XfwfPagerWidget)self)->xfwfPager.roman->descent >= rect.y + rect.height - 50) break;
            for (q = p; *q != '\0' && *q != '\n' && *q != '\f'; q++) ;
            XfwfDrawImageString(dpy, win, ((XfwfPagerWidget)self)->xfwfPager.romangc, rect.x+((XfwfPagerWidget)self)->xfwfPager.margin, y,
				p, q - p, ((XfwfPagerWidget)self)->xfwfPager.tabs);
            if (*q == '\0' || *q == '\f') break;
            y += ((XfwfPagerWidget)self)->xfwfPager.baselineskip;
            p = q + 1;
        }
    }
    /* Draw page number */
    sprintf(h, "%d", ((XfwfPagerWidget)self)->xfwfPager.pageno);
    XfwfDrawImageString(dpy, win, ((XfwfPagerWidget)self)->xfwfPager.romangc, rect.x + rect.width/2, rect.y +
		     rect.height - ((XfwfPagerWidget)self)->xfwfPager.roman->descent, h, strlen(h), ((XfwfPagerWidget)self)->xfwfPager.tabs);

    XSetClipMask(dpy, ((XfwfPagerWidget)self)->xfwfPager.romangc, None);
    xfwfBoardClassRec.core_class.expose(self, event, region);
}
