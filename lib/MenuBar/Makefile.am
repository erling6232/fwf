#
#      Makefile definitions for lib/MenuBar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libMenuBar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libMenuBar_la_SOURCES = MenuBar.c
dist_man3_MANS = MenuBar.man
include_HEADERS = MenuBar.h  MenuBarP.h
