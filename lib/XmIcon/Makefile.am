#
#      Makefile definitions for lib/XmIcon
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libXmIcon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libXmIcon_la_SOURCES = XmIcon.c
dist_man3_MANS = XmIcon.man
include_HEADERS = XmIcon.h  XmIconP.h
