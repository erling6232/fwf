#
#      Makefile definitions for src/Canvas
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = CanvasT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libCanvas.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCanvas_la_SOURCES = Canvas.c
dist_man1_MANS = CanvasT.man
dist_man3_MANS = Canvas.man
include_HEADERS = Canvas.h  CanvasP.h
