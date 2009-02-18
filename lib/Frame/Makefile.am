#
#      Makefile definitions for lib/Frame
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libFrame.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libFrame_la_SOURCES = Frame.c
dist_man3_MANS = Frame.man
include_HEADERS = Frame.h  FrameP.h
