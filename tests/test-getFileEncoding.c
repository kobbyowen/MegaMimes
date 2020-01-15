#include "megamimetests.h"

void getMegaMimeFileEnc(void* ignored)
{

  assert_string_equal(getMegaTextFileEncoding("tests/data/utf-8.txt"), "UTF-8") ;
  assert_string_equal(getMegaTextFileEncoding("tests/data/utf-8bom-enc.txt"), "UTF-8") ;
  //assert_string_equal(getMegaTextFileEncoding("tests/data/utf-16be.txt"), "UTF-16BE") ;
  assert_string_equal(getMegaTextFileEncoding("tests/data/utf-16le.txt"), "UTF-16LE") ;
  assert_string_equal(getMegaTextFileEncoding("tests/data/MegaMimeTypes.json"), "UTF-8") ;
	assert_string_equal(getMegaTextFileEncoding("tests/data/bin.dat"), "UTF-8") ;
	assert_string_equal(getMegaTextFileEncoding("tests/data/MegaMimeTypes.json"), "UTF-8") ;
	
  assert_llong_equal(isTextFile("tests/data/utf-8.txt"), true) ;
  assert_llong_equal(isTextFile("tests/data/utf-8bom-enc.txt"), true) ;
  //assert_llong_equal(isTextFile("tests/data/utf-16be.txt"), true) ;
  assert_llong_equal(isTextFile("tests/data/utf-16le.txt"), true) ;
  assert_llong_equal(isTextFile("tests/data/MegaMimeTypes.json"), true) ;
  assert_llong_equal(isTextFile("data/utf8data.txt"), false) ; //does not exist

  assert_llong_equal(isTextFile("tests/data/MegaMimeTypes.json"), true) ;
  assert_llong_equal(isTextFile("tests/data/bin.dat"), false) ;
  
 }
