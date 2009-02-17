#
#      Makefile definitions for src/Slider4
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = Slider4T
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libSlider4.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libSlider4_la_SOURCES = Slider4.c
dist_man1_MANS = Slider4T.man
dist_man3_MANS = Slider4.man
include_HEADERS = Slider4.h  Slider4P.h
