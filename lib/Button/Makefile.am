#
#      Makefile definitions for lib/Button
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libButton.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libButton_la_SOURCES = Button.c
dist_man3_MANS = Button.man
include_HEADERS = Button.h  ButtonP.h
