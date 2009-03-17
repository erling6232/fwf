/****************************************************************************

	RegExp.c

	This file contains the C code for the regular expression
	matching code.

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

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <Xfwf/RegExp.h>
#include <stdlib.h>

void RegExpCompile(const char *regexp, regex_obj *fsm_ptr, int fsm_length)
{
#ifdef HAVE_REGEX_H
	int cflags = 0;
	(void) regcomp(fsm_ptr, regexp, cflags);
#else
#ifndef NO_REGEXP
	compile(regexp,fsm_ptr,&(fsm_ptr[fsm_length]),'\0');
#endif
#endif
} /* End RegExpCompile */


#ifdef HAVE_REGEX_H
int RegExpMatch(const char *string, const regex_t *fsm_ptr)
{
	if (regexec(fsm_ptr, string, (size_t) 0, NULL, 0) == 0)
		return(TRUE);
	else
		return(FALSE);
}
#else
int RegExpMatch(const char *string, const char *fsm_ptr)
{
#ifndef NO_REGEXP
	if (advance(string,fsm_ptr) != 0)
		return(TRUE);
	    else
		return(FALSE);
#else
	return(TRUE);
#endif
}
#endif
/* End RegExpMatch */


void _RegExpError(val)
int val;
{
	fprintf(stderr,"Regular Expression Error %d\n",val);
	exit(-1);
} /* End _RegExpError */


void RegExpPatternToRegExp(const char *pattern, char *reg_exp)
{
	int in_bracket;

	in_bracket = 0;
	while (*pattern != '\0')
	{
		if (in_bracket)
		{
			if (*pattern == ']') in_bracket = 0;
			*reg_exp++ = *pattern++;
		}
		    else
		{
			switch (*pattern)
			{
			    case '[':
				in_bracket = 1;
				*reg_exp++ = '[';
				break;
			    case '?':
				*reg_exp++ = '.';
				break;
			    case '*':
				*reg_exp++ = '.';
				*reg_exp++ = '*';
				break;
			    case '.':
				*reg_exp++ = '\\';
				*reg_exp++ = '.';
				break;
			    default:
				*reg_exp++ = *pattern;
				break;
			}
			++ pattern;
		}
	}
	*reg_exp++ = '$';
	*reg_exp++ = '\0';
} /* End RegExpPatternToRegExp */
