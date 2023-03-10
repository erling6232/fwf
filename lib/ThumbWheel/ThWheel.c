/* Generated by wbuild from "ThWheel.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 586 "ThWheel.w"
#include "wheels.h"
#line 587 "ThWheel.w"
#include <stdio.h>
#include <Xfwf/ThWheelP.h>
#line 353 "ThWheel.w"
static void up(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 387 "ThWheel.w"
static void down(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#define BMask (Button1Mask |Button2Mask |Button3Mask |Button4Mask |Button5Mask )


#line 432 "ThWheel.w"
static void turn(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 529 "ThWheel.w"
static void stop_turning(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);

static XtActionsRec actionsList[] = {
{"up", up},
{"down", down},
{"turn", turn},
{"stop_turning", stop_turning},
};

static char defaultTranslations[] = "\
<Btn1Down>: turn() \n\
<Btn2Down>: turn(50) \n\
<Btn3Down>: turn(25) \n\
<BtnUp>: stop_turning() \n\
None<Key>Up: up() \n\
!Shift<Key>Up: up(50) \n\
!Ctrl<Key>Up: up(25) \n\
None<Key>Down: down() \n\
!Shift<Key>Down: down(50) \n\
!Ctrl<Key>Down: down(25) \n\
";
static void _resolve_inheritance(
#if NeedFunctionPrototypes
WidgetClass
#endif
);
#line 220 "ThWheel.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 239 "ThWheel.w"
static void realize(
#if NeedFunctionPrototypes
Widget,XtValueMask *,XSetWindowAttributes *
#endif
);
#line 326 "ThWheel.w"
static void scroll_response(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 539 "ThWheel.w"
#define abs(a) ((a )<0 ?-(a ):(a ))


#line 540 "ThWheel.w"
#define min(a, b) ((a )<(b )?(a ):(b ))


#line 541 "ThWheel.w"
#define max(a, b) ((a )>(b )?(a ):(b ))


#line 547 "ThWheel.w"
static void timer_callback(
#if NeedFunctionPrototypes
XtPointer ,XtIntervalId *
#endif
);
#line 547 "ThWheel.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 547 "ThWheel.w"
static void timer_callback(XtPointer  call_data,XtIntervalId * id)
#else
#line 547 "ThWheel.w"
static void timer_callback(call_data,id)XtPointer  call_data;XtIntervalId * id;
#endif
#line 548 "ThWheel.w"
{
    Widget self = (Widget) call_data;
    XfwfScrollInfo info;
    int newval, a, b;

    newval = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.delta;
    a = min(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    b = max(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    newval = min(b, max(a, newval));
    if (newval == ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value) {			/* No further changes */
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer_on = False;
	return;
    }
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = newval;

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic += (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason == XfwfSUp || ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason == XfwfSLeft) ?
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures - 1 : 1;
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic], NULL);

    info.reason = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason;
    info.flags = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical ? XFWF_VPOS : XFWF_HPOS;
    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical)
	info.vpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    else
	info.hpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer = XtAppAddTimeOut(XtWidgetToApplicationContext(self),
			     ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.repeatDelay, timer_callback, self);
}

