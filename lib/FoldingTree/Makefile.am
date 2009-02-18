#
#      Makefile definitions for src/FoldingTree
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FoldTreeT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFoldingTree.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFoldingTree_la_SOURCES = FoldTree.c
dist_man1_MANS = FoldTreeT.man
dist_man3_MANS = FoldTree.man
include_HEADERS = FoldTree.h  FoldTreeP.h
