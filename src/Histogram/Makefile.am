#
#      Makefile definitions for src/Histogram
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = HistogramT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Histogram.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Histogram_la_SOURCES = Histogram.c
dist_man1_MANS = HistogramT.man
dist_man3_MANS = Histogram.man
include_HEADERS = Histogram.h  HistogramP.h
