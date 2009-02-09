#
#      Makefile definitions for src/ScrollWin3
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ScrWin3T
LDADD = ../libfwf.la
noinst_LTLIBRARIES = ScrollWin3.la
AM_CPPFLAGS = -I$(top_srcdir)/include

ScrollWin3_la_SOURCES = ScrWin3.c
dist_man1_MANS = ScrWin3T.man
dist_man3_MANS = ScrWin3.man
include_HEADERS = ScrWin3.h  ScrWin3P.h
