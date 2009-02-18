#
#      Makefile definitions for src/Label
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = LabelT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libLabel.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libLabel_la_SOURCES = Label.c
dist_man1_MANS = LabelT.man
dist_man3_MANS = Label.man
include_HEADERS = Label.h  LabelP.h
