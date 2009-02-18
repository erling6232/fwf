#
#      Makefile definitions for lib/HScrollb
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libHScrollb.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libHScrollb_la_SOURCES = HScrollb.c
dist_man3_MANS = HScrollb.man
include_HEADERS = HScrollb.h  HScrollbP.h
