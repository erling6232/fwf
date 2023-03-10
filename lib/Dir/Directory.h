/****************************************************************************

	Directory.h

	This file contains the C definitions and declarations for the
	Directory.c directory iteration code.

	This code is intended to be used as a convenient, machine
	independent interface to iterate through the contents of a
	directory.

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

#ifndef _FWF_DIRECTORY_H_
#define _FWF_DIRECTORY_H_

#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef HAVE_DIRENT_H
# include <dirent.h>
# define NAMLEN(dirent) strlen ((dirent)->d_name)
#else
# define dirent direct
# define NAMLEN(dirent) ((dirent)->d_namlen)
# ifdef HAVE_SYS_NDIR_H
#  include <sys/ndir.h>
# endif
# ifdef HAVE_SYS_DIR_H
#  include <sys/dir.h>
# endif
# ifdef HAVE_NDIR_H
#  include <ndir.h>
# endif
#endif

#ifndef _SYS_NAME_MAX
#ifndef MAXNAMLEN
ERROR, ONE OF THESE MUST BE DEFINED
#else
#define	MAX_NAME_LENGTH	MAXNAMLEN
#endif
#else
#define	MAX_NAME_LENGTH	_SYS_NAME_MAX
#endif

#ifndef TRUE
#define TRUE				1
#endif

#ifndef FALSE
#define	FALSE				0
#endif

#define	PERM_READ			4
#define	PERM_WRITE			2	
#define	PERM_EXECUTE			1

#define	F_TYPE_DIR			1
#define	F_TYPE_FILE			2
#define	F_TYPE_CHAR_SPECIAL		3
#define	F_TYPE_BLOCK_SPECIAL		4
#define	F_TYPE_SYM_LINK			5
#define	F_TYPE_SOCKET			6
#define	F_TYPE_FIFO			7

/*--------------------------------------------------------------------------*

            D A T A    T Y P E    A C C E S S    M A C R O S

 *--------------------------------------------------------------------------*/

	/* Directory: Directory Iterator */

#define	DirectoryDir(dp)		((dp)->filep)
#define	DirectoryPath(dp)		((dp)->path)

	/* FileInfo: Information About A File Or Link */

#define	FileInfoProt(fi)		((fi)->protections)
#define FileInfoOrigMode(fi)		((fi)->orig_mode)
#define	FileInfoUserID(fi)		((fi)->user_id)
#define	FileInfoGroupID(fi)		((fi)->group_id)
#define	FileInfoFileSize(fi)		((fi)->size)
#define	FileInfoLastAccess(fi)		((fi)->last_access)
#define	FileInfoLastModify(fi)		((fi)->last_modify)
#define	FileInfoLastStatusChange(fi)	((fi)->last_status_change)

#define	FIProt(fi)			FileInfoProt(fi)
#define FIOrigMode(fi)			FileInfoOrigMode(fi)
#define	FIUserID(fi)			FileInfoUserID(fi)
#define	FIGroupID(fi)			FileInfoGroupID(fi)
#define	FIFileSize(fi)			FileInfoFileSize(fi)
#define	FILastAccess(fi)		FileInfoLastAccess(fi)
#define	FILastModify(fi)		FileInfoLastModify(fi)
#define	FILastStatusChange(fi)		FileInfoLastStatusChange(fi)

	/* FType: File Type Macros */

#define	FTypeIsDir(ft)			((ft) == F_TYPE_DIR)
#define	FTypeIsFile(ft)			((ft) == F_TYPE_FILE)
#define	FTypeIsCharSpecial(ft)		((ft) == F_TYPE_CHAR_SPECIAL)
#define	FTypeIsBlockSpecial(ft)		((ft) == F_TYPE_BLOCK_SPECIAL)
#define	FTypeIsSymLink(ft)		((ft) == F_TYPE_SYM_LINK)
#define	FTypeIsSocket(ft)		((ft) == F_TYPE_SOCKET)
#define	FTypeIsFifo(ft)			((ft) == F_TYPE_FIFO)

	/* DirEntry: Information About A Item In A Directory */

