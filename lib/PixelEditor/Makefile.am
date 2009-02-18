#
#      Makefile definitions for src/PixelEditor
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PixEditT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libPixelEditor.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPixelEditor_la_SOURCES = PixEdit.c
dist_man1_MANS = PixEditT.man
dist_man3_MANS = PixEdit.man
include_HEADERS = PixEdit.h  PixEditP.h
