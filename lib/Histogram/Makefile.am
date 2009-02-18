#
#      Makefile definitions for lib/Histogram
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libHistogram.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libHistogram_la_SOURCES = Histogram.c
dist_man3_MANS = Histogram.man
include_HEADERS = Histogram.h  HistogramP.h
