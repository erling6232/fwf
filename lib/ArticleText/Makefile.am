#
#      Makefile definitions for lib/ArticleText
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libArticleText.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libArticleText_la_SOURCES = ArtText.c
dist_man3_MANS = ArtText.man