static XtResource resources[] = {
#line 60 "ThWheel.w"
{XtNnumberOfPictures,XtCNumberOfPictures,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.numberOfPictures),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.numberOfPictures),XtRImmediate,(XtPointer)0 },
#line 61 "ThWheel.w"
{XtNpictures,XtCPictures,XtRImageList,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.pictures),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.pictures),XtRImmediate,(XtPointer)NULL },
#line 67 "ThWheel.w"
{XtNvertical,XtCVertical,XtRBoolean,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.vertical),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.vertical),XtRImmediate,(XtPointer)True },
#line 74 "ThWheel.w"
{XtNclickArea,XtCClickArea,XtRDimension,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.clickArea),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.clickArea),XtRImmediate,(XtPointer)7 },
#line 86 "ThWheel.w"
{XtNminValue,XtCMinValue,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.minValue),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.minValue),XtRImmediate,(XtPointer)0 },
#line 87 "ThWheel.w"
{XtNmaxValue,XtCMaxValue,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.maxValue),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.maxValue),XtRImmediate,(XtPointer)100 },
#line 88 "ThWheel.w"
{XtNvalue,XtCValue,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.value),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.value),XtRImmediate,(XtPointer)0 },
#line 95 "ThWheel.w"
{XtNstep,XtCStep,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.step),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.step),XtRImmediate,(XtPointer)1 },
#line 101 "ThWheel.w"
{XtNinitialDelay,XtCInitialDelay,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.initialDelay),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.initialDelay),XtRImmediate,(XtPointer)500 },
#line 102 "ThWheel.w"
{XtNrepeatDelay,XtCRepeatDelay,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.repeatDelay),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.repeatDelay),XtRImmediate,(XtPointer)50 },
#line 108 "ThWheel.w"
{XtNsensitivity,XtCSensitivity,XtRInt,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.sensitivity),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.sensitivity),XtRImmediate,(XtPointer)2 },
#line 140 "ThWheel.w"
{XtNscrollCallback,XtCScrollCallback,XtRCallback,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.scrollCallback),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.scrollCallback),XtRImmediate,(XtPointer)NULL },
#line 151 "ThWheel.w"
{XtNscrollResponse,XtCScrollResponse,XtRXTCallbackProc,sizeof(((XfwfThumbWheelRec*)NULL)->xfwfThumbWheel.scrollResponse),XtOffsetOf(XfwfThumbWheelRec,xfwfThumbWheel.scrollResponse),XtRImmediate,(XtPointer)scroll_response },
};

XfwfThumbWheelClassRec xfwfThumbWheelClassRec = {
{ /* core_class part */
/* superclass   	*/  (WidgetClass) &coreClassRec,
/* class_name   	*/  "XfwfThumbWheel",
/* widget_size  	*/  sizeof(XfwfThumbWheelRec),
/* class_initialize 	*/  NULL,
/* class_part_initialize*/  _resolve_inheritance,
/* class_inited 	*/  FALSE,
/* initialize   	*/  initialize,
/* initialize_hook 	*/  NULL,
/* realize      	*/  realize,
/* actions      	*/  actionsList,
/* num_actions  	*/  4,
/* resources    	*/  resources,
/* num_resources 	*/  13,
/* xrm_class    	*/  NULLQUARK,
/* compres_motion 	*/  False ,
/* compress_exposure 	*/  FALSE ,
/* compress_enterleave 	*/  False ,
/* visible_interest 	*/  False ,
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
{ /* XfwfThumbWheel_class part */
scroll_response,
},
};
WidgetClass xfwfThumbWheelWidgetClass = (WidgetClass) &xfwfThumbWheelClassRec;
/*ARGSUSED*/
#line 353 "ThWheel.w"
static void up(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, newval, a, b;
    XfwfScrollInfo info;


    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;
    newval = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.step * percentage + 99)/100; /* Round up */
    a = min(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    b = max(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    newval = min(b, max(a, newval));

    if (newval == ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value) return;		/* No change */

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = newval;

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures - 1) % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic], NULL);

    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	info.reason = XfwfSUp;
	info.flags = XFWF_VPOS;
	info.vpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    } else {
	info.reason = XfwfSLeft;
	info.flags = XFWF_HPOS;
	info.hpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    }
    XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);
}

/*ARGSUSED*/
#line 387 "ThWheel.w"
static void down(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, newval, a, b;
    XfwfScrollInfo info;

    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;

    newval = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value + (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.step * percentage + 99)/100; /* Round up */
    a = min(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    b = max(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
    newval = min(b, max(a, newval));

    if (newval == ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value) return;		/* No change */

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = newval;

    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic + 1) % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic], NULL);

    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	info.reason = XfwfSDown;
	info.flags = XFWF_VPOS;
	info.vpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    } else {	
	info.reason = XfwfSRight;
	info.flags = XFWF_HPOS;
	info.hpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
    }
    XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);
}

