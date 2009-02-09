#
#      Makefile definitions for src/RowCol
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = RowColT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = RowCol.la
AM_CPPFLAGS = -I$(top_srcdir)/include

RowCol_la_SOURCES = RowCol.c
dist_man1_MANS = RowColT.man
dist_man3_MANS = RowCol.man
include_HEADERS = RowCol.h  RowColP.h
