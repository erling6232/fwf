#
#      Makefile definitions for src/Mdial
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = MdialT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Mdial.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Mdial_la_SOURCES = Mdial.c
dist_man1_MANS = MdialT.man
dist_man3_MANS = Mdial.man
include_HEADERS = Mdial.h  MdialP.h
