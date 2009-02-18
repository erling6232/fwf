#
#      Makefile definitions for lib/ScrolledList
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libScrolledList.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrolledList_la_SOURCES = ScrList.c
dist_man3_MANS = ScrList.man
include_HEADERS = ScrList.h  ScrListP.h
