#
#      Makefile definitions for src/FileLister
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FileListerT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFileLister.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFileLister_la_SOURCES = FileLister.c
dist_man1_MANS = FileListerT.man
dist_man3_MANS = FileLister.man
include_HEADERS = FileLister.h  FileListerP.h
