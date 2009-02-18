#
#      Makefile definitions for lib/Slider2
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libSlider2.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libSlider2_la_SOURCES = Slider2.c
dist_man3_MANS = Slider2.man
include_HEADERS = Slider2.h  Slider2P.h
