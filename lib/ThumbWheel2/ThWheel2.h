/* Generated by wbuild from "ThWheel2.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfThumbWheel2_H_
#define _XfwfThumbWheel2_H_
#include <X11/Core.h>
#include <Xfwf/scroll.h>
typedef XImage ** XImageArray;

#ifndef XtNnumberOfPictures
#define XtNnumberOfPictures "numberOfPictures"
#endif
#ifndef XtCNumberOfPictures
#define XtCNumberOfPictures "NumberOfPictures"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNpictures
#define XtNpictures "pictures"
#endif
#ifndef XtCPictures
#define XtCPictures "Pictures"
#endif
#ifndef XtRXImageArray
#define XtRXImageArray "XImageArray"
#endif

#ifndef XtNclickArea
#define XtNclickArea "clickArea"
#endif
#ifndef XtCClickArea
#define XtCClickArea "ClickArea"
#endif
#ifndef XtRDimension
#define XtRDimension "Dimension"
#endif

#ifndef XtNminValue
#define XtNminValue "minValue"
#endif
#ifndef XtCMinValue
#define XtCMinValue "MinValue"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNmaxValue
#define XtNmaxValue "maxValue"
#endif
#ifndef XtCMaxValue
#define XtCMaxValue "MaxValue"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNvalue
#define XtNvalue "value"
#endif
#ifndef XtCValue
#define XtCValue "Value"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNstep
#define XtNstep "step"
#endif
#ifndef XtCStep
#define XtCStep "Step"
#endif
#ifndef XtRInt
#define XtRInt "Int"
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

#ifndef XtNsensitivity
#define XtNsensitivity "sensitivity"
#endif
#ifndef XtCSensitivity
#define XtCSensitivity "Sensitivity"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNscrollCallback
#define XtNscrollCallback "scrollCallback"
#endif
#ifndef XtCScrollCallback
#define XtCScrollCallback "ScrollCallback"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNscrollResponse
#define XtNscrollResponse "scrollResponse"
#endif
#ifndef XtCScrollResponse
#define XtCScrollResponse "ScrollResponse"
#endif
#ifndef XtRXTCallbackProc
#define XtRXTCallbackProc "XTCallbackProc"
#endif

typedef struct _XfwfThumbWheel2ClassRec *XfwfThumbWheel2WidgetClass;
typedef struct _XfwfThumbWheel2Rec *XfwfThumbWheel2Widget;
externalref WidgetClass xfwfThumbWheel2WidgetClass;
#endif /*_XfwfThumbWheel2_H_*/