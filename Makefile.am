lib_LTLIBRARIES = libmegamimes-1.0.la
libmegamimes_1_0_la_SOURCES = src/MegaMimes.c
libmegamimes_1_0_la_LDFLAGS = -version-info 1:0
libmegamimes_1_0_la_CFLAGS = -std=c11 
include_HEADERS = src/MegaMimes.h 

check_PROGRAMS = tests/run-tests
tests_run_tests_SOURCES = tests/test-getMegaMimeExtensions.c \
				tests/test-getMegaMimeFileInfo.c \
				tests/test-getMegaMimeType.c \
				tests/main.c \
				tests/test-getFileEncoding.c \
				tests/tester.h \
				tests/megamimes.h 

TESTS=tests/run-tests
tests_run_tests_CFLAGS = -DDEBUG 
tests_run_tests_LDADD = $(lib_LTLIBRARIES) tests/tester.o

pkgconfig_DATA = libmegamimes.pc 
