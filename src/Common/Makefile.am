#
#      Makefile definitions for src/Common
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = CommonT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libCommon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCommon_la_SOURCES = Common.c
dist_man1_MANS = CommonT.man
dist_man3_MANS = Common.man
include_HEADERS = Common.h  CommonP.h
