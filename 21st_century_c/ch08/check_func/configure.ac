#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([check_func], [0.1], [/dev/null])
AC_CONFIG_SRCDIR([check_func.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([strings.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp asprintf])

AC_OUTPUT
