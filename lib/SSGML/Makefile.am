#
#      Makefile definitions for lib/SSGML
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libSSGML.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libSSGML_la_SOURCES = SSGML.c
dist_man3_MANS = SSGML.man
include_HEADERS = SSGML.h  SSGMLP.h
