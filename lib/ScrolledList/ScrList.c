/*****************************************************************************

	ScrolledList.c

	This file contains the C code for the ScrolledList widget, which
	acts as a vertically scrolling list of text, from which, items can
	be selected.

******************************************************************************/

/*
 * Author:
 * 	Brian Totty
 * 	Department of Computer Science
 * 	University Of Illinois at Urbana-Champaign
 *	1304 West Springfield Avenue
 * 	Urbana, IL 61801
 * 
 * 	totty@cs.uiuc.edu
 * 	
 */ 

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/StringDefs.h>
#include <X11/IntrinsicP.h>
#include <X11/Intrinsic.h>
#include <X11/CompositeP.h>
#include <X11/Composite.h>
#include <X11/Xaw/ViewportP.h>
#include <X11/Xaw/Viewport.h>
#include <Xfwf/MultiListP.h>
#include <Xfwf/MultiList.h>
#include <Xfwf/ScrListP.h>
#include <Xfwf/ScrList.h>

/*---------------------------------------------------------------------------*

                       D E C L A R A T I O N S

 *---------------------------------------------------------------------------*/

#define	SUPERCLASS		(&compositeClassRec)

#define max(a,b)		((a) > (b) ? (a) : (b))
#define min(a,b)		((a) < (b) ? (a) : (b))
#define abs(a)			((a) < 0 ? -(a) : (a))
#define XtStrlen(s)		((s) ? strlen(s) : 0)

#define offset(field)		XtOffset(XfwfScrolledListWidget,	\
					 scrolledList.field)
#define coffset(field)		XtOffset(Widget,core.field)

#define	MyData(w)		((w)->scrolledList)
#define	CoreData(w)		((w)->core)

#if (!NeedFunctionPrototypes)

static void		MultiListCallbackHandler();
static void		ClassInitialize();
static void		Initialize();
static void		Realize();
static void		Destroy();
static void		Resize();
static Boolean		SetValues();
static XtGeometryResult	GeometryManager();
static XtGeometryResult	PreferredGeometry();
static void		ReCalcChildren();

#else

static void		MultiListCallbackHandler(Widget w, Widget self,
				XfwfMultiListReturnStruct *call_data);
static void		ClassInitialize(void);
static void		Initialize(Widget request, Widget new);
static void		Realize(Widget gw, XtValueMask *valueMask,
				XSetWindowAttributes *attrs);
static void		Destroy(Widget gw);
static void		Resize(Widget gw);
static Boolean		SetValues(Widget gcurrent, Widget grequest,
				Widget gnew);
static XtGeometryResult	GeometryManager(Widget w, XtWidgetGeometry *request,
				XtWidgetGeometry *reply);
static XtGeometryResult	PreferredGeometry(XfwfScrolledListWidget slw,
				XtWidgetGeometry *parent_idea,
				XtWidgetGeometry *our_idea);
static void		ReCalcChildren(XfwfScrolledListWidget w);

#endif

/*---------------------------------------------------------------------------*

              R E S O U R C E    I N I T I A L I Z A T I O N

 *---------------------------------------------------------------------------*/

static XtResource resources[] =
{
	{XtNwidth,XtCWidth,XtRDimension,sizeof(Dimension),
		coffset(width),XtRString,"200"},
	{XtNheight,XtCHeight,XtRDimension,sizeof(Dimension),
		coffset(height),XtRString,"500"},
	{XtNbackground,XtCBackground,XtRPixel,sizeof(Pixel),
		coffset(background_pixel),XtRString,"white"},
	{XtNlist,XtCList,XtRPointer,sizeof(char **),
		offset(item_array),XtRPointer,NULL},
	{XtNnumberStrings,XtCNumberStrings,XtRInt,sizeof(int),
		offset(item_count),XtRInt,0},
	{XtNsensitiveArray,XtCList,XtRPointer,sizeof(Boolean *),
		offset(sensitive_array),XtRPointer,NULL},
	{XtNcallback, XtCCallback, XtRCallback, sizeof(caddr_t),
		offset(callback), XtRCallback, NULL}
};

