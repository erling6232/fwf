#
#      Makefile definitions for lib/PixelEditor
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPixelEditor.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPixelEditor_la_SOURCES = PixEdit.c
dist_man3_MANS = PixEdit.man
include_HEADERS = PixEdit.h  PixEditP.h
