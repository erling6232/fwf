/****************************************************************************

	DirMgr.h

	This file contains the C declarations and definitions for the
	DirectoryMgr system.

	This system is intended to managed filtered and sorted directory
	lists.

 ****************************************************************************/

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

#ifndef _FWF_DIRECTORY_MGR_H_
#define	_FWF_DIRECTORY_MGR_H_

#include <Xfwf/RegExp.h>
#include <Xfwf/Directory.h>

/*---------------------------------------------------------------------------*

        Simple DirectoryMgr Interface

		DirectoryMgrSimpleOpen();
		DirectoryMgrSimpleRefilter();
		DirectoryMgrSimpleResort();

	Standard DirectoryMgr Interface

		DirectoryMgrCanOpen();
		DirectoryMgrOpen();
		DirectoryMgrClose();
		DirectoryMgrRefilter();
		DirectoryMgrRefresh();
		DirectoryMgrResort();

	Moving Around Items

		DirectoryMgrGotoItem();
		DirectoryMgrGotoNamedItem();
		DirectoryMgrRestart();
		DirectoryMgrGetIndex();
		DirectoryMgrCurrentEntry();
		DirectoryMgrNextEntry();
		DirectoryMgrPrevEntry();

	Utility Functions

		DirectoryMgrSimpleFilterFunc();
		DirectoryMgrSimpleSortingFunc();

	Comparison Functions

		DirectoryMgrCompareName();
		DirectoryMgrCompareSizeAscending();
		DirectoryMgrCompareSizeDescending();

	Macros

		DirectoryMgrDir();
		DirectoryMgrData();
		DirectoryMgrSortedPtrs();
		DirectoryMgrFilterFunc();
		DirectoryMgrCompFunc();
		DirectoryMgrFilterData();
		DirectoryMgrFreeFilterData();
		DirectoryMgrTotalCount();
		DirectoryMgrFilteredCount();
		DirectoryMgrCurrentIndex();


 *---------------------------------------------------------------------------*/

#ifndef PFI
typedef int (*PFI)();
#endif

typedef struct entry_cons
{
	DIR_ENTRY dir_entry;
	struct entry_cons *next;
} DIR_ENTRY_CONS;

typedef	DIR_ENTRY_CONS DirEntryCons;

typedef struct
{
	DIRECTORY dir;
	DIR_ENTRY *data;
	DIR_ENTRY **sorted_ptrs;
	size_t total_count;
	size_t filtered_count;
	PFI filter_func;
	regex_obj *filter_data;
	int free_filter_data;
	PFI comp_func;
	size_t current_index;
} DIRECTORY_MGR;

typedef	DIRECTORY_MGR DirectoryMgr;

#define	DIR_MGR_SORT_NONE			0
#define	DIR_MGR_SORT_NAME			1
#define	DIR_MGR_SORT_NAME_DIRS_FIRST		2
#define DIR_MGR_SORT_SIZE_ASCENDING		3
#define DIR_MGR_SORT_SIZE_DESCENDING		4
#define	DIR_MGR_SORT_ACCESS_ASCENDING		5
#define	DIR_MGR_SORT_ACCESS_DESCENDING		6

#define	DirectoryMgrDir(dm)		(&((dm)->dir))
#define	DirectoryMgrData(dm)		((dm)->data)
#define	DirectoryMgrSortedPtrs(dm)	((dm)->sorted_ptrs)
#define	DirectoryMgrFilterFunc(dm)	((dm)->filter_func)
#define	DirectoryMgrCompFunc(dm)	((dm)->comp_func)
#define	DirectoryMgrFilterData(dm)	((dm)->filter_data)
#define	DirectoryMgrFreeFilterData(dm)	((dm)->free_filter_data)
#define	DirectoryMgrTotalCount(dm)	((dm)->total_count)
#define	DirectoryMgrFilteredCount(dm)	((dm)->filtered_count)
#define	DirectoryMgrCurrentIndex(dm)	((dm)->current_index)

#if (!NeedFunctionPrototypes)

DirectoryMgr *	DirectoryMgrSimpleOpen();
int		DirectoryMgrSimpleRefilter();
int		DirectoryMgrSimpleResort();

int		DirectoryMgrCanOpen();
DirectoryMgr *	DirectoryMgrOpen();
void		DirectoryMgrClose();
int		DirectoryMgrRefilter();
int		DirectoryMgrRefresh();
void		DirectoryMgrResort();

int		DirectoryMgrGotoItem();
int		DirectoryMgrGotoNamedItem();
void		DirectoryMgrRestart();
int		DirectoryMgrGetIndex();
DirEntry *	DirectoryMgrCurrentEntry();
DirEntry *	DirectoryMgrNextEntry();
DirEntry *	DirectoryMgrPrevEntry();

int		DirectoryMgrSimpleFilterFunc();
int		DirectoryMgrSimpleSortingFunc();

int		DirectoryMgrCompareName();
int		DirectoryMgrCompareNameDirsFirst();
int		DirectoryMgrCompareSizeAscending();
int		DirectoryMgrCompareSizeDescending();
int		DirectoryMgrCompareLastAccessAscending();
int		DirectoryMgrCompareLastAccessDescending();

int		DirectoryMgrFilterName();

#else

DirectoryMgr *	DirectoryMgrSimpleOpen(const char *path, int sort_type,
			const char *pattern);
int		DirectoryMgrSimpleRefilter(DirectoryMgr *dm, const char *pattern);
int		DirectoryMgrSimpleResort(DirectoryMgr *dm, int sort_type);

int		DirectoryMgrCanOpen(char *path);
DirectoryMgr *	DirectoryMgrOpen(const char *path, PFI c_func, PFI f_func,
			regex_obj *f_data, int free_data);
void		DirectoryMgrClose(DirectoryMgr *dm);
int		DirectoryMgrRefilter(DirectoryMgr *dm, PFI f_func,
			regex_obj *f_data, int f_free);
int		DirectoryMgrRefresh(DirectoryMgr *dm);
void		DirectoryMgrResort(DirectoryMgr *dm, PFI c_func);

int		DirectoryMgrGotoItem(DirectoryMgr *dm, int i);
int		DirectoryMgrGotoNamedItem(DirectoryMgr *dm, char *name);
void		DirectoryMgrRestart(DirectoryMgr *dm);
DirEntry *	DirectoryMgrCurrentEntry(DirectoryMgr *dm);
DirEntry *	DirectoryMgrNextEntry(DirectoryMgr *dm);
DirEntry *	DirectoryMgrPrevEntry(DirectoryMgr *dm);

int             DirectoryMgrSimpleFilterFunc(const char *pattern, PFI *ff_ptr, regex_obj **fd_ptr);
int		DirectoryMgrSimpleSortingFunc(int sort_type, PFI *sf_ptr);

int		DirectoryMgrCompareName(DirEntry **e1p, DirEntry **e2p);
int		DirectoryMgrCompareNameDirsFirst(DirEntry **e1p,
			DirEntry **e2p);
int		DirectoryMgrCompareSizeAscending(DirEntry **e1p,
			DirEntry **e2p);
int		DirectoryMgrCompareSizeDescending(DirEntry **e1p,
			DirEntry **e2p);
int		DirectoryMgrCompareLastAccessAscending(DirEntry **e1p,
			DirEntry **e2p);
int		DirectoryMgrCompareLastAccessDescending(DirEntry **e1p,
			DirEntry **e2p);

int             DirectoryMgrFilterName(DirEntry *de, regex_obj *fsm);

#endif

#endif
