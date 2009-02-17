#
#      Makefile definitions for src/Arrow
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ArrowT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libArrow.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libArrow_la_SOURCES = Arrow.c
dist_man1_MANS = Arrow.man
dist_man3_MANS = Arrow.man
include_HEADERS = Arrow.h  ArrowP.h
