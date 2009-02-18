#
#      Makefile definitions for src/tabstring
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libtabstring.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libtabstring_la_SOURCES = DrawImageString.c DrawString.c strnchr.c \
		       Tablist2Tabs.c TextWidth.c
include_HEADERS = TabString.h
