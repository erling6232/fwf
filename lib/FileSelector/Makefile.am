#
#      Makefile definitions for lib/FileSelector
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFileSelector.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileSelector_la_SOURCES = FileSel.c
dist_man3_MANS = FileSel.man
include_HEADERS = FileSel.h  FileSelP.h
