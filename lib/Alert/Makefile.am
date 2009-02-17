#
#      Makefile definitions for lib/Alert
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libAlert.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libAlert_la_SOURCES = Alert.c
dist_man3_MANS = Alert.man
include_HEADERS = Alert.h  AlertP.h
