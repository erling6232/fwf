#
#      Makefile definitions for lib/Entry
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libEntry.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libEntry_la_SOURCES = Entry.c
dist_man3_MANS = Entry.man
include_HEADERS = Entry.h  EntryP.h