#undef offset
#undef coffset

/*---------------------------------------------------------------------------*

                    C L A S S    A L L O C A T I O N

 *---------------------------------------------------------------------------*/

XfwfScrolledListClassRec xfwfScrolledListClassRec =
{
	{
		/* superclass		*/	(WidgetClass)SUPERCLASS,
		/* class_name		*/	"XfwfScrolledList",
		/* widget_size		*/	sizeof(XfwfScrolledListRec),
		/* class_initialize	*/	(XtProc)ClassInitialize,
		/* class_part_initialize*/	NULL,
		/* class_inited		*/	FALSE,
		/* initialize		*/	(XtInitProc)Initialize,
		/* initialize_hook	*/	NULL,
		/* realize		*/	(XtRealizeProc)Realize,
		/* actions		*/	NULL,
		/* num_actions		*/	0,
		/* resources		*/	resources,
		/* resource_count	*/	XtNumber(resources),
		/* xrm_class		*/	NULLQUARK,
		/* compress_motion	*/	TRUE,
		/* compress_exposure	*/	TRUE,
		/* compress_enterleave	*/	TRUE,
		/* visible_interest	*/	FALSE,
		/* destroy		*/	(XtWidgetProc)Destroy,
		/* resize		*/	(XtWidgetProc)Resize,
		/* expose		*/	NULL,
		/* set_values		*/	(XtSetValuesFunc)SetValues,
		/* set_values_hook	*/	NULL,
		/* set_values_almost	*/	XtInheritSetValuesAlmost,
		/* get_values_hook	*/	NULL,
		/* accept_focus		*/	NULL,
		/* version		*/	XtVersion,
		/* callback_private	*/	NULL,
		/* tm_table		*/	NULL,
		/* query_geometry       */	(XtGeometryHandler)
							PreferredGeometry,
		/* display_accelerator  */	XtInheritDisplayAccelerator,
		/* extension            */	NULL
	}, /* Core Part */
	{
		/* geometry_manager     */	GeometryManager,
		/* change_managed       */	XtInheritChangeManaged,
		/* insert_child         */	XtInheritInsertChild,
		/* delete_child         */	XtInheritDeleteChild,
		/* extension            */	NULL
	}, /* Composite Part */		
	{
		/* no extra class data  */	0
	}  /* XfwfScrolledList Part */
};

WidgetClass xfwfScrolledListWidgetClass =
	(WidgetClass)&xfwfScrolledListClassRec;

/*---------------------------------------------------------------------------*

                    E X P O R T E D    M E T H O D S

 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------*

	MultiListCallbackHandler(w,client_data,call_data)

	This routine gets called when the user clicks on a
	MultiList item.  It in turn calls any callbacks in the
	ScrolledList widget.

 *---------------------------------------------------------------*/

static void MultiListCallbackHandler(w,self,call_data)
Widget w;
Widget self;
XfwfMultiListReturnStruct *call_data;
{
	Boolean highlighted,sensitive;
	XfwfScrolledListReturnStruct ret_value;

	if (call_data->num_selected)
	{
		ret_value.index = call_data->selected_items[0];
		XfwfMultiListGetItemInfo((XfwfMultiListWidget)w,
			ret_value.index,&(ret_value.string),
			&highlighted,&sensitive);
	}
	    else
	{
		ret_value.index = -1;
		ret_value.string = NULL;
	}
	XtCallCallbacks(self,XtNcallback,(caddr_t)(&ret_value));
}


/*---------------------------------------------------------------*

	ClassInitialize()

	This procedure is called by the X toolkit to initialize
	the class.  The hook to this routine is in the
	class_initialize part of the core part of the class.

 *---------------------------------------------------------------*/

static void ClassInitialize()
{
} /* End ClassInitialize */



/*---------------------------------------------------------------*

	Initialize()

	This procedure is called by the X toolkit to initialize
	the widget instance.  The hook to this routine is in the
	initialize part of the core part of the class.

 *---------------------------------------------------------------*/

