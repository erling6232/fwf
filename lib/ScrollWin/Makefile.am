#
#      Makefile definitions for lib/ScrollWin
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libScrollWin.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrollWin_la_SOURCES = ScrollWin.c
dist_man3_MANS = ScrollWin.man
include_HEADERS = ScrollWin.h  ScrollWinP.h
