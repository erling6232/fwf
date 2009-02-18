#
#      Makefile definitions for lib/FileComp
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFileComp.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileComp_la_SOURCES = FileComp.c getod.c squish.c
dist_man3_MANS = FileComp.man
include_HEADERS = FileComp.h FileCompP.h