/* ARGSUSED */
static void Initialize(request,new)
Widget request,new;
{
	XfwfScrolledListWidget w;
	Arg args[10];

/*
	static char translations[] =
		"<Btn1Down>:	Select()\n\
		 <Btn1Up>:	Notify()\n";
*/

	w = (XfwfScrolledListWidget)new;

	if (CoreData(new).width <= 0) CoreData(new).width = 200;
	if (CoreData(new).height <= 0) CoreData(new).height = 300;

	XtSetArg(args[0],XtNuseRight,True);
	XtSetArg(args[1],XtNwidth,CoreData(new).width);
	XtSetArg(args[2],XtNheight,CoreData(new).height);
	XtSetArg(args[3],XtNallowVert,True);
	XtSetArg(args[4],XtNforceBars,True);
	MyData(w).viewport = XtCreateManagedWidget("viewport",
		viewportWidgetClass,(Widget)w,args,5);
	XtSetArg(args[0],XtNlist,MyData(w).item_array);
	XtSetArg(args[1],XtNnumberStrings,MyData(w).item_count);
	XtSetArg(args[2],XtNsensitiveArray,MyData(w).sensitive_array);
	XtSetArg(args[3],XtNdefaultColumns,1);
	XtSetArg(args[4],XtNborderWidth,0);
	XtSetArg(args[5],XtNx,1);
	XtSetArg(args[6],XtNy,1);
	XtSetArg(args[7],XtNmaxSelectable,1);
/*
	XtSetArg(args[8],XtNtranslations,
		 XtParseTranslationTable(translations));
*/
	MyData(w).list = XtCreateManagedWidget("multilist",
		xfwfMultiListWidgetClass,MyData(w).viewport,args,8);

	XtAddCallback(MyData(w).list,XtNcallback,
		(XtCallbackProc)MultiListCallbackHandler,(caddr_t)w);
} /* End Initialize */



/*---------------------------------------------------------------*

	Realize()

	This function is called to realize a ScrolledList widget.

 *---------------------------------------------------------------*/

static void Realize(gw,valueMask,attrs)
Widget gw;
XtValueMask *valueMask;
XSetWindowAttributes *attrs;
{
	XfwfScrolledListWidget w;

	w = (XfwfScrolledListWidget)gw;
	XtCreateWindow(gw,InputOutput,(Visual *)CopyFromParent,
		*valueMask,attrs);
	XtRealizeWidget(MyData(w).viewport);

	Resize(gw);
} /* End Realize */



/*---------------------------------------------------------------*

	Destroy()

	This function is called to destroy a scrolledList widget.

 *---------------------------------------------------------------*/

static void Destroy(gw)
Widget gw;
{
	XfwfScrolledListWidget w;

	w = (XfwfScrolledListWidget)gw;
	XtDestroyWidget(MyData(w).viewport);
	XtDestroyWidget(MyData(w).list);
} /* End Destroy */



/*---------------------------------------------------------------*

	Resize()

	This function is called to resize a scrolledList widget.

 *---------------------------------------------------------------*/

static void Resize(gw) 
Widget gw;
{
	XfwfScrolledListWidget w;

	w = (XfwfScrolledListWidget)gw;
	ReCalcChildren(w);
} /* End Resize */



/*---------------------------------------------------------------*

	Boolean SetValues(wcurrent,wrequest,wnew)

	This isn't inplemented yet, meaning you can't change
	resources dynamically.

 *---------------------------------------------------------------*/

/* ARGSUSED */
static Boolean SetValues(wcurrent,wrequest,wnew)
Widget wcurrent,wrequest,wnew;
{
	Boolean redraw,recalc;
	XfwfScrolledListWidget csl,rsl,nsl;

	csl = (XfwfScrolledListWidget)wcurrent;
	rsl = (XfwfScrolledListWidget)wrequest;
	nsl = (XfwfScrolledListWidget)wnew;

	redraw = False;
	recalc = False;

	if ((MyData(csl).item_array != MyData(nsl).item_array) ||
	    (MyData(csl).item_count != MyData(nsl).item_count) ||
	    (MyData(csl).sensitive_array != MyData(nsl).sensitive_array))
	{
		XfwfScrolledListSetList((Widget)csl,
			MyData(nsl).item_array,
			MyData(nsl).item_count,True,
			MyData(nsl).sensitive_array);
		redraw = recalc = True;
	}

	return(redraw);
} /* End SetValues */


