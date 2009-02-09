/* Generated by wbuild from "IconBox.w"
** (generator version $Revision$ of $Date$)
*/
#ifndef _XfwfIconBox_H_
#define _XfwfIconBox_H_
#include <Xfwf/Board.h>
_XFUNCPROTOBEGIN
#include <Xfwf/Icon.h>
typedef struct {
            String icon;
            int flags;
            String label;
        } XfwfIconListItem;

typedef XfwfIconListItem * XfwfIconList;

typedef struct {
	    Widget sender;
            int target;
            int n;
            int *droplings;
        } XfwfItemDropInfo;

void XfwfCleanUp(
#if NeedFunctionPrototypes
Widget
#endif
);
void XfwfCanonicalOrder(
#if NeedFunctionPrototypes
Widget
#endif
);
void XfwfCacheIcon(
#if NeedFunctionPrototypes
Widget,String ,Icon 
#endif
);
#ifndef XtNlist
#define XtNlist "list"
#endif
#ifndef XtCList
#define XtCList "List"
#endif
#ifndef XtRXFwfIconList
#define XtRXFwfIconList "XFwfIconList"
#endif

#ifndef XtNhorizontalGrid
#define XtNhorizontalGrid "horizontalGrid"
#endif
#ifndef XtCHorizontalGrid
#define XtCHorizontalGrid "HorizontalGrid"
#endif
#ifndef XtRDimension
#define XtRDimension "Dimension"
#endif

#ifndef XtNverticalGrid
#define XtNverticalGrid "verticalGrid"
#endif
#ifndef XtCVerticalGrid
#define XtCVerticalGrid "VerticalGrid"
#endif
#ifndef XtRDimension
#define XtRDimension "Dimension"
#endif

#ifndef XtNtopskip
#define XtNtopskip "topskip"
#endif
#ifndef XtCTopskip
#define XtCTopskip "Topskip"
#endif
#ifndef XtRInt
#define XtRInt "Int"
#endif

#ifndef XtNitemSelect
#define XtNitemSelect "itemSelect"
#endif
#ifndef XtCItemSelect
#define XtCItemSelect "ItemSelect"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNitemDeselect
#define XtNitemDeselect "itemDeselect"
#endif
#ifndef XtCItemDeselect
#define XtCItemDeselect "ItemDeselect"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNitemActivate
#define XtNitemActivate "itemActivate"
#endif
#ifndef XtCItemActivate
#define XtCItemActivate "ItemActivate"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNitemDrop
#define XtNitemDrop "itemDrop"
#endif
#ifndef XtCItemDrop
#define XtCItemDrop "ItemDrop"
#endif
#ifndef XtRCallback
#define XtRCallback "Callback"
#endif

#ifndef XtNlabelFont
#define XtNlabelFont "labelFont"
#endif
#ifndef XtCLabelFont
#define XtCLabelFont "LabelFont"
#endif
#ifndef XtRFontStruct
#define XtRFontStruct "FontStruct"
#endif

#ifndef XtNiconTranslations
#define XtNiconTranslations "iconTranslations"
#endif
#ifndef XtCIconTranslations
#define XtCIconTranslations "IconTranslations"
#endif
#ifndef XtRString
#define XtRString "String"
#endif

#ifndef XtNdragCursor
#define XtNdragCursor "dragCursor"
#endif
#ifndef XtCDragCursor
#define XtCDragCursor "DragCursor"
#endif
#ifndef XtRCursor
#define XtRCursor "Cursor"
#endif

typedef struct _XfwfIconBoxClassRec *XfwfIconBoxWidgetClass;
typedef struct _XfwfIconBoxRec *XfwfIconBoxWidget;
externalref WidgetClass xfwfIconBoxWidgetClass;
_XFUNCPROTOEND
#endif /*_XfwfIconBox_H_*/
