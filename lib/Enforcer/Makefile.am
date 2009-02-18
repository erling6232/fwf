#
#      Makefile definitions for lib/Enforcer
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libEnforcer.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libEnforcer_la_SOURCES = Enforcer.c
dist_man3_MANS = Enforcer.man
include_HEADERS = Enforcer.h  EnforcerP.h
