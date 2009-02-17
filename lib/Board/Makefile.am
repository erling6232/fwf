#
#      Makefile definitions for lib/Board
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libBoard.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libBoard_la_SOURCES = Board.c
dist_man3_MANS = Board.man
include_HEADERS = Board.h  BoardP.h
