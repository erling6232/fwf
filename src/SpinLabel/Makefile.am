#
#      Makefile definitions for src/SpinLabel
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = SpinLabelT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = SpinLabel.la
AM_CPPFLAGS = -I$(top_srcdir)/include

SpinLabel_la_SOURCES = SpinLabel.c
dist_man1_MANS = SpinLabelT.man
dist_man3_MANS = SpinLabel.man
include_HEADERS = SpinLabel.h  SpinLabelP.h
