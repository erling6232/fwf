#
#      Makefile definitions for src/FText
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FTextT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFText.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFText_la_SOURCES = FText.c
dist_man1_MANS = FTextT.man
dist_man3_MANS = FText.man
include_HEADERS = FText.h  FTextP.h
