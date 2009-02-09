#
#      Makefile definitions for src/Icon
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = IconT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Icon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Icon_la_SOURCES = Icon.c
dist_man1_MANS = IconT.man
dist_man3_MANS = Icon.man
include_HEADERS = Icon.h  IconP.h
