#
#      Makefile definitions for src/Dir
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = DirectoryT DirMgrT RegExpT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libDir.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libDir_la_SOURCES = Directory.c DirMgr.c RegExp.c
include_HEADERS = Directory.h  DirMgr.h  RegExp.h
