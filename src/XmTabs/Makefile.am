#
#      Makefile definitions for src/XmTabs
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmTabsT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libXmTabs.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libXmTabs_la_SOURCES = XmTabs.c rotated.c
dist_man1_MANS = XmTabsT.man
dist_man3_MANS = XmTabs.man
include_HEADERS = XmTabs.h  XmTabsP.h rotated.h
