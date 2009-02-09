/* Generated by wbuild from "ThWheel.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfThumbWheelP_H_
#define _XfwfThumbWheelP_H_
#include <X11/CoreP.h>
#include <Xfwf/ThWheel.h>
_XFUNCPROTOBEGIN
typedef void (*scroll_response_Proc)(
#if NeedFunctionPrototypes
Widget ,XtPointer ,XtPointer 
#endif
);
#define XtInherit_scroll_response ((scroll_response_Proc) _XtInherit)

typedef struct {
/* methods */
scroll_response_Proc scroll_response;
/* class variables */
} XfwfThumbWheelClassPart;

typedef struct _XfwfThumbWheelClassRec {
CoreClassPart core_class;
XfwfThumbWheelClassPart xfwfThumbWheel_class;
} XfwfThumbWheelClassRec;

typedef struct {
/* resources */
int  numberOfPictures;
XImage ** pictures;
Boolean  vertical;
Dimension  clickArea;
int  minValue;
int  maxValue;
int  value;
int  step;
int  initialDelay;
int  repeatDelay;
int  sensitivity;
XtCallbackList  scrollCallback;
XtCallbackProc  scrollResponse;
/* private state */
Pixmap * pix;
int  curpic;
GC  gc;
XtIntervalId  timer;
int  delta;
XfwfSReason  reason;
Boolean  timer_on;
} XfwfThumbWheelPart;

typedef struct _XfwfThumbWheelRec {
CorePart core;
XfwfThumbWheelPart xfwfThumbWheel;
} XfwfThumbWheelRec;

externalref XfwfThumbWheelClassRec xfwfThumbWheelClassRec;

_XFUNCPROTOEND
#endif /* _XfwfThumbWheelP_H_ */
