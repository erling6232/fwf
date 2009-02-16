#
#      Makefile definitions for src/Slider2
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = Slider2T
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Slider2.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Slider2_la_SOURCES = Slider2.c
dist_man1_MANS = Slider2T.man
dist_man3_MANS = Slider2.man
include_HEADERS = Slider2.h  Slider2P.h
