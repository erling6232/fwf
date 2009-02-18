#
#      Makefile definitions for lib/Hdial
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libHdial.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libHdial_la_SOURCES = Hdial.c
dist_man3_MANS = Hdial.man
include_HEADERS = Hdial.h  HdialP.h
