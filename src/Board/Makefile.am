#
#      Makefile definitions for src/Board
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = BoardT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Board.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Board_la_SOURCES = Board.c
dist_man1_MANS = BoardT.man
dist_man3_MANS = Board.man
include_HEADERS = Board.h  BoardP.h
