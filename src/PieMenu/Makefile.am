#
#      Makefile definitions for src/PieMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PieMenuT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = PieMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

PieMenu_la_SOURCES = PieMenu.c
dist_man1_MANS = PieMenuT.man
dist_man3_MANS = PieMenu.man
include_HEADERS = PieMenu.h  PieMenuP.h
