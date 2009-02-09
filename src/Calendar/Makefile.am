#
#      Makefile definitions for src/Calendar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = CalendarT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Calendar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Calendar_la_SOURCES = Calendar.c
dist_man1_MANS = CalendarT.man
dist_man3_MANS = Calendar.man
include_HEADERS = Calendar.h  CalendarP.h
