/* Generated by wbuild from "ThWheel2.w"
** (generator version $Revision$ of $Date$)
*/
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#line 462 "ThWheel2.w"
#include "wheel0.bm"
#line 463 "ThWheel2.w"
#include "wheel1.bm"
#line 464 "ThWheel2.w"
#include "wheel2.bm"
#line 465 "ThWheel2.w"
#include "wheel3.bm"
#line 467 "ThWheel2.w"
#include <stdio.h>
#include <Xfwf/ThWheel2P.h>
#line 271 "ThWheel2.w"
static void up(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 299 "ThWheel2.w"
static void down(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#define BMask (Button1Mask |Button2Mask |Button3Mask |Button4Mask |Button5Mask )


#line 337 "ThWheel2.w"
static void turn(
#if NeedFunctionPrototypes
Widget,XEvent*,String*,Cardinal*
#endif
);
#line 411 "ThWheel2.w"
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
#line 188 "ThWheel2.w"
static void initialize(
#if NeedFunctionPrototypes
Widget ,Widget,ArgList ,Cardinal *
#endif
);
#line 200 "ThWheel2.w"
static void realize(
#if NeedFunctionPrototypes
Widget,XtValueMask *,XSetWindowAttributes *
#endif
);
#line 248 "ThWheel2.w"
static void scroll_response(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#line 421 "ThWheel2.w"
#define abs(a) ((a )<0 ?-(a ):(a ))


#line 422 "ThWheel2.w"
#define min(a, b) ((a )<(b )?(a ):(b ))


#line 423 "ThWheel2.w"
#define max(a, b) ((a )>(b )?(a ):(b ))


#line 429 "ThWheel2.w"
static void timer_callback(
#if NeedFunctionPrototypes
XtPointer ,XtIntervalId *
#endif
);
#line 429 "ThWheel2.w"
/*ARGSUSED*/static void timer_callback(call_data,id)XtPointer  call_data;XtIntervalId * id;
{
    Widget self = (Widget) call_data;
    XfwfScrollInfo info;
    int newval, a, b;

    newval = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value + ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.delta;
    a = min(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    b = max(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    newval = min(b, max(a, newval));
    if (newval == ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value) {			/* No further changes */
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer_on = False;
	return;
    }
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = newval;

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic += ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.reason == XfwfSUp ? ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures - 1 : 1;
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic], NULL);

    info.reason = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.reason;
    info.flags = XFWF_VPOS;
    info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
    XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer = XtAppAddTimeOut(XtWidgetToApplicationContext(self),
			     ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.repeatDelay, timer_callback, self);
}

static XtResource resources[] = {
#line 31 "ThWheel2.w"
{XtNnumberOfPictures,XtCNumberOfPictures,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.numberOfPictures),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.numberOfPictures),XtRImmediate,(XtPointer)0 },
#line 32 "ThWheel2.w"
{XtNpictures,XtCPictures,XtRXImageArray,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.pictures),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.pictures),XtRImmediate,(XtPointer)NULL },
#line 38 "ThWheel2.w"
{XtNclickArea,XtCClickArea,XtRDimension,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.clickArea),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.clickArea),XtRImmediate,(XtPointer)7 },
#line 50 "ThWheel2.w"
{XtNminValue,XtCMinValue,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.minValue),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.minValue),XtRImmediate,(XtPointer)0 },
#line 51 "ThWheel2.w"
{XtNmaxValue,XtCMaxValue,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.maxValue),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.maxValue),XtRImmediate,(XtPointer)100 },
#line 52 "ThWheel2.w"
{XtNvalue,XtCValue,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.value),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.value),XtRImmediate,(XtPointer)0 },
#line 59 "ThWheel2.w"
{XtNstep,XtCStep,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.step),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.step),XtRImmediate,(XtPointer)1 },
#line 65 "ThWheel2.w"
{XtNinitialDelay,XtCInitialDelay,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.initialDelay),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.initialDelay),XtRImmediate,(XtPointer)500 },
#line 66 "ThWheel2.w"
{XtNrepeatDelay,XtCRepeatDelay,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.repeatDelay),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.repeatDelay),XtRImmediate,(XtPointer)50 },
#line 72 "ThWheel2.w"
{XtNsensitivity,XtCSensitivity,XtRInt,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.sensitivity),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.sensitivity),XtRImmediate,(XtPointer)2 },
#line 102 "ThWheel2.w"
{XtNscrollCallback,XtCScrollCallback,XtRCallback,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.scrollCallback),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.scrollCallback),XtRImmediate,(XtPointer)NULL },
#line 113 "ThWheel2.w"
{XtNscrollResponse,XtCScrollResponse,XtRXTCallbackProc,sizeof(((XfwfThumbWheel2Rec*)NULL)->xfwfThumbWheel2.scrollResponse),XtOffsetOf(XfwfThumbWheel2Rec,xfwfThumbWheel2.scrollResponse),XtRImmediate,(XtPointer)scroll_response },
};

