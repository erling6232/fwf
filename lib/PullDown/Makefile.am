#
#      Makefile definitions for lib/PullDown
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPullDown.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPullDown_la_SOURCES = PullDown.c
dist_man3_MANS = PullDown.man
include_HEADERS = PullDown.h  PullDownP.h
