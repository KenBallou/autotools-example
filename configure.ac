AC_INIT([hello], [1.0])

AC_CONFIG_AUX_DIR(build-aux)

AC_CONFIG_MACRO_DIRS([m4])

AC_CONFIG_HEADERS([config.h])

AC_PROG_CC

AM_INIT_AUTOMAKE([foreign])

LT_INIT

AC_ARG_ENABLE([separate-hello-library],
              [AS_HELP_STRING([--enable-separate-hello-library],
                              [build a separate shared libhello.so library])],
              [],
              [enable_separate_hello_library=no])

AM_CONDITIONAL([BUILD_SEPARATE_HELLO_LIBRARY],
               [test "x$enable_separate_hello_library" = "xyes"])

AC_SUBST([LIBTOOL_DEPS])

AC_OUTPUT([Makefile include/Makefile lib/Makefile src/Makefile man/Makefile])
