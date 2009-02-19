# Prelude
AC_PREREQ(2.50)
AC_INIT([fwf], [4.0.1], [Erling.Andersen@Helse-Bergen.NO])
AC_CONFIG_SRCDIR([lib/Common/Common.h])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_SED

# AM_PROG_CC_C_O

# Checks for libraries
AC_CHECK_LIB([X11],  [XBell])
# Internal xpm # AC_CHECK_LIB([xpm],  [xpmReadFile])
# AC_CHECK_LIB([Xaw],  [XawAsciiSave])
AC_CHECK_LIB([Xmu],  [XmuMakeAtom])
AC_CHECK_LIB([Xt],   [XtConvert])
#AC_CHECK_LIB([Xext], [XextAddDisplay])
AC_CHECK_LIB([m],    [sqrt])

# Checks for header files
AC_PATH_X
AC_ARG_ENABLE(gui,
	[AS_HELP_STRING([--enable-gui=auto], [Select GUI: motif, athena or auto])],
	[gui="$enableval"], [gui=auto])
LIBGUI=
AS_IF([test "x$gui" = xauto],
	[AC_CHECK_LIB([Xaw],  [XawAsciiSave],
		[AC_SUBST([LIBGUI], ["-lXaw -lXmu -lXt"])
		 AC_DEFINE([HAVE_LIBXAW], [1], [Define if you have libXaw])
		],
		[AC_CHECK_LIB([Xm],  [XmStringFree],
			[AC_SUBST([LIBGUI], ["-lXm"])
			 AC_DEFINE([HAVE_LIBMOTIF], [1], [Define if you have Motif])
			 AC_DEFINE([MOTIF], [], [Define when you have Motif])
			],
			[AC_MSG_FAILURE([Motif test failed])
			])
		])
	],
      [test "x$gui" = xathena],
	[AC_CHECK_LIB([Xaw],  [XawAsciiSave],
		[AC_SUBST([LIBGUI], ["-lXaw -lXmu -lXt"])
		 AC_DEFINE([HAVE_LIBXAW], [1], [Define if you have libXaw])
		],
	)],
      [test "x$gui" = xmotif],
	[AC_CHECK_LIB([Xm],  [XmStringFree],
		[AC_SUBST([LIBGUI], ["-lXm"])
		 AC_DEFINE([HAVE_LIBMOTIF], [1], [Define if you have Motif])
		],
	)]
)

AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([ctype.h fcntl.h sys/fcntl.h float.h io.h sys/io.h limits.h malloc.h math.h memory.h stddef.h stdio.h stdlib.h sys/file.h sys/param.h sys/stat.h sys/time.h sys/times.h time.h unistd.h values.h])
AC_CHECK_HEADERS([direct.h varargs.h stdarg.h pwd.h process.h])
AC_CHECK_HEADER([regex.h],
                [AC_DEFINE([HAVE_REGEX_H], [1], [Define if you have regex.h])]
                [AC_DEFINE([REGEX], [1], [Define if you have regex.h])],
		[AC_CHECK_HEADER([regexp.h],
		                 [AC_DEFINE([HAVE_REGEXP_H], [1], [Define if you have regexp.h])],
				 [AC_DEFINE([NO_REGEXP], [1], [Define if you dont have regex])]
				)
	       ])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_CHECK_TYPES([ptrdiff_t])
AC_CHECK_MEMBERS([struct passwd.pw_dir])

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_LSTAT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_FUNC_STRTOD
AC_FUNC_VPRINTF
AC_FUNC_WAIT3
AC_CHECK_FUNCS([dup2 getcwd getwd isascii pow regcomp select sqrt strcasecmp strchr strcspn strerror strrchr strspn strstr strtod strtol])
AC_CHECK_FUNCS([link setmode symlink rand random srand srandom toupper tolower umask])
AC_CHECK_FUNCS([clock flock mktemp mkstemp tempnam time times])

# define XITE_MALLOC_H     <stdlib.h>
# define XITE_MEMORY_H     <string.h>
# define XITE_STRING_H     <string.h>
# define XITE_PARAM_H      <sys/param.h>



# Common Makefile.def
AC_SUBST(configdir, [\${top_builddir}])
AC_SUBST(common_makefile, [Makefile.def])

