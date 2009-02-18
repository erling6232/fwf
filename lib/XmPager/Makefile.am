#
#      Makefile definitions for lib/XmPager
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libXmPager.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libXmPager_la_SOURCES = XmPager.c
dist_man3_MANS = XmPager.man
include_HEADERS = XmPager.h  XmPagerP.h
