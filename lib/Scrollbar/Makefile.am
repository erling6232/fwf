#
#      Makefile definitions for lib/Scrollbar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libScrollbar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libScrollbar_la_SOURCES = Scrollbar.c
dist_man3_MANS = Scrollbar.man
include_HEADERS = Scrollbar.h  ScrollbarP.h
