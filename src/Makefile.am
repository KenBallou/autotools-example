bin_PROGRAMS=greet greet_static

greet_SOURCES = main.c
greet_LDADD = ../lib/libhello.la
greet_CFLAGS = -I $(top_srcdir)/include

greet_static_SOURCES = main.c
greet_static_LDADD = ../lib/libhello.la
greet_static_CFLAGS = -I $(top_srcdir)/include
greet_static_LDFLAGS = -static

