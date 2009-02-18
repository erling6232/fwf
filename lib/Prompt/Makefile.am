#
#      Makefile definitions for lib/Prompt
#


@SET_MAKE@

SHELL = /bin/sh
configdir = @configdir@

#
include $(configdir)/@common_makefile@

#
#   Makefile definitions
#

noinst_LTLIBRARIES = libPrompt.la
AM_CPPFLAGS = -I$(top_srcdir)/include

libPrompt_la_SOURCES = Prompt.c
dist_man3_MANS = Prompt.man
include_HEADERS = Prompt.h  PromptP.h
