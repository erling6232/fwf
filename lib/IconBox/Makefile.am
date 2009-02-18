#
#      Makefile definitions for lib/IconBox
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libIconBox.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libIconBox_la_SOURCES = IconBox.c
dist_man3_MANS = IconBox.man
include_HEADERS = IconBox.h  IconBoxP.h
