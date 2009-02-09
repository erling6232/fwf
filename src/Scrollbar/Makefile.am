#
#      Makefile definitions for src/Scrollbar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ScrollbarT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Scrollbar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Scrollbar_la_SOURCES = Scrollbar.c
dist_man1_MANS = ScrollbarT.man
dist_man3_MANS = Scrollbar.man
include_HEADERS = Scrollbar.h  ScrollbarP.h
