#
#      Makefile definitions for lib/PcBar
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPcBar.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPcBar_la_SOURCES = PcBar.c
dist_man3_MANS = PcBar.man
include_HEADERS = PcBar.h  PcBarP.h
