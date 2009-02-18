#
#      Makefile definitions for src/ScrolledList
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ScrListT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libScrolledList.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrolledList_la_SOURCES = ScrList.c
dist_man1_MANS = ScrListT.man
dist_man3_MANS = ScrList.man
include_HEADERS = ScrList.h  ScrListP.h
