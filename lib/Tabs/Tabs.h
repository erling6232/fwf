/* Generated by wbuild from "Tabs.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfTabs_H_
#define _XfwfTabs_H_
#include <Xfwf/Board.h>
_XFUNCPROTOBEGIN
typedef enum {
	    XfwfUpTabs, XfwfDownTabs, XfwfLeftTabs, XfwfRightTabs,
	} TabsOrientation;

#ifndef XtNforeground
#define XtNforeground "foreground"
#endif
#ifndef XtCForeground
#define XtCForeground "Foreground"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNorientation
#define XtNorientation "orientation"
#endif
#ifndef XtCOrientation
#define XtCOrientation "Orientation"
#endif
#ifndef XtRTabsOrientation
#define XtRTabsOrientation "TabsOrientation"
#endif

#ifndef XtNlefttabs
#define XtNlefttabs "lefttabs"
#endif
#ifndef XtCLefttabs
#define XtCLefttabs "Lefttabs"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNrighttabs
#define XtNrighttabs "righttabs"
#endif
#ifndef XtCRighttabs
#define XtCRighttabs "Righttabs"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNlabels
#define XtNlabels "labels"
#endif
#ifndef XtCLabels
#define XtCLabels "Labels"
#endif
#ifndef XtRStringArray
#define XtRStringArray "StringArray"
#endif

#ifndef XtNtabWidthPercentage
#define XtNtabWidthPercentage "tabWidthPercentage"
#endif
#ifndef XtCTabWidthPercentage
#define XtCTabWidthPercentage "TabWidthPercentage"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNcornerwidth
#define XtNcornerwidth "cornerwidth"
#endif
#ifndef XtCCornerwidth
#define XtCCornerwidth "Cornerwidth"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNcornerheight
#define XtNcornerheight "cornerheight"
#endif
#ifndef XtCCornerheight
#define XtCCornerheight "Cornerheight"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNtextmargin
#define XtNtextmargin "textmargin"
#endif
#ifndef XtCTextmargin
#define XtCTextmargin "Textmargin"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNtabcolor
#define XtNtabcolor "tabcolor"
#endif
#ifndef XtCTabcolor
#define XtCTabcolor "Tabcolor"
#endif
#ifndef XtRPixel
#define XtRPixel "Pixel"
#endif

#ifndef XtNfont
#define XtNfont "font"
#endif
#ifndef XtCFont
#define XtCFont "Font"
#endif
#ifndef XtRFontStruct
#define XtRFontStruct "FontStruct"
#endif

#ifndef XtNactivate
#define XtNactivate "activate"
#endif
#ifndef XtCActivate
#define XtCActivate "Activate"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

typedef struct _XfwfTabsClassRec *XfwfTabsWidgetClass;
typedef struct _XfwfTabsRec *XfwfTabsWidget;
externalref WidgetClass xfwfTabsWidgetClass;
_XFUNCPROTOEND
#endif /*_XfwfTabs_H_*/