#
#      Makefile definitions for src/XmPager
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmPagerT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = XmPager.la
AM_CPPFLAGS = -I$(top_srcdir)/include

XmPager_la_SOURCES = XmPager.c
dist_man1_MANS = XmPagerT.man
dist_man3_MANS = XmPager.man
include_HEADERS = XmPager.h  XmPagerP.h
