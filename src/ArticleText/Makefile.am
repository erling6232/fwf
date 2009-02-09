#
#      Makefile definitions for src/ArticleText
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ArtTextT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = ArticleText.la
AM_CPPFLAGS = -I$(top_srcdir)/include

ArticleText_la_SOURCES = ArtText.c
dist_man1_MANS = ArtTextT.man
dist_man3_MANS = ArtText.man
include_HEADERS = ArtText.h  ArtTextP.h
