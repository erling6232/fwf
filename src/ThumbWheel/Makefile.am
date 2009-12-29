#
#      Makefile definitions for src/ThumbWheel
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = ThWheelT ThWheelT2
LDADD = ../../lib/libfwf4.la -lXpm -lXaw
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = ThWheelT.man
