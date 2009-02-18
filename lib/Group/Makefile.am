#
#      Makefile definitions for lib/Group
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libGroup.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libGroup_la_SOURCES = Group.c
dist_man3_MANS = Group.man
include_HEADERS = Group.h  GroupP.h
