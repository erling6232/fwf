#
#      Makefile definitions for src/RadioGroup
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = RadioGrpT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = RadioGroup.la
AM_CPPFLAGS = -I$(top_srcdir)/include

RadioGroup_la_SOURCES = RadioGrp.c
dist_man1_MANS = RadioGrpT.man
dist_man3_MANS = RadioGrp.man
include_HEADERS = RadioGrp.h  RadioGrpP.h