/*ARGSUSED*/
#line 432 "ThWheel.w"
static void turn(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, mouse, rx, ry, m, x, y, m1, oldvalue, newval, a, b;
    Window root, child;
    unsigned int mask;
    XfwfScrollInfo info;

    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;
    d = (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.step * percentage + 99)/100;

    /* Get starting mouse position */
    mouse = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical ? event->xbutton.y : event->xbutton.x;

    if (mouse >= ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea
	&& mouse < (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical?((XfwfThumbWheelWidget)self)->core.height:((XfwfThumbWheelWidget)self)->core.width) - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea) {
	/* Middle area */
	m1 = mouse;				/* Previous mouse pos. */
	oldvalue = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value;
	while (XQueryPointer(XtDisplay(self), XtWindow(self), &root, &child,
			     &rx, &ry, &x, &y, &mask)
	       && (mask & BMask)) {
	    m = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical ? y : x;
	    if (m != m1) {
		m1 = m;

		newval = oldvalue + (m - mouse)/((XfwfThumbWheelWidget)self)->xfwfThumbWheel.sensitivity * d;
		a = min(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
		b = max(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
		newval = min(b, max(a, newval));
		if (newval == ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value) continue;	/* No change */

		((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = newval;

		((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = ((m - mouse)/((XfwfThumbWheelWidget)self)->xfwfThumbWheel.sensitivity % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures
			   + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures) % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures;
		XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic], NULL);

		info.reason = XfwfSDrag;
		if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
		    info.flags = XFWF_VPOS;
		    info.vpos = 1.0
			* (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
		} else {
		    info.flags = XFWF_HPOS;
		    info.hpos = 1.0
			* (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
		}
		XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);
	    }
	}
	info.reason = XfwfSMove;
	if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	    info.flags = XFWF_VPOS;
	    info.vpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
	} else {
	    info.flags = XFWF_HPOS;
	    info.hpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
	}
	XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);
    } else {
	/* Upper/left or lower/right click area */
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.delta = mouse < ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea ? -d : d;
	if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical)
	    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason = mouse < ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea ? XfwfSUp : XfwfSDown;
	else
	    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason = mouse < ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea ? XfwfSLeft : XfwfSRight;
	newval = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.delta;
	a = min(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
	b = max(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue);
	newval = min(b, max(a, newval));
	if (newval == ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value) return;		/* No change */

	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic += mouse < ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.clickArea ? ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures - 1 : 1;
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic % ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures;
	XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic], NULL);

	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = newval;

	info.reason = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.reason;
	if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	    info.flags = XFWF_VPOS;
	    info.vpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
	} else {
	    info.flags = XFWF_HPOS;
	    info.hpos = 1.0 * (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue)/(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue);
	}
	XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &info);

	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer_on = True;
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer = XtAppAddTimeOut(XtWidgetToApplicationContext(self),
				 ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.initialDelay, timer_callback, self);
    }
}

