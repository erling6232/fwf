#
#      Makefile definitions for src/RadioGroup
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = RadioGrpT
LDADD = ../../lib/libfwf.la -lXpm -lXaw
AM_CPPFLAGS = -I$(top_srcdir)/include

dist_man1_MANS = RadioGrpT.man
