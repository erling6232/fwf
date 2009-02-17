#
#      Makefile definitions for lib/Canvas
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libCanvas.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCanvas_la_SOURCES = Canvas.c
dist_man3_MANS = Canvas.man
include_HEADERS = Canvas.h  CanvasP.h
