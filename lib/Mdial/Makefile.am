#
#      Makefile definitions for lib/Mdial
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libMdial.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libMdial_la_SOURCES = Mdial.c
dist_man3_MANS = Mdial.man
include_HEADERS = Mdial.h  MdialP.h
