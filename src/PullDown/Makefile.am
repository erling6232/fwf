#
#      Makefile definitions for src/PullDown
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PullDownT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = PullDown.la
AM_CPPFLAGS = -I$(top_srcdir)/include

PullDown_la_SOURCES = PullDown.c
dist_man1_MANS = PullDownT.man
dist_man3_MANS = PullDown.man
include_HEADERS = PullDown.h  PullDownP.h
