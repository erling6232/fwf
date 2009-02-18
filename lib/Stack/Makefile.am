#
#      Makefile definitions for lib/Stack
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libStack.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libStack_la_SOURCES = Stack.c
dist_man3_MANS = Stack.man
include_HEADERS = Stack.h  StackP.h
