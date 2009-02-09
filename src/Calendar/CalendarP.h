/* Generated by wbuild from "Calendar.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfCalendarP_H_
#define _XfwfCalendarP_H_
#include <Xfwf/BoardP.h>
#include <Xfwf/Calendar.h>
_XFUNCPROTOBEGIN
typedef enum {
	    MonthPlus, MonthMinus, YearPlus, YearMinus } CalendarMovement;

typedef struct {
/* methods */
/* class variables */
int dummy;
} XfwfCalendarClassPart;

typedef struct _XfwfCalendarClassRec {
CoreClassPart core_class;
CompositeClassPart composite_class;
XfwfCommonClassPart xfwfCommon_class;
XfwfFrameClassPart xfwfFrame_class;
XfwfBoardClassPart xfwfBoard_class;
XfwfCalendarClassPart xfwfCalendar_class;
} XfwfCalendarClassRec;

typedef struct {
/* resources */
XFontStruct * calendarFont;
XFontStruct * headingFont;
Pixel  color1;
Pixel  color2;
Pixel  color3;
Pixel  color4;
Pixel  color5;
Pixel  headingColor;
Pixel  boxColor;
Pixel  weekdayColor;
int * dayColors;
Dimension  internalOffset;
int  month;
int  year;
Boolean  boxed;
Boolean  wrapped;
Boolean  heading;
XtCallbackList  dateCallback;
XtCallbackList  changeCallback;
int  initialDelay;
int  repeatDelay;
/* private state */
Pixmap  upBitmap;
Pixmap  downBitmap;
GC  headingGC;
GC  calendarGC;
GC  boxGC;
GC  reversingGC;
XtIntervalId  timer;
Boolean  timer_on;
int  calmatrix[6][7];
CalendarMovement  movement;
XfwfDate  click_date;
} XfwfCalendarPart;

typedef struct _XfwfCalendarRec {
CorePart core;
CompositePart composite;
XfwfCommonPart xfwfCommon;
XfwfFramePart xfwfFrame;
XfwfBoardPart xfwfBoard;
XfwfCalendarPart xfwfCalendar;
} XfwfCalendarRec;

externalref XfwfCalendarClassRec xfwfCalendarClassRec;

_XFUNCPROTOEND
#endif /* _XfwfCalendarP_H_ */
