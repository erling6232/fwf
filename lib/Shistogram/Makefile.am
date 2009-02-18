#
#      Makefile definitions for lib/Shistogram
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libShistogram.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libShistogram_la_SOURCES = Shistogram.c
dist_man3_MANS = Shistogram.man
include_HEADERS = Shistogram.h  ShistogramP.h
