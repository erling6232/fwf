#
#      Makefile definitions for src/PcBar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PcBarT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = PcBar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

PcBar_la_SOURCES = PcBar.c
dist_man1_MANS = PcBarT.man
dist_man3_MANS = PcBar.man
include_HEADERS = PcBar.h  PcBarP.h
