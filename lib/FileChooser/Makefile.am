#
#      Makefile definitions for lib/FileChooser
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFileChooser.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileChooser_la_SOURCES = FChooser.c
dist_man3_MANS = FChooser.man
include_HEADERS = FChooser.h FChooserP.h
