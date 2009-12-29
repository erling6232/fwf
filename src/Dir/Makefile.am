#
#      Makefile definitions for src/Dir
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = DirectoryT DirMgrT RegExpT
LDADD = ../../lib/libfwf4.la -lXpm -lXaw
AM_CPPFLAGS = -I$(top_srcdir)/include
