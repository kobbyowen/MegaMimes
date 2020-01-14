#ifndef _TESTER_H_
#define _TESTER_H_

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

long long passed, failed ;

typedef void (*TestFunction)(void*) ;
typedef void* TestData ;

typedef struct {

  const char** testNames ;
  TestFunction* testFunctions;
  TestData* testData ;
  size_t size , pos;

}TestStructure ;

void test_init(TestStructure* data) ;
bool test_add_func( TestStructure* structure, const char* name, TestFunction func, TestData data) ;
void run_tests( TestStructure* data) ;

void assert_null( const void* ptr ) ;
void assert_nonnull(const void* ptr) ;

void assert_string_equal( const char* s1, const char*s2) ;
void assert_string_nequal( const char* s1, const char* s2) ;
void assert_string_greater( const char* s1, const char* s2) ;
void assert_string_less( const char* s1, const char* s2) ;

void assert_int_equal( int a, int b) ;
void assert_int_nequal( int a, int b) ;
void assert_int_greater( int a, int b) ;
void assert_int_less( int a, int b) ;

void assert_uint_equal( unsigned int a, unsigned int b) ;
void assert_unint_nequal(unsigned int a, unsigned int b) ;
void assert_uint_greater(unsigned int a, unsigned int  b) ;
void assert_uint_less( unsigned int a, unsigned int b) ;

void assert_long_equal( long a, long b) ;
void assert_long_nequal(long a, long b) ;
void assert_long_greater(long a, long  b) ;
void assert_long_less( long a, long b) ;


void assert_ulong_equal( unsigned long a, unsigned long b) ;
void assert_ulong_nequal(unsigned long a, unsigned long b) ;
void assert_ulong_greater(unsigned long a, unsigned long  b) ;
void assert_ulong_less( unsigned long a, unsigned long b) ;

void assert_llong_equal( long long a, long long b) ;
void assert_llong_nequal( long long a, long long b) ;
void assert_llong_greater( long long a, long long  b) ;
void assert_llong_less( long long a, long long b) ;

void assert_ullong_equal( unsigned long long a, unsigned long long b) ;
void assert_ullong_nequal(unsigned long long a, unsigned long long b) ;
void assert_ullong_greater(unsigned long long a, unsigned long long  b) ;
void assert_ullong_less( unsigned long long a, unsigned long long b) ;

void assert_float_equal( float a, float b) ;
void assert_float_nequal( float a, float b) ;
void assert_float_greater(float a, float b) ;
void assert_float_less( float a, float b) ;

void assert_double_equal( double a, double b) ;
void assert_double_nequal( double a, double b) ;
void assert_double_greater( double a, double b) ;
void assert_double_less( double a, double b) ;

void assert_ldouble_equal( long double a, long double b) ;
void assert_ldouble_nequal( long double a, long double b) ;
void assert_ldouble_greater(long double a, long double b) ;
void assert_ldouble_less( long double a, long double b) ;

#endif 
