#
#      Makefile definitions for lib/EzMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libEzMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libEzMenu_la_SOURCES = EzME.c EzMenu.c SmeLine.c
dist_man3_MANS = EzME.man EzMenu.man
include_HEADERS = EzME.h EzMenu.h EzMenuP.h EzMEP.h
