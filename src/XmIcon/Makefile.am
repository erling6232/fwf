#
#      Makefile definitions for src/XmIcon
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmIconT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = XmIcon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

XmIcon_la_SOURCES = XmIcon.c
dist_man1_MANS = XmIconT.man
dist_man3_MANS = XmIcon.man
include_HEADERS = XmIcon.h  XmIconP.h
