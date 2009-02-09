#
#      Makefile definitions for src/Enforcer
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = EnforcerT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Enforcer.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Enforcer_la_SOURCES = Enforcer.c
dist_man1_MANS = EnforcerT.man
dist_man3_MANS = Enforcer.man
include_HEADERS = Enforcer.h  EnforcerP.h
