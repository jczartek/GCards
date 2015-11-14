AC_PREREQ(2.63.2)

m4_define(gcard_major_version, 0)
m4_define(gcard_minor_version, 1)
m4_define(gcard_micro_vesrion, 0)
m4_define(gcard_version, gcard_major_version.gcard_minor_version.gcard_micro_vesrion)

AC_INIT([gcards],
        [gcard_version],
        [],
        [gcards])

dnl ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
dnl + Dependencies                                                             +
dnl ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

GLIB_REQUIRED=2.44
GTK_REQUIRED=3.16.0
CLUTTER_REQUIRED=1.22.0
CLUTTER_GTK_REQUIRED=1.6.0
SQLITE3_REQUIRED=3.8.0

AC_CONFIG_SRCDIR([src/gc-main.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_DEFINE(GCARD_MAJOR_VERSION, gcard_major_version, [GCards major version])
AC_SUBST(GCARD_MAJOR_VERSION, gcard_major_version)
AC_DEFINE(GCARD_MINOR_VERSION, gcard_minor_version, [GCards minor version])
AC_SUBST(GCARD_MINOR_VERSION, gcard_minor_version)
AC_DEFINE(GCARD_MICRO_VERSION, gcard_micro_vesrion, [GCards micro version])
AC_SUBST(GCARD_MICRO_VERSION, gcard_micro_vesrion)

AM_INIT_AUTOMAKE([1.11 tar-ustar dist-xz no-dist-gzip -Wall])
AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PROG_CPP
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG
AC_HEADER_STDC
AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)

PKG_CHECK_MODULES(GCARDS,
                  [gtk+-3.0 >= $GTK_REQUIRED
                   glib-2.0 >= $GLIB_REQUIRED
                   sqlite3 >= $SQLITE3_REQUIRED
                   clutter-1.0 >= $CLUTTER_REQUIRED
                   clutter-gtk-1.0 >= $CLUTTER_GTK_REQUIRED])

AC_SUBST(GCARDS_CFLAGS)
AC_SUBST(GCARDS_LIBS)

AC_OUTPUT([
Makefile
src/Makefile
tools/Makefile])

echo "
     Prefix: ${prefix}
     Compiler: ${CC}
     "
