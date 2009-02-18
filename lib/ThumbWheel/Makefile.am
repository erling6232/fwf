#
#      Makefile definitions for lib/ThumbWheel
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libThumbWheel.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libThumbWheel_la_SOURCES = ThWheel.c
dist_man3_MANS = ThWheel.man
include_HEADERS = ThWheel.h  ThWheelP.h
