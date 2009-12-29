#
#      Makefile definitions for src/IconBox
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = IconBoxT
LDADD = ../../lib/libfwf4.la -lXpm -lXaw
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = IconBoxT.man
