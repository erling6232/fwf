#
#      Makefile definitions for lib/Pager
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPager.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPager_la_SOURCES = Pager.c
dist_man3_MANS = Pager.man
include_HEADERS = Pager.h  PagerP.h
