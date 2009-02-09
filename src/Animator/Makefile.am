#
#      Makefile definitions for src/Animator
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = AnimatorT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Animator.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Animator_la_SOURCES = Animator.c
dist_man1_MANS = AnimatorT.man
dist_man3_MANS = Animator.man
include_HEADERS = Animator.h  AnimatorP.h