/*ARGSUSED*/
#line 529 "ThWheel.w"
static void stop_turning(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer_on) {
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer_on = False;
	XtRemoveTimeOut(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer);
    }
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfThumbWheelWidgetClass c = (XfwfThumbWheelWidgetClass) class;
  XfwfThumbWheelWidgetClass super;
  if (class == xfwfThumbWheelWidgetClass) return;
  super = (XfwfThumbWheelWidgetClass)class->core_class.superclass;
  if (c->xfwfThumbWheel_class.scroll_response == XtInherit_scroll_response)
    c->xfwfThumbWheel_class.scroll_response = super->xfwfThumbWheel_class.scroll_response;
}
#line 220 "ThWheel.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 220 "ThWheel.w"
static void initialize(Widget  request,Widget self,ArgList  args,Cardinal * num_args)
#else
#line 220 "ThWheel.w"
static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
#endif
#line 221 "ThWheel.w"
{
    XGCValues values;

    if (! ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures) ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures = 4;	/* Built-in pictures */
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.gc = XtGetGC(self, 0, &values);
    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures) {
	((XfwfThumbWheelWidget)self)->core.width = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[0]->width;
	((XfwfThumbWheelWidget)self)->core.height = ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[0]->height;
    } else if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	((XfwfThumbWheelWidget)self)->core.width = 15;
	((XfwfThumbWheelWidget)self)->core.height = 64;
    } else {
	((XfwfThumbWheelWidget)self)->core.width = 64;
	((XfwfThumbWheelWidget)self)->core.height = 15;
    }
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.timer_on = False;
}
#line 239 "ThWheel.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 239 "ThWheel.w"
static void realize(Widget self,XtValueMask * mask,XSetWindowAttributes * attributes)
#else
#line 239 "ThWheel.w"
static void realize(self,mask,attributes)Widget self;XtValueMask * mask;XSetWindowAttributes * attributes;
#endif
#line 240 "ThWheel.w"
{
    int i, stat;

    coreClassRec.core_class.realize(self, mask, attributes);
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix = (Pixmap*) XtMalloc(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures * sizeof(((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0]));
    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures) {
	for (i = 0; i < ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.numberOfPictures; i++) {
	    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[i] = XCreatePixmap
		(XtDisplay(self), XtWindow(self), ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[i]->width,
		 ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[i]->height, ((XfwfThumbWheelWidget)self)->core.depth);
	    XPutImage(XtDisplay(self), ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[i], ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.gc, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[i], 0, 0, 0, 0,
		      ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[i]->width, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pictures[i]->height);
	}
    } else if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {			/* Use built-in pictures */
#ifndef NO_XPM
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel0, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel1, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[1], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel2, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[2], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel3, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[3], NULL, NULL);
#else
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel0_bits, wheel0_width,
	     wheel0_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[1] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel1_bits, wheel1_width,
	     wheel1_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[2] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel2_bits, wheel2_width,
	     wheel2_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[3] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel3_bits, wheel3_width,
	     wheel3_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
#endif
    } else {					/* Horizontal */
#ifndef NO_XPM
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel0h, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel1h, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[1], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel2h, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[2], NULL, NULL);
	stat = XpmCreatePixmapFromData
	    (XtDisplay(self), XtWindow(self), wheel3h, &((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[3], NULL, NULL);
#else
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel0h_bits, wheel0h_width,
	     wheel0h_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[1] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel1h_bits, wheel1h_width,
	     wheel1h_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[2] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel2h_bits, wheel2h_width,
	     wheel2h_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
	((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[3] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel3h_bits, wheel3h_width,
	     wheel3h_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheelWidget)self)->core.depth);
#endif
    }

    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.pix[0], NULL);
    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.curpic = 0;
}
#line 326 "ThWheel.w"
/*ARGSUSED*/
#if NeedFunctionPrototypes
#line 326 "ThWheel.w"
static void scroll_response(Widget  w,XtPointer  client_data,XtPointer  call_data)
#else
#line 326 "ThWheel.w"
static void scroll_response(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
#endif
#line 327 "ThWheel.w"
{
    Widget self = (Widget) client_data;
    XfwfScrollInfo *info = (XfwfScrollInfo *) call_data;
    XfwfScrollInfo new_info;

    if (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.vertical) {
	if (info->flags & XFWF_VPOS)
	    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue) * info->vpos + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue + 0.5;
    } else {
	if (info->flags & XFWF_HPOS)
	    ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.value = (((XfwfThumbWheelWidget)self)->xfwfThumbWheel.maxValue - ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue) * info->hpos + ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.minValue + 0.5;
    }
    if (info->reason != XfwfSNotify) {
	new_info = *info;
	new_info.reason = XfwfSNotify;
	XtCallCallbackList(self, ((XfwfThumbWheelWidget)self)->xfwfThumbWheel.scrollCallback, &new_info);
    }
}
#line 159 "ThWheel.w"
