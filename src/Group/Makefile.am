#
#      Makefile definitions for src/Group
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = GroupT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Group.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Group_la_SOURCES = Group.c
dist_man1_MANS = GroupT.man
dist_man3_MANS = Group.man
include_HEADERS = Group.h  GroupP.h
