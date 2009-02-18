#
#      Makefile definitions for lib/Icon
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libIcon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libIcon_la_SOURCES = Icon.c
dist_man3_MANS = Icon.man
include_HEADERS = Icon.h  IconP.h
