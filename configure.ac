AC_INIT([MegaMimes], [1.0], [okessuman@st.ug.edu.gh])
AC_PREREQ([2.64])
AC_CONFIG_SRCDIR([src/MegaMimes.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([libmegamimes.pc])
AC_CONFIG_AUX_DIR([build-aux])
AC_ENABLE_SHARED
AC_ENABLE_STATIC

PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

AC_CHECK_HEADERS([wctype.h string.h stdbool.h stdio.h])
AC_C_INLINE
AC_TYPE_SIZE_T

AC_FUNC_MALLOC
AC_CHECK_FUNCS([free])

AM_PROG_AR
AC_PROG_LIBTOOL
LT_INIT

AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects ])
AC_CONFIG_FILES([Makefile])
AC_PROG_CC
AC_OUTPUT 
