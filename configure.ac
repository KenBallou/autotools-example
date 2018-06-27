### Except for AC_PREREQ, this needs to be the first macro in this file.
### This one macro creates a LOT of code in the configure script.  On
### a Debian 9 system, a configure.ac file with just this one macro
### causes Autoconf to create a configure script with 1,673 lines.
AC_INIT([hello], [1.0])

### Instead of cluttering up the top level directory, this macro causes
### Autoconf to create a build-aux/ directory for any scripts Autotools
### needs to provide.
AC_CONFIG_AUX_DIR([build-aux])

### Similarly, this causes any macro files Autotools needs to copy to be
### placed in an m4/ directory under the top level.
AC_CONFIG_MACRO_DIR([m4])

### This macro causes Autoconf to place all its test results in the file
### config.h in the top level directory.  (It might be better to put this
### file in the include/ directory.  Also, if the project already has a
### config.h header, this file could easily be renamed (such as autoconfig.h).
AC_CONFIG_HEADERS([config.h])

### Normally, we could just use the macro AC_PROG_CC to check for the presence
### of a C compiler and to determine how to invoke it.  (This generates the
### CC macro for Makefiles.  However, src/main.c uses a C99 construct
### (declaring a loop variable inside the "for" statement).  So we need to
### determine whether the C compiler implements the C99 standard, and if
### so, how to invoke the C compiler to use the C99 standard.
###
### It is possible to specify a list of compilers to try before Autoconf's
### default list.  For example, if the developer has a preference for, say,
### clang, then write: AC_PROG_CC_C99([clang])
### This will use clang if it is installed (and findable by Autoconf) and
### look for another compiler if clang is not installed.  Similarly, if we
### had another hypothetical compiler "ccomp", we could write
### AC_PROG_CC_C99([clang ccomp]) to check first for clang, then ccomp, and
### then for Autoconf's default.
###
### (Note: GNU gcc automatically accepts C99 code by default.  The need for
### this macro was not apparent until we tried to compile this code on an
### OpenBSD system.  LESSON LEARNED:  When developing a project that uses
### Autotools for its build system, it is very worthwhile to test the build
### on a non-Linux system (or, preferably, as many non-Linux systems as
### reasonably possible).  Fortunately, virtual machines make this a much
### more feasible task.
AC_PROG_CC_C99

### This and the next macro are the minimum that needs to be done to use
### Automake.  Specifying the "foreign" argument tells Automake that this
### project does not conform to the GNU coding standard and prevents Automake
### from complaining about the omission of files required by the GNU standard
###(AUTHORS, COPYING, and so on).
AM_INIT_AUTOMAKE([foreign])

### These two macros are the minimum required to use GNU gettext (for
### internationalization).  The "external" argument to AM_GNU_GETTEXT means
### that we are not providing the gettext source in this distribution.
### Instead, we are relying on an installed gettext package whose version
### is at least 0.19,8.
###
### OpenBSD note:  Installing GNU gettext installs files in the /usr/local
### hierarchy.  The configure script will not find packages installed in
### /usr/local without help.  The user can run configure with the options
###  "--with-libintl-prefix=/usr/local --with-iconv-prefix=/usr/local" to tell
### configure where the packages are installed.  However, it's ugly to make
### the user have to do this.  Let's give configure a little help:  if we
### find the libraries in /usr/local/lib and the user has not already
### specified values for the prefixes, we'll set them here.
###
### It is really important to remember that configure.ac is really just
### a very heavily macroized shell script.  It is entirely possible to
### insert shell script in configure.ac.  However, be careful to write
### portable shell script, as the whole point of Autotools is to deal
### with portability issues across systems.  (For example, the Autotools
### always use "test" instead of "[" because of portability issues.)
if test \( -f /usr/local/lib/libiconv.a \) -a \
        \( -z "${with_libiconv_prefix}" \) ; then
    with_libiconv_prefix=/usr/local
fi
if test \( -f /usr/local/lib/libintl.a \) -a \
        \( -z "${with_libintl_prefix}" \) ; then
    with_libintl_prefix=/usr/local
fi
AM_GNU_GETTEXT(external)
AM_GNU_GETTEXT_VERSION(0.19.8)

### This macro causes Autoconf to create a substitution variabloe for Automake
### named LIBTOOL_DEPS.  When Automake processes Makefile.am to create
### Makefile.in, it may create references to @LIBTOOL_DEPS@.  When the configure
### script processes Makefile.in to create Makefile. it will create a Make
### variable LIBTOOL_DEPS whse value is whatever the configure script has
### determined is needed (this may be the empty string).
AC_SUBST([LIBTOOL_DEPS])

### This is the minimum needed to use libtool.
LT_INIT

### So this is more than the bare minimum needed to use autotools, but it
### seems worthwhile to show how to use --enable-* (--disable-*, --enable-*=no)
### and with-* configuration options.  (The with-* options work very
### similarly to enable-*, but we do not include an example.)
###
### The hello library (lib/hello.c) can either be compiled as a shared and
### static library (libhello.so/libhello.a) that is installed in the lib/
### directory ($libdir, or $prefix/lib), or it can be compiled as a "utility
### library" (autotools terminology).  A "utility library" is not installed
### upon "make install".  It is just a library archive (.a file) that is linked
### in with the main executable.
AC_ARG_ENABLE([separate-hello-library],
              [AS_HELP_STRING([--enable-separate-hello-library],
                              [build a separate shared libhello.so library])],
              [],
              [enable_separate_hello_library=no])

### This AM_CONDITIONAL macro is one way to connect the result of AC_ARG_ENABLE
### to the build process.  The default we specified in AC_ARG_ENAABLE above
### was enable_separate_hello_library=no.  If the user specified any of:
###     --enable-separate-hello-library, enable-separate-hello
###     --enable-separate-hello-library=yes
###     --disable-separate-hello-library=no
### then the shell variable enable_separate_hello_library will be assigned
### the value "yes".  The AM_CONDITIONAL macro provides a string of shell
### code (the "test" expression) which, if true, causes Automake to set
### BUILD_SEPARATE_HELLO_LIBRARY to true.
###
### Refer to lib/Makefile.am to see how this affects the build.  If the user
### wants a separate library, we define lib_LTLIBRARIES.  Otherwise, we
### define noinst_LTLIBRARIES to indicate this is a utility library.  (Yes,
### that really is all there is to it.)
AM_CONDITIONAL([BUILD_SEPARATE_HELLO_LIBRARY],
               [test "x$enable_separate_hello_library" = "xyes"])

### Finally, we specify all the output files the configure script should
### create.  Since we did not specify input files, each Makefile is generated
### from the corresponding Makefile.in (which itself was generated from
### Makefile.am by Automake).
AC_OUTPUT([Makefile include/Makefile lib/Makefile src/Makefile man/Makefile po/Makefile.in])
