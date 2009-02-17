#
#      Makefile definitions for lib/Animator
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libAnimator.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libAnimator_la_SOURCES = Animator.c
dist_man3_MANS = Animator.man
include_HEADERS = Animator.h  AnimatorP.h
