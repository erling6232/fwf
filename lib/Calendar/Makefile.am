#
#      Makefile definitions for lib/Calendar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libCalendar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libCalendar_la_SOURCES = Calendar.c
dist_man3_MANS = Calendar.man
include_HEADERS = Calendar.h  CalendarP.h
