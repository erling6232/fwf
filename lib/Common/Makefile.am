#
#      Makefile definitions for lib/Common
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libCommon.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCommon_la_SOURCES = Common.c
dist_man3_MANS = Common.man
include_HEADERS = Common.h  CommonP.h
