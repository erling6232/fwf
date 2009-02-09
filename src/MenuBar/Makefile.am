#
#      Makefile definitions for src/MenuBar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = MenuBarT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = MenuBar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

MenuBar_la_SOURCES = MenuBar.c
dist_man1_MANS = MenuBarT.man
dist_man3_MANS = MenuBar.man
include_HEADERS = MenuBar.h  MenuBarP.h
