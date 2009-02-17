#
#      Makefile definitions for src/TextOut
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = TextOutT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libTextOut.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libTextOut_la_SOURCES = TextOut.c
dist_man1_MANS = TextOutT.man
dist_man3_MANS = TextOut.man
include_HEADERS = TextOut.h  TextOutP.h
