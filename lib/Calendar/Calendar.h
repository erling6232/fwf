/* Generated by wbuild from "Calendar.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfCalendar_H_
#define _XfwfCalendar_H_

#include <Xfwf/Board.h>
_XFUNCPROTOBEGIN
typedef struct {
            int day;
            int month;
            int year;
        } XfwfDate;

#define XfwfReverseDate 0x80 


void XfwfSetDayColors(
#if NeedFunctionPrototypes
Widget,int  colors[]
#endif
);
#ifndef XtNcalendarFont
#define XtNcalendarFont "calendarFont"
#endif
#ifndef XtCCalendarFont
#define XtCCalendarFont "CalendarFont"
#endif
#ifndef XtRFontStruct
#define XtRFontStruct "FontStruct"
#endif

#ifndef XtNheadingFont
#define XtNheadingFont "headingFont"
#endif
#ifndef XtCHeadingFont
#define XtCHeadingFont "HeadingFont"
#endif
#ifndef XtRFontStruct
#define XtRFontStruct "FontStruct"
#endif

#ifndef XtNcolor1
#define XtNcolor1 "color1"
#endif
#ifndef XtCColor1
#define XtCColor1 "Color1"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNcolor2
#define XtNcolor2 "color2"
#endif
#ifndef XtCColor2
#define XtCColor2 "Color2"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNcolor3
#define XtNcolor3 "color3"
#endif
#ifndef XtCColor3
#define XtCColor3 "Color3"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNcolor4
#define XtNcolor4 "color4"
#endif
#ifndef XtCColor4
#define XtCColor4 "Color4"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNcolor5
#define XtNcolor5 "color5"
#endif
#ifndef XtCColor5
#define XtCColor5 "Color5"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNheadingColor
#define XtNheadingColor "headingColor"
#endif
#ifndef XtCHeadingColor
#define XtCHeadingColor "HeadingColor"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNboxColor
#define XtNboxColor "boxColor"
#endif
#ifndef XtCBoxColor
#define XtCBoxColor "BoxColor"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNweekdayColor
#define XtNweekdayColor "weekdayColor"
#endif
#ifndef XtCWeekdayColor
#define XtCWeekdayColor "WeekdayColor"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNdayColors
#define XtNdayColors "dayColors"
#endif
#ifndef XtCDayColors
#define XtCDayColors "DayColors"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNinternalOffset
#define XtNinternalOffset "internalOffset"
#endif
#ifndef XtCInternalOffset
#define XtCInternalOffset "InternalOffset"
#endif
#ifndef XtRDimension
#define XtRDimension "Dimension"
#endif

#ifndef XtNmonth
#define XtNmonth "month"
#endif
#ifndef XtCMonth
#define XtCMonth "Month"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNyear
#define XtNyear "year"
#endif
#ifndef XtCYear
#define XtCYear "Year"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNboxed
#define XtNboxed "boxed"
#endif
#ifndef XtCBoxed
#define XtCBoxed "Boxed"
#endif
#ifndef XtRBoolean
#define XtRBoolean "Boolean"
#endif

#ifndef XtNwrapped
#define XtNwrapped "wrapped"
#endif
#ifndef XtCWrapped
#define XtCWrapped "Wrapped"
#endif
#ifndef XtRBoolean
#define XtRBoolean "Boolean"
#endif

#ifndef XtNheading
#define XtNheading "heading"
#endif
#ifndef XtCHeading
#define XtCHeading "Heading"
#endif
#ifndef XtRBoolean
#define XtRBoolean "Boolean"
#endif

#ifndef XtNdateCallback
#define XtNdateCallback "dateCallback"
#endif
#ifndef XtCDateCallback
#define XtCDateCallback "DateCallback"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNchangeCallback
#define XtNchangeCallback "changeCallback"
#endif
#ifndef XtCChangeCallback
#define XtCChangeCallback "ChangeCallback"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNinitialDelay
#define XtNinitialDelay "initialDelay"
#endif
#ifndef XtCInitialDelay
#define XtCInitialDelay "InitialDelay"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNrepeatDelay
#define XtNrepeatDelay "repeatDelay"
#endif
#ifndef XtCRepeatDelay
#define XtCRepeatDelay "RepeatDelay"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

typedef struct _XfwfCalendarClassRec *XfwfCalendarWidgetClass;
typedef struct _XfwfCalendarRec *XfwfCalendarWidget;
externalref WidgetClass xfwfCalendarWidgetClass;
_XFUNCPROTOEND
#endif /*_XfwfCalendar_H_*/
