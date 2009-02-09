#
#      Makefile definitions for src/Rheostat
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = RheostatT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Rheostat.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Rheostat_la_SOURCES = Rheostat.c
dist_man1_MANS = RheostatT.man
dist_man3_MANS = Rheostat.man
include_HEADERS = Rheostat.h  RheostatP.h
