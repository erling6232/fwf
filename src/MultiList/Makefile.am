#
#      Makefile definitions for src/MultiList
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = MultiListT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = MultiList.la
AM_CPPFLAGS = -I$(top_srcdir)/include

MultiList_la_SOURCES = MultiList.c
dist_man1_MANS = MultiListT.man
dist_man3_MANS = MultiList.man
include_HEADERS = MultiList.h  MultiListP.h
