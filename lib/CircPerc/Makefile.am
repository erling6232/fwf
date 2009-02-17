#
#      Makefile definitions for lib/CircPerc
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libCircPerc.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCircPerc_la_SOURCES = CircPerc.c
dist_man3_MANS = CircPerc.man
include_HEADERS = CircPerc.h  CircPercP.h
