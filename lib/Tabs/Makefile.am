#
#      Makefile definitions for lib/Tabs
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libTabs.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libTabs_la_SOURCES = Tabs.c
dist_man3_MANS = Tabs.man
include_HEADERS = Tabs.h  TabsP.h
