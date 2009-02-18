#
#      Makefile definitions for lib/MultiList
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libMultiList.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libMultiList_la_SOURCES = MultiList.c
dist_man3_MANS = MultiList.man
include_HEADERS = MultiList.h  MultiListP.h
