#
#      Makefile definitions for src/XmPager
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = XmPagerT
LDADD = ../libfwf.la
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = XmPagerT.man
