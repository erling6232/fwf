#
#      Makefile definitions for src/OptButton
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = OptButtonT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = OptButton.la
AM_CPPFLAGS = -I$(top_srcdir)/include

OptButton_la_SOURCES = OptButton.c
dist_man1_MANS = OptButtonT.man
dist_man3_MANS = OptButton.man
include_HEADERS = OptButton.h  OptButtonP.h
