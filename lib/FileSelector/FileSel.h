/*****************************************************************************

	FileSelector.h

	This file contains the user includes for the FileSelector widget.

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

#ifndef _FILESELECTOR_H_
#define _FILESELECTOR_H_

#include <Xfwf/ScrList.h>
#include <Xfwf/DirMgr.h>

extern WidgetClass	xfwfFileSelectorWidgetClass;

typedef struct _XfwfFileSelectorClassRec *XfwfFileSelectorWidgetClass;
typedef struct _XfwfFileSelectorRec      *XfwfFileSelectorWidget;

#define	XtNpathname XtNcurrentDirectory		/* For Compatibility */

#ifndef XtNtitle
#define	XtNtitle			"title"
#endif

#ifndef XtNcurrentDirectory
#define	XtNcurrentDirectory		"currentDirectory"
#endif
#define	XtNcurrentFile			"currentFile"
#define	XtNsortMode			"sortMode"
#define	XtNpattern			"pattern"
#define	XtNokButtonCallback		"okButtonCallback"
#define	XtNcancelButtonCallback		"cancelButtonCallback"
#define	XtNselectionChangeCallback	"selectionChangeCallback"
#define	XtNshowOkButton			"showOkButton"
#define	XtNshowCancelButton		"showCancelButton"
#define	XtNfileSelected			"fileSelected"
#define	XtNflagLinks			"flagLinks"
#define	XtNcheckExistence		"checkExistence"

#define	XtCPathname			"Pathname"
#define	XtCFilename			"Filename"

typedef struct _XfwfFileSelectorOkButtonReturnStruct
{
	char *path;
	char *file;
	char *file_box_text;
} XfwfFileSelectorOkButtonReturnStruct;

typedef struct _XfwfFileSelectorSelectionChangeReturnStruct
{
	Boolean file_selected;
	char *path;
	char *file;
} XfwfFileSelectorSelectionChangeReturnStruct;

typedef struct _XfwfFileSelectorStatusStruct
{
	Boolean file_selected;
	char *path;
	char *file;
	char *file_box_text;
} XfwfFileSelectorStatusStruct;

/*---------------------------------------------------------------------------*

                  E X T E R N A L    F U N C T I O N S

 *---------------------------------------------------------------------------*/

#if (!NeedFunctionPrototypes)

void	XfwfFileSelectorChangeDirectory();
void	XfwfFileSelectorRefresh();
void	XfwfFileSelectorGetStatus();

#else

void	XfwfFileSelectorChangeDirectory(XfwfFileSelectorWidget fsw, char *dir);
void	XfwfFileSelectorRefresh(XfwfFileSelectorWidget fsw);
void	XfwfFileSelectorGetStatus(XfwfFileSelectorWidget fsw,
				  XfwfFileSelectorStatusStruct *ssp);

#endif
#endif
