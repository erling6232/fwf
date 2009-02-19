#
#      Makefile definitions for lib/misc
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libmisc.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libmisc_la_SOURCES = VarArgs.c
dist_man3_MANS = VarArgs.man
include_HEADERS = VarArgs.h
