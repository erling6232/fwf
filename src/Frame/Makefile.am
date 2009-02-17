#
#      Makefile definitions for src/Frame
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = FrameT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = libFrame.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFrame_la_SOURCES = Frame.c
dist_man1_MANS = FrameT.man
dist_man3_MANS = Frame.man
include_HEADERS = Frame.h  FrameP.h