/*---------------------------------------------------------------*

	GeometryManager(w,request,reply)

	This routine acts as the geometry_manager method for the
	ScrolledList widget.  It is called when a child wants to
	resize/reposition itself.

	Currently, we allow all requests.

 *---------------------------------------------------------------*/

/* ARGSUSED */
static XtGeometryResult GeometryManager(w,request,reply)
Widget w;
XtWidgetGeometry *request;
XtWidgetGeometry *reply;
{
	return(XtGeometryYes);
} /* End GeometryManager */


/*---------------------------------------------------------------------------*

	PreferredGeometry(slw,parent_idea,our_idea)

	This routine is called by the parent to tell us about the
	parent's idea of our width and/or height.  We then suggest
	our preference through <our_idea> and return the information
	to the parent.

 *---------------------------------------------------------------------------*/

static XtGeometryResult PreferredGeometry(slw,parent_idea,our_idea)
XfwfScrolledListWidget slw;
XtWidgetGeometry *parent_idea,*our_idea;
{
	Arg multilist_args[2],slist_args[2];
	Dimension col_width,row_height,num_rows,current_width,current_height;
    
	if (!XtIsRealized((Widget)slw)) return(XtGeometryYes);

	XtSetArg(multilist_args[0],XtNrowHeight,&row_height);
	XtSetArg(multilist_args[1],XtNcolumnWidth,&col_width);
	XtSetArg(slist_args[0],XtNwidth,&current_width);
	XtSetArg(slist_args[1],XtNheight,&current_height);
	XtGetValues(MyData(slw).list,multilist_args,2);
	XtGetValues((Widget)slw,slist_args,2);

	row_height = max(1,row_height);
	num_rows = max(1,(parent_idea->height / row_height));

	our_idea->request_mode = (CWWidth | CWHeight);
	our_idea->width = col_width;
	our_idea->height = num_rows * row_height;

	if ((our_idea->width == current_width) &&
	    (our_idea->height == current_height))
	{
		return(XtGeometryNo);		/* Prefer To Stay As Is */
	}

	if ((our_idea->width == parent_idea->width) &&
	    (our_idea->height == parent_idea->height))
	{
		return(XtGeometryYes);		/* Proposed Change Is Fine */
	}

	return(XtGeometryAlmost);
} /* End PreferredGeometry */


/*---------------------------------------------------------------------------*

                     L O C A L    R O U T I N E S

 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------*

	ReCalcChildren(w)

	This routine takes a ScrolledList widget <w> and updates
	the widths and positions of the child widgets.

 *---------------------------------------------------------------*/

static void ReCalcChildren(w)
XfwfScrolledListWidget w;
{
	int wid_h,wid_w;

	wid_w = CoreData(w).width;
	wid_h = CoreData(w).height;

	XtResizeWidget(MyData(w).viewport,wid_w,wid_h,1);
} /* End ReCalcChildren */


/*===========================================================================*

                    E X P O R T E D    F U N C T I O N S

 *===========================================================================*/

/*---------------------------------------------------------------------------*

	XfwfScrolledListSetList(w,newlist,items,resize,sensitive_array)

	This routine tries to set the string array to the new array
	<newlist>.  <items> is the count of strings.  If <items> is 0
	and the array is NULL terminated, the number of strings will be
	automatically counted.	The <resize> flag indicates if we want
	the widget to try to resize itself to hold the new array.  The
	<sensitive_array> parameter (if non-NULL) contains an array of
	Booleans representing the sensitivity of the list items.

 *---------------------------------------------------------------------------*/

