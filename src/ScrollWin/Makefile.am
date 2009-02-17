#
#      Makefile definitions for src/ScrollWin
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ScrollWinT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libScrollWin.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrollWin_la_SOURCES = ScrollWin.c
dist_man1_MANS = ScrollWinT.man
dist_man3_MANS = ScrollWin.man
include_HEADERS = ScrollWin.h  ScrollWinP.h
