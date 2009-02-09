#
#      Makefile definitions for src/Prompt
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

bin_PROGRAMS = PromptT
LDADD = ../libfwf.la
noinst_LTLIBRARIES = Prompt.la
AM_CPPFLAGS = -I$(top_srcdir)/include

Prompt_la_SOURCES = Prompt.c
dist_man1_MANS = PromptT.man
dist_man3_MANS = Prompt.man
include_HEADERS = Prompt.h  PromptP.h
