#
#      Makefile definitions for lib/UserGraf
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libUserGraf.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libUserGraf_la_SOURCES = \
	UGraf.c UGrafColor.c UGrafDraw.c UGrafHershey.c UGrafTrans3.c \
	UGrafTransforms.c XfwfHersheyGlyphs.c
dist_man3_MANS = UGraf.man
include_HEADERS = UGraf.h UGrafP.h UGrafTranslations.h XfwfHershey.h
