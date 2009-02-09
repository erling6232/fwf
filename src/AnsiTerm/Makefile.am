#
#      Makefile definitions for src/AnsiTerm
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = AnsiTerm.la
AM_CPPFLAGS = -I$(top_srcdir)/include

AnsiTerm_la_SOURCES = AnsiTerm.c
dist_man3_MANS = AnsiTerm.man
include_HEADERS = AnsiTerm.h  AnsiTermP.h
