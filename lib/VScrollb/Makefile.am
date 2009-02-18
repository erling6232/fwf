#
#      Makefile definitions for src/VScrollb
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = VScrollbT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libVScrollb.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libVScrollb_la_SOURCES = VScrollb.c
dist_man1_MANS = VScrollbT.man
dist_man3_MANS = VScrollb.man
include_HEADERS = VScrollb.h  VScrollbP.h
