#
#      Makefile definitions for lib/Cmap
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libCmap.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCmap_la_SOURCES = Cmap.c
dist_man3_MANS = Cmap.Motif.man
include_HEADERS = Cmap.h  CmapP.h