XfwfThumbWheel2ClassRec xfwfThumbWheel2ClassRec = {
{ /* core_class part */
(WidgetClass) &coreClassRec,
"XfwfThumbWheel2",
sizeof(XfwfThumbWheel2Rec),
NULL,
_resolve_inheritance,
FALSE,
initialize,
NULL,
realize,
actionsList,
4,
resources,
12,
NULLQUARK,
False ,
FALSE ,
False ,
False ,
NULL,
XtInheritResize,
XtInheritExpose,
NULL,
NULL,
XtInheritSetValuesAlmost,
NULL,
XtInheritAcceptFocus,
XtVersion,
NULL,
defaultTranslations,
XtInheritQueryGeometry,
XtInheritDisplayAccelerator,
NULL 
},
{ /* XfwfThumbWheel2_class part */
scroll_response,
},
};
WidgetClass xfwfThumbWheel2WidgetClass = (WidgetClass) &xfwfThumbWheel2ClassRec;
/*ARGSUSED*/
#line 271 "ThWheel2.w"
static void up(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, newval, a, b;
    XfwfScrollInfo info;


    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;
    newval = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.step * percentage + 99)/100; /* Round up */
    a = min(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    b = max(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    newval = min(b, max(a, newval));

    if (newval == ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value) return;		/* No change */

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = newval;

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic + ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures - 1) % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic], NULL);

    info.reason = XfwfSUp;
    info.flags = XFWF_VPOS;
    info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
    XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);
}

/*ARGSUSED*/
#line 299 "ThWheel2.w"
static void down(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, newval, a, b;
    XfwfScrollInfo info;

    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;

    newval = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value + (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.step * percentage + 99)/100; /* Round up */
    a = min(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    b = max(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
    newval = min(b, max(a, newval));

    if (newval == ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value) return;		/* No change */

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = newval;

    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic + 1) % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures;
    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic], NULL);

    info.reason = XfwfSDown;
    info.flags = XFWF_VPOS;
    info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
    XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);
}

