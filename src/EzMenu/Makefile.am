#
#      Makefile definitions for src/EzMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = EzMenuT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = EzMenu.la
AM_CPPFLAGS = -I$(top_srcdir)/include

EzMenu_la_SOURCES = EzME.c EzMenu.c SmeLine.c
dist_man1_MANS = EzMenuT.man
dist_man3_MANS = EzME.man EzMenu.man
include_HEADERS = EzME.h EzMenu.h EzMenuP.h EzMEP.h
