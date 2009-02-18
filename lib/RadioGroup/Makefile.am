#
#      Makefile definitions for lib/RadioGroup
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libRadioGroup.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libRadioGroup_la_SOURCES = RadioGrp.c
dist_man3_MANS = RadioGrp.man
include_HEADERS = RadioGrp.h  RadioGrpP.h
