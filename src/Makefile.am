bin_PROGRAMS=greet greet_static

greet_SOURCES = main.c
greet_LDADD = ../lib/libhello.la $(LTLIBINTL)
greet_CPPFLAGS = -DLOCALEDIR='"$(localedir)"' -I$(top_srcdir)/include

greet_static_SOURCES = main.c
greet_static_LDADD = ../lib/libhello.la $(LTLIBINTL)
greet_static_CPPFLAGS =  -DLOCALEDIR='"$(localedir)"' -I$(top_srcdir)/include
greet_static_LDFLAGS = -static
