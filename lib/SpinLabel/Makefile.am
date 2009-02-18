#
#      Makefile definitions for lib/SpinLabel
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libSpinLabel.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libSpinLabel_la_SOURCES = SpinLabel.c
dist_man3_MANS = SpinLabel.man
include_HEADERS = SpinLabel.h  SpinLabelP.h
