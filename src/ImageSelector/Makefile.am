#
#      Makefile definitions for src/ImageSelector
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ImageSelT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libImageSelector.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libImageSelector_la_SOURCES = ImageSel.c
dist_man1_MANS = ImageSelT.man
dist_man3_MANS = ImageSel.man
include_HEADERS = ImageSel.h  ImageSelP.h