/*ARGSUSED*/
#line 337 "ThWheel2.w"
static void turn(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    int percentage, d, mousey, rx, ry, x, y, y1, oldvalue, newval, a, b;
    Window root, child;
    unsigned int mask;
    XfwfScrollInfo info;

    if (*num_params == 0 || sscanf(params[0], "%d", &percentage) != 1)
	percentage = 100;
    d = (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.step * percentage + 99)/100;

    mousey = event->xbutton.y;			/* Starting mouse pos. */

    if (mousey >= ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.clickArea && mousey < ((XfwfThumbWheel2Widget)self)->core.height - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.clickArea) {
	/* Middle area */
	y1 = mousey;				/* Previous mouse pos. */
	oldvalue = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value;
	while (XQueryPointer(XtDisplay(self), XtWindow(self), &root, &child,
			     &rx, &ry, &x, &y, &mask)
	       && (mask & BMask)) {
	    if (y != y1) {
		y1 = y;

		newval = oldvalue + (y - mousey)/((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.sensitivity * d;
		a = min(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
		b = max(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
		newval = min(b, max(a, newval));
		if (newval == ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value) continue;	/* No change */

		((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = newval;

		((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = ((y - mousey)/((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.sensitivity % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures
			   + ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures) % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures;
		XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic], NULL);

		info.reason = XfwfSDrag;
		info.flags = XFWF_VPOS;
		info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
		XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);
	    }
	}
	info.reason = XfwfSMove;
	info.flags = XFWF_VPOS;
	info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
	XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);
    } else {
	/* Upper or lower click area */
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.delta = mousey < ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.clickArea ? -d : d;
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.reason = mousey < ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.clickArea ? XfwfSUp : XfwfSDown;
	newval = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value + ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.delta;
	a = min(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
	b = max(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue);
	newval = min(b, max(a, newval));
	if (newval == ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value) return;		/* No change */

	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic += mousey < ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.clickArea ? ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures - 1 : 1;
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic % ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures;
	XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic], NULL);

	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = newval;

	info.reason = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.reason;
	info.flags = XFWF_VPOS;
	info.vpos = 1.0 * (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue)/(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue);
	XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &info);

	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer_on = True;
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer = XtAppAddTimeOut(XtWidgetToApplicationContext(self),
				 ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.initialDelay, timer_callback, self);
    }
}

/*ARGSUSED*/
#line 411 "ThWheel2.w"
static void stop_turning(self,event,params,num_params)Widget self;XEvent*event;String*params;Cardinal*num_params;
{
    if (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer_on) {
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer_on = False;
	XtRemoveTimeOut(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer);
    }
}

static void _resolve_inheritance(class)
WidgetClass class;
{
  XfwfThumbWheel2WidgetClass c = (XfwfThumbWheel2WidgetClass) class;
  XfwfThumbWheel2WidgetClass super;
  if (class == xfwfThumbWheel2WidgetClass) return;
  super = (XfwfThumbWheel2WidgetClass)class->core_class.superclass;
  if (c->xfwfThumbWheel2_class.scroll_response == XtInherit_scroll_response)
    c->xfwfThumbWheel2_class.scroll_response = super->xfwfThumbWheel2_class.scroll_response;
}
#line 188 "ThWheel2.w"
/*ARGSUSED*/static void initialize(request,self,args,num_args)Widget  request;Widget self;ArgList  args;Cardinal * num_args;
{
    XGCValues values;
    int stat;

    if (! ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures) ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures = 4;	/* Built-in pictures */
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.gc = XtGetGC(self, 0, &values);
    ((XfwfThumbWheel2Widget)self)->core.width = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures ? ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[0]->width : wheel0_width;
    ((XfwfThumbWheel2Widget)self)->core.height = ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures ? ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[0]->height : wheel0_height;
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.timer_on = False;
}
#line 200 "ThWheel2.w"
/*ARGSUSED*/static void realize(self,mask,attributes)Widget self;XtValueMask * mask;XSetWindowAttributes * attributes;
{
    int i;

    coreClassRec.core_class.realize(self, mask, attributes);
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix = (Pixmap*) XtMalloc(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures * sizeof(((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[0]));
    if (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures) {
	for (i = 0; i < ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.numberOfPictures; i++) {
	    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[i] = XCreatePixmap
		(XtDisplay(self), XtWindow(self), ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[i]->width,
		 ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[i]->height, ((XfwfThumbWheel2Widget)self)->core.depth);
	    XPutImage(XtDisplay(self), ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[i], ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.gc, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[i], 0, 0, 0, 0,
		      ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[i]->width, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pictures[i]->height);
	}
    } else {					/* Built-in pictures */
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[0] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel0_bits, wheel0_width,
	     wheel0_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheel2Widget)self)->core.depth);
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[1] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel1_bits, wheel1_width,
	     wheel1_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheel2Widget)self)->core.depth);
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[2] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel2_bits, wheel2_width,
	     wheel2_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheel2Widget)self)->core.depth);
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[3] = XCreatePixmapFromBitmapData
	    (XtDisplay(self), XtWindow(self), wheel3_bits, wheel3_width,
	     wheel3_height, BlackPixelOfScreen(XtScreen(self)),
	     WhitePixelOfScreen(XtScreen(self)), ((XfwfThumbWheel2Widget)self)->core.depth);
    }

    XtVaSetValues(self, XtNbackgroundPixmap, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.pix[0], NULL);
    ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.curpic = 0;
}
#line 248 "ThWheel2.w"
/*ARGSUSED*/static void scroll_response(w,client_data,call_data)Widget  w;XtPointer  client_data;XtPointer  call_data;
{
    Widget self = (Widget) client_data;
    XfwfScrollInfo *info = (XfwfScrollInfo *) call_data;
    XfwfScrollInfo new_info;

    if (info->flags & XFWF_VPOS)
	((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.value = (((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.maxValue - ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue) * info->vpos + ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.minValue + 0.5;

    if (info->reason != XfwfSNotify) {
	new_info = *info;
	new_info.reason = XfwfSNotify;
	XtCallCallbackList(self, ((XfwfThumbWheel2Widget)self)->xfwfThumbWheel2.scrollCallback, &new_info);
    }
}
#line 121 "ThWheel2.w"
#line 125 "ThWheel2.w"
