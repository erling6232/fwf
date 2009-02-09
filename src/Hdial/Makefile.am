#
#      Makefile definitions for src/Hdial
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = HdialT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Hdial.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Hdial_la_SOURCES = Hdial.c
dist_man1_MANS = HdialT.man
dist_man3_MANS = Hdial.man
include_HEADERS = Hdial.h  HdialP.h
