#
#      Makefile definitions for src/converters
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = converters.la
AM_CPPFLAGS = -I$(top_srcdir)/include

converters_la_SOURCES = choosecol.c icon.c long.c Pen.c str2color.c \
			strarray.c StrToPmap.c  XCC.c
dist_man3_MANS = Pen.man  StrToPmap.man
include_HEADERS = choosecol.h Converters.h icon.h long.h Pen.h \
		  str2color.h strarray.h StrToPmap.h XCC.h XCCP.h
