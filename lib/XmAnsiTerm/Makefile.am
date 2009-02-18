#
#      Makefile definitions for lib/XmAnsiTerm
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libXmAnsiTerm.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libXmAnsiTerm_la_SOURCES = XmATerm.c
dist_man3_MANS = XmATerm.man
include_HEADERS = XmATerm.h  XmATermP.h
