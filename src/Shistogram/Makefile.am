#
#      Makefile definitions for src/Shistogram
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ShistogramT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Shistogram.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Shistogram_la_SOURCES = Shistogram.c
dist_man1_MANS = ShistogramT.man
dist_man3_MANS = Shistogram.man
include_HEADERS = Shistogram.h  ShistogramP.h
