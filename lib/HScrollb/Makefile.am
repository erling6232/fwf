#
#      Makefile definitions for src/HScrollb
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = HScrollbT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libHScrollb.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libHScrollb_la_SOURCES = HScrollb.c
dist_man1_MANS = HScrollbT.man
dist_man3_MANS = HScrollb.man
include_HEADERS = HScrollb.h  HScrollbP.h
