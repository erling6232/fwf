#
#      Makefile definitions for src/Tabs
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = TabsT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Tabs.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Tabs_la_SOURCES = Tabs.c
dist_man1_MANS = TabsT.man
dist_man3_MANS = Tabs.man
include_HEADERS = Tabs.h  TabsP.h
