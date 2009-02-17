#
#      Makefile definitions for src/SSGML
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = SSGMLT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libSSGML.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libSSGML_la_SOURCES = SSGML.c
dist_man1_MANS = SSGMLT.man
dist_man3_MANS = SSGML.man
include_HEADERS = SSGML.h  SSGMLP.h
