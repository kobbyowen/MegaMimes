lib_LTLIBRARIES = libmegamimes-1.0.0.la
libmegamimes_1_0_0_la_SOURCES = src/MegaMimes.c
libmegamimes_1_0_0_la_LDFLAGS = -version-info 1:0:0
include_HEADERS = src/MegaMimes.h 

check_PROGRAMS = tests/run-tests
tests_run_tests_SOURCES = tests/getMegaMimeExtensionstest.c \
				tests/getMegaMimeFileInformationTest.c \
				tests/getMegaMimeTypeTest.c \
				tests/main.c \
				tests/tester.h \
				tests/megamimes.h 

tests_run_tests_CFLAGS = -DDEBUG 
tests_run_tests_LDADD = $(lib_LTLIBRARIES) tests/tester.o

