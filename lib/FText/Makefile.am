#
#      Makefile definitions for lib/FText
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFText.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFText_la_SOURCES = FText.c
dist_man3_MANS = FText.man
include_HEADERS = FText.h  FTextP.h
