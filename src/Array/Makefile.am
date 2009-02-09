#
#      Makefile definitions for src/Array
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ArrayT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Array.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Array_la_SOURCES = Array.c
dist_man1_MANS = ArrayT.man
dist_man3_MANS = Array.man
include_HEADERS = Array.h  ArrayP.h
