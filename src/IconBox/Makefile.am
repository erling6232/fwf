#
#      Makefile definitions for src/IconBox
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = IconBoxT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libIconBox.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libIconBox_la_SOURCES = IconBox.c
dist_man1_MANS = IconBoxT.man
dist_man3_MANS = IconBox.man
include_HEADERS = IconBox.h  IconBoxP.h
