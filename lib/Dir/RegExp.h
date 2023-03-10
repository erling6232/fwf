/****************************************************************************

	RegExp.h

	This file contains the C definitions and declarations for
	the regular expression matching code.

	The routines supported act as a more friendly, user level
	interface to the regexp regular expression matching system.

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

#ifndef _FWF_REGEXP_H_
#define	_FWF_REGEXP_H_

#include <stdio.h>

#ifdef HAVE_REGEX_H
#  include <regex.h>
   typedef regex_t regex_obj;
#elif HAVE_REGEXP_H
#  include <regexp.h>
   typedef char    regex_obj;
#else
   typedef char    regex_obj;
#endif

#if (!NeedFunctionPrototypes)

void	RegExpCompile();
int	RegExpMatch();
void	_RegExpError();
void	RegExpPatternToRegExp();

#else

void    RegExpCompile(const char *regexp, regex_obj *fsm_ptr, int fsm_length);
int     RegExpMatch(const char *string, const regex_obj *fsm_ptr);
void	_RegExpError(int val);
void	RegExpPatternToRegExp(const char *pattern, char *reg_exp);

#endif

#ifndef TRUE
#define TRUE				1
#endif

#ifndef FALSE
#define	FALSE				0
#endif

#if HAVE_REGEXP_H
#define	INIT		register char *sp = instring;
#define	GETC()		(*sp++)
#define	PEEKC()		(*sp)
#define	UNGETC(c)	(-- sp)
#define	RETURN(ptr)	return;
#define	ERROR(val)	_RegExpError(val)
#endif

#endif