void XfwfScrolledListSetList(w,newlist,items,resize,sensitive_array)
Widget w;
char **newlist;
int items;
Boolean resize;
Boolean *sensitive_array;
{
	XfwfScrolledListWidget sw;

	sw = (XfwfScrolledListWidget)w;
	XfwfMultiListSetNewData((XfwfMultiListWidget)(MyData(sw).list),
		newlist,items,0,resize,sensitive_array);
	MyData(sw).item_array = newlist;
	MyData(sw).item_count = items;
	MyData(sw).sensitive_array = sensitive_array;
} /* End XfwfScrolledListSetList */


/*---------------------------------------------------------------------------*

	XfwfScrolledListUnhighlightAll(w)

	This routine unhighlights all highlighted items in the
	ScrolledList widget <w>.

 *---------------------------------------------------------------------------*/

void XfwfScrolledListUnhighlightAll(w)
Widget w;
{
	XfwfScrolledListWidget sw;

	sw = (XfwfScrolledListWidget)w;
	XfwfMultiListUnhighlightAll((XfwfMultiListWidget)(MyData(sw).list));
} /* End XfwfScrolledListUnhighlightAll */


/*---------------------------------------------------------------------------*

	XfwfScrolledListHighlightItem(w,item_index)

	This routine highlights the item with index number <item_index>.

 *---------------------------------------------------------------------------*/

void XfwfScrolledListHighlightItem(w,item_index)
Widget w;
int item_index;
{
	XfwfScrolledListWidget sw;

	sw = (XfwfScrolledListWidget)w;
	XfwfMultiListHighlightItem((XfwfMultiListWidget)(MyData(sw).list),
		item_index);
} /* End XfwfScrolledListHighlightItem */


/*---------------------------------------------------------------------------*

	XfwfScrolledListGetHighlighted(w)

	This routine returns the current highlighted item.

 *---------------------------------------------------------------------------*/

XfwfScrolledListReturnStruct *XfwfScrolledListGetHighlighted(sw)
XfwfScrolledListWidget sw;
{
	XfwfMultiListReturnStruct *pl_ret;
	static XfwfScrolledListReturnStruct sl_ret; /* Added static [BB] */

	sl_ret.multilist = MyData(sw).list;

	pl_ret = XfwfMultiListGetHighlighted((XfwfMultiListWidget)
		(MyData(sw).list));
	if (pl_ret->num_selected != 0)
	{
		sl_ret.string = pl_ret->string;
		sl_ret.index = pl_ret->item;
		sl_ret.highlighted = True;
	}
	    else
	{
		sl_ret.string = NULL;
		sl_ret.index = -1;
		sl_ret.highlighted = False;
	}
	return(&sl_ret);
} /* End XfwfScrolledListGetHighlighted */


/*---------------------------------------------------------------------------*

	XfwfScrolledListIsHighlighted(w,item_index)

	This routine returns a boolean that indicates if the item
	with index <item_index> was highlighted or not.

 *---------------------------------------------------------------------------*/

Boolean XfwfScrolledListIsHighlighted(w,item_index)
Widget w;
int item_index;
{
	XfwfScrolledListWidget sw;

	sw = (XfwfScrolledListWidget)w;
	return(XfwfMultiListIsHighlighted((XfwfMultiListWidget)
		(MyData(sw).list),item_index));
} /* End XfwfScrolledListIsHighlighted */


/*---------------------------------------------------------------------------*

	XfwfScrolledListGetItem(w,item_index,str_ptr,high_ptr,sens_ptr)

	This routine returns information about a numbered item including
	the name of the item, whether it is highlighted, and its
	sensitivity.  If the item index number does not correspond to an
	item, False is returned, else True is returned.

 *---------------------------------------------------------------------------*/

Boolean XfwfScrolledListGetItem(w,item_index,str_ptr,high_ptr,sens_ptr)
Widget w;
int item_index;
String *str_ptr;
Boolean *high_ptr,*sens_ptr;
{
	XfwfScrolledListWidget sw;

	sw = (XfwfScrolledListWidget)w;
	return(XfwfMultiListGetItemInfo((XfwfMultiListWidget)(MyData(sw).list),
		item_index,str_ptr,high_ptr,sens_ptr));
} /* End XfwfScrolledListGetItem */
