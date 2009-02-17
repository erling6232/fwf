#
#      Makefile definitions for src/Button
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ButtonT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libButton.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libButton_la_SOURCES = Button.c
dist_man1_MANS = ButtonT.man
dist_man3_MANS = Button.man
include_HEADERS = Button.h  ButtonP.h
