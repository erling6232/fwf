#
#      Makefile definitions for src/UserGraf
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = UGrafT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = UserGraf.la
AM_CPPFLAGS = -I$(top_srcdir)/include

UserGraf_la_SOURCES = \
	UGraf.c UGrafColor.c UGrafDraw.c UGrafHershey.c UGrafTrans3.c \
	UGrafTransforms.c XfwfHersheyGlyphs.c
dist_man1_MANS = UGrafT.man
dist_man3_MANS = UGraf.man
include_HEADERS = UGraf.h UGrafP.h UGrafTranslations.h XfwfHershey.h