#define	DirEntryFileName(fi)		((fi)->filename)
#define	DirEntryType(fi)		((fi)->file_type)
#define	DirEntrySelfInfo(fi)		(&((fi)->self_info))
#define	DirEntryActualInfo(fi)		(&((fi)->actual_info))

#define	DirEntryIsBrokenLink(fi)	((fi)->broken_link)
#define	DirEntryIsDirectoryLink(fi)	((fi)->directory_link)
#define	DirEntryIsDir(fi)		(FTypeIsDir(DirEntryType(fi)))
#define	DirEntryIsFile(fi)		(FTypeIsFile(DirEntryType(fi)))
#define	DirEntryIsCharSpecial(fi)	(FTypeIsCharSpecial(DirEntryType(fi)))
#define	DirEntryIsBlockSpecial(fi)	(FTypeIsBlockSpecial(DirEntryType(fi)))
#define	DirEntryIsSymLink(fi)		(FTypeIsSymLink(DirEntryType(fi)))
#define	DirEntryIsSocket(fi)		(FTypeIsSocket(DirEntryType(fi)))
#define	DirEntryIsFifo(fi)		(FTypeIsFifo(DirEntryType(fi)))
#define	DirEntryLeadsToDir(fi)		(DirEntryIsDir(fi) ||		\
					 DirEntryIsDirectoryLink(fi))

#define	DirEntryProt(d)			FIProt(DirEntrySelfInfo(d))
#define DirEntryOrigMode(d)		FIOrigMode(DirEntrySelfInfo(d))
#define	DirEntryUserID(d)		FIUserID(DirEntrySelfInfo(d))
#define	DirEntryGroupID(d)		FIGroupID(DirEntrySelfInfo(d))
#define	DirEntryFileSize(d)		FIFileSize(DirEntrySelfInfo(d))
#define	DirEntryLastAccess(d)		FILastAccess(DirEntrySelfInfo(d))
#define	DirEntryLastModify(d)		FILastModify(DirEntrySelfInfo(d))
#define	DirEntryLastStatusChange(d)	FILastStatusChange(DirEntrySelfInfo(d))

/*--------------------------------------------------------------------------*

             D A T A    T Y P E    D E F I N I T I O N S

 *--------------------------------------------------------------------------*/

	/* Directory: Directory Iterator */

typedef struct
{
	DIR *filep;
	char path[MAXPATHLEN + 2];
} DIRECTORY;

typedef DIRECTORY Directory;

	/* FileInfo: Information About A File Or Link */

typedef struct
{
	mode_t protections;
	mode_t orig_mode;
	uid_t user_id;
	gid_t group_id;
	off_t size;
	time_t last_access;
	time_t last_modify;
	time_t last_status_change;
} FILE_INFO;

typedef	FILE_INFO FileInfo;

	/* DirEntry: Information About A Item In A Directory */

typedef struct
{
	char filename[MAX_NAME_LENGTH + 1];
	mode_t file_type;
	short broken_link;
	short directory_link;
	FileInfo self_info;
	FileInfo actual_info;
} DIR_ENTRY;

typedef DIR_ENTRY DirEntry;

/*--------------------------------------------------------------------------*

        L O W    L E V E L    D I R E C T O R Y    I N T E R F A C E

 *--------------------------------------------------------------------------*/

#if (!NeedFunctionPrototypes)

int	DirectoryOpen();
void	DirectoryRestart();
void	DirectoryClose();
off_t	DirectoryTellPosition();
void	DirectorySetPosition();
int	DirectoryReadNextEntry();
char *	DirectoryPathExpand();
void	DirEntryDump();

#else

int	DirectoryOpen(const char *dir_name, Directory *dp);
void	DirectoryRestart(Directory *dp);
void	DirectoryClose(Directory *dp);
off_t	DirectoryTellPosition(Directory *dp);
void	DirectorySetPosition(Directory *dp, off_t pos);
int	DirectoryReadNextEntry(Directory *dp, DirEntry *de);
char *	DirectoryPathExpand(const char *old_path, char *new_path);
void	DirEntryDump(FILE *fp, DirEntry *de);

#endif

#endif


