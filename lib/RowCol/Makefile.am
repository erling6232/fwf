#
#      Makefile definitions for lib/RowCol
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libRowCol.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libRowCol_la_SOURCES = RowCol.c
dist_man3_MANS = RowCol.man
include_HEADERS = RowCol.h  RowColP.h
