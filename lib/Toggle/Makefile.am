#
#      Makefile definitions for lib/Toggle
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libToggle.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libToggle_la_SOURCES = Toggle.c
dist_man3_MANS = Toggle.man
include_HEADERS = Toggle.h  ToggleP.h
