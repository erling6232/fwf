#
#      Makefile definitions for lib/ThumbWheel2
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libThumbWheel2.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libThumbWheel2_la_SOURCES = ThWheel2.c
dist_man3_MANS = ThWheel2.man
include_HEADERS = ThWheel2.h  ThWheel2P.h
