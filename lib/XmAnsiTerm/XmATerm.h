/* Generated by wbuild from "XmATerm.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XmAnsiTerm_H_
#define _XmAnsiTerm_H_
_XFUNCPROTOBEGIN
void  XfwfAnsiWrite(
#if NeedFunctionPrototypes
Widget,char *,int 
#endif
);
typedef struct {
	    int rows, columns;
	} XfwfResizeInfo;

#ifndef XtNrows
#define XtNrows "rows"
#endif
#ifndef XtCRows
#define XtCRows "Rows"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNcolumns
#define XtNcolumns "columns"
#endif
#ifndef XtCColumns
#define XtCColumns "Columns"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNfont
#define XtNfont "font"
#endif
#ifndef XtCFont
#define XtCFont "Font"
#endif
#ifndef XtRString
#define XtRString "String"
#endif

#ifndef XtNboldfont
#define XtNboldfont "boldfont"
#endif
#ifndef XtCBoldfont
#define XtCBoldfont "Boldfont"
#endif
#ifndef XtRXFontStruct
#define XtRXFontStruct "XFontStruct"
#endif

#ifndef XtNmargin
#define XtNmargin "margin"
#endif
#ifndef XtCMargin
#define XtCMargin "Margin"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNkeyCallback
#define XtNkeyCallback "keyCallback"
#endif
#ifndef XtCKeyCallback
#define XtCKeyCallback "KeyCallback"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNresizeCallback
#define XtNresizeCallback "resizeCallback"
#endif
#ifndef XtCResizeCallback
#define XtCResizeCallback "ResizeCallback"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

typedef struct _XmAnsiTermClassRec *XmAnsiTermWidgetClass;
typedef struct _XmAnsiTermRec *XmAnsiTermWidget;
externalref WidgetClass xmAnsiTermWidgetClass;
_XFUNCPROTOEND
#endif /*_XmAnsiTerm_H_*/
