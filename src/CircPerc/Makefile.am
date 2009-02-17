#
#      Makefile definitions for src/CircPerc
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = CircPercT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libCircPerc.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCircPerc_la_SOURCES = CircPerc.c
dist_man1_MANS = CircPercT.man
dist_man3_MANS = CircPerc.man
include_HEADERS = CircPerc.h  CircPercP.h
