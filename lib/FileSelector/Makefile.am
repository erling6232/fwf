#
#      Makefile definitions for src/FileSelector
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FileSelT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFileSelector.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileSelector_la_SOURCES = FileSel.c
dist_man1_MANS = FileSelT.man
dist_man3_MANS = FileSel.man
include_HEADERS = FileSel.h  FileSelP.h
