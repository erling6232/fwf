#
#      Makefile definitions for lib/OptButton
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libOptButton.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libOptButton_la_SOURCES = OptButton.c
dist_man3_MANS = OptButton.man
include_HEADERS = OptButton.h  OptButtonP.h
