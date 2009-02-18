#
#      Makefile definitions for lib/TextMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libTextMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libTextMenu_la_SOURCES = TextMenu.c
dist_man3_MANS = TextMenu.man
include_HEADERS = TextMenu.h  TextMenuP.h
