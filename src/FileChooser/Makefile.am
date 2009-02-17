#
#      Makefile definitions for src/FileChooser
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FChooserT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFileChooser.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileChooser_la_SOURCES = FChooser.c
dist_man1_MANS = FChooserT.man
dist_man3_MANS = FChooser.man
include_HEADERS = FChooser.h FChooserP.h
