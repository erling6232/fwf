#
#      Makefile definitions for src/Rows
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = RowsT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libRows.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libRows_la_SOURCES = Rows.c
dist_man1_MANS = RowsT.man
dist_man3_MANS = Rows.man
include_HEADERS = Rows.h  RowsP.h
