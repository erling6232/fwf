#
#      Makefile definitions for src/TextMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = TextMenuT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = TextMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

TextMenu_la_SOURCES = TextMenu.c
dist_man1_MANS = TextMenuT.man
dist_man3_MANS = TextMenu.man
include_HEADERS = TextMenu.h  TextMenuP.h
