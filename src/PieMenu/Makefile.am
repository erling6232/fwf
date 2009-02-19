#
#      Makefile definitions for src/PieMenu
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PieMenuT
LDADD = ../../lib/libfwf.la -lXpm -lXaw
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = PieMenuT.man
