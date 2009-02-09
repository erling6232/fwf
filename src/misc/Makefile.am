#
#      Makefile definitions for src/misc
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = misc.la
AM_CPPFLAGS = -I$(top_srcdir)/include

misc_la_SOURCES = VarArgs.c
dist_man3_MANS = VarArgs.man
include_HEADERS = VarArgs.h  VarArgsP.h
