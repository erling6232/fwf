#
#      Makefile definitions for lib/FoldingTree
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFoldingTree.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFoldingTree_la_SOURCES = FoldTree.c
dist_man3_MANS = FoldTree.man
include_HEADERS = FoldTree.h  FoldTreeP.h
