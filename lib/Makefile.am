if BUILD_SEPARATE_HELLO_LIBRARY
lib_LTLIBRARIES = libhello.la
else
noinst_LTLIBRARIES = libhello.la
endif

libhello_la_SOURCES = hello.c
libhello_la_CPPFLAGS = -I$(top_srcdir)/include
libhello_la_LDFLAGS = -version-info 1:0:0

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ../config.status libtool
