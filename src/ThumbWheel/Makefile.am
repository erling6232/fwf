#
#      Makefile definitions for src/ThumbWheel
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ThWheelT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = ThumbWheel.la
AM_CPPFLAGS = -I$(top_srcdir)/include

ThumbWheel_la_SOURCES = ThWheel.c
dist_man1_MANS = ThWheelT.man
dist_man3_MANS = ThWheel.man
include_HEADERS = ThWheel.h  ThWheelP.h
