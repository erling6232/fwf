#
#      Makefile definitions for lib/ScrollWin3
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libScrollWin3.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrollWin3_la_SOURCES = ScrWin3.c
dist_man3_MANS = ScrWin3.man
include_HEADERS = ScrWin3.h  ScrWin3P.h
