#
#      Makefile definitions for src/Stack
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = StackT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Stack.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Stack_la_SOURCES = Stack.c
dist_man1_MANS = StackT.man
dist_man3_MANS = Stack.man
include_HEADERS = Stack.h  StackP.h
