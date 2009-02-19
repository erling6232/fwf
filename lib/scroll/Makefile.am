#
#      Makefile definitions for lib/scroll
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libscroll.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libscroll_la_SOURCES = scroll.c
include_HEADERS = scroll.h  scrollP.h
