#
#      Makefile definitions for src/XmTabs
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmTabsT
LDADD = ../libfwf.la
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = XmTabsT.man
