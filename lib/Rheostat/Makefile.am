#
#      Makefile definitions for lib/Rheostat
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libRheostat.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libRheostat_la_SOURCES = Rheostat.c
dist_man3_MANS = Rheostat.man
include_HEADERS = Rheostat.h  RheostatP.h
