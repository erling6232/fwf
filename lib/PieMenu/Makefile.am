#
#      Makefile definitions for lib/PieMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPieMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPieMenu_la_SOURCES = PieMenu.c
dist_man3_MANS = PieMenu.man
include_HEADERS = PieMenu.h  PieMenuP.h
