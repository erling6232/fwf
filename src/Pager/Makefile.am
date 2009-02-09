#
#      Makefile definitions for src/Pager
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PagerT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Pager.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Pager_la_SOURCES = Pager.c
dist_man1_MANS = PagerT.man
dist_man3_MANS = Pager.man
include_HEADERS = Pager.h  PagerP.h
