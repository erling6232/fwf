#
#      Makefile definitions for src/Cmap
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = CmapT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Cmap.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Cmap_la_SOURCES = Cmap.c
dist_man1_MANS = CmapT.man
dist_man3_MANS = Cmap.Motif.man
include_HEADERS = Cmap.h  CmapP.h