# Output files
AC_CONFIG_FILES([
    Makefile.def
    Makefile
    lib/Makefile
    lib/Alert/Makefile
    lib/Animator/Makefile
    lib/AnsiTerm/Makefile
    lib/Array/Makefile
    lib/Arrow/Makefile
    lib/ArticleText/Makefile
    lib/Board/Makefile
    lib/Button/Makefile
    lib/Calendar/Makefile
    lib/Canvas/Makefile
    lib/CircPerc/Makefile
    lib/Cmap/Makefile
    lib/Common/Makefile
    lib/converters/Makefile
    lib/Dir/Makefile
    lib/Enforcer/Makefile
    lib/Entry/Makefile
    lib/FileChooser/Makefile
    lib/FileComp/Makefile
    lib/FileLister/Makefile
    lib/FileSelector/Makefile
    lib/FoldingTree/Makefile
    lib/Frame/Makefile
    lib/FText/Makefile
    lib/Group/Makefile
    lib/Hdial/Makefile
    lib/Histogram/Makefile
    lib/HScrollb/Makefile
    lib/HTML2/Makefile
    lib/Icon/Makefile
    lib/IconBox/Makefile
    lib/ImageSelector/Makefile
    lib/Label/Makefile
    lib/Mdial/Makefile
    lib/MenuBar/Makefile
    lib/misc/Makefile
    lib/MultiList/Makefile
    lib/OptButton/Makefile
    lib/Pager/Makefile
    lib/PcBar/Makefile
    lib/PieMenu/Makefile
    lib/PixelEditor/Makefile
    lib/Prompt/Makefile
    lib/PullDown/Makefile
    lib/RadioGroup/Makefile
    lib/Rheostat/Makefile
    lib/RowCol/Makefile
    lib/Rows/Makefile
    lib/scroll/Makefile
    lib/Scrollbar/Makefile
    lib/ScrolledList/Makefile
    lib/ScrollWin/Makefile
    lib/ScrollWin3/Makefile
    lib/Shistogram/Makefile
    lib/Slider2/Makefile
    lib/Slider4/Makefile
    lib/SpinLabel/Makefile
    lib/SSGML/Makefile
    lib/Stack/Makefile
    lib/Tabs/Makefile
    lib/tabstring/Makefile
    lib/TextMenu/Makefile
    lib/TextOut/Makefile
    lib/ThumbWheel/Makefile
    lib/ThumbWheel2/Makefile
    lib/Toggle/Makefile
    lib/UserGraf/Makefile
    lib/VScrollb/Makefile
    lib/XmAnsiTerm/Makefile
    lib/XmIcon/Makefile
    lib/XmPager/Makefile
    lib/XmTabs/Makefile
    src/Makefile
    src/Alert/Makefile
    src/Animator/Makefile
    src/AnsiTerm/Makefile
    src/Array/Makefile
    src/Arrow/Makefile
    src/ArticleText/Makefile
    src/Board/Makefile
    src/Button/Makefile
    src/Calendar/Makefile
    src/Canvas/Makefile
    src/CircPerc/Makefile
    src/Cmap/Makefile
    src/Common/Makefile
    src/Dir/Makefile
    src/Enforcer/Makefile
    src/Entry/Makefile
    src/FileChooser/Makefile
    src/FileComp/Makefile
    src/FileLister/Makefile
    src/FileSelector/Makefile
    src/FoldingTree/Makefile
    src/Frame/Makefile
    src/FText/Makefile
    src/Group/Makefile
    src/Hdial/Makefile
    src/Histogram/Makefile
    src/HScrollb/Makefile
    src/HTML2/Makefile
    src/Icon/Makefile
    src/IconBox/Makefile
    src/ImageSelector/Makefile
    src/Label/Makefile
    src/Mdial/Makefile
    src/MenuBar/Makefile
    src/MultiList/Makefile
    src/OptButton/Makefile
    src/Pager/Makefile
    src/PcBar/Makefile
    src/PieMenu/Makefile
    src/PixelEditor/Makefile
    src/Prompt/Makefile
    src/PullDown/Makefile
    src/RadioGroup/Makefile
    src/Rheostat/Makefile
    src/RowCol/Makefile
    src/Rows/Makefile
    src/Scrollbar/Makefile
    src/ScrolledList/Makefile
    src/ScrollWin/Makefile
    src/ScrollWin3/Makefile
    src/Shistogram/Makefile
    src/Slider2/Makefile
    src/Slider4/Makefile
    src/SpinLabel/Makefile
    src/SSGML/Makefile
    src/Stack/Makefile
    src/Tabs/Makefile
    src/TextMenu/Makefile
    src/TextOut/Makefile
    src/ThumbWheel/Makefile
    src/ThumbWheel2/Makefile
    src/Toggle/Makefile
    src/UserGraf/Makefile
    src/VScrollb/Makefile
    src/XmAnsiTerm/Makefile
    src/XmIcon/Makefile
    src/XmPager/Makefile
    src/XmTabs/Makefile
    ])
AC_OUTPUT
