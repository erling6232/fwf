#
#      Makefile definitions for src/FileComp
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FileCompT.c sqtest.c
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFileComp.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileComp_la_SOURCES = FileComp.c getod.c squish.c
dist_man1_MANS = FileCompT.man
dist_man3_MANS = FileComp.man
include_HEADERS = FileComp.h FileCompP.h
