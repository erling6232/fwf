#
#      Makefile definitions for lib/TextOut
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libTextOut.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libTextOut_la_SOURCES = TextOut.c
dist_man3_MANS = TextOut.man
include_HEADERS = TextOut.h  TextOutP.h
