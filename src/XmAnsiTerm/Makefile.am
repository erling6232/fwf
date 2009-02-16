#
#      Makefile definitions for src/XmAnsiTerm
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmATermT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = XmAnsiTerm.la
AM_CPPFLAGS = -I$(top_srcdir)/include

XmAnsiTerm_la_SOURCES = XmATerm.c
dist_man1_MANS = XmATermT.man
dist_man3_MANS = XmATerm.man
include_HEADERS = XmATerm.h  XmATermP.h
