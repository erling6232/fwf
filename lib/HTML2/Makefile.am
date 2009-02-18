#
#      Makefile definitions for lib/HTML2
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libHTML2.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libHTML2_la_SOURCES = HTML2.c
dist_man3_MANS = HTML2.man
include_HEADERS = HTML2.h  HTML2P.h
