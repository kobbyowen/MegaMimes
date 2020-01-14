#include "megamimetests.h"

void getMegaMimeFileInformationtest(void* data)
{
  MegaFileInfo* res = getMegaFileInformation("tests/data") ;
  assert_null(res) ;

  res = getMegaFileInformation("owentrump") ;
  assert_null(res) ;

  res = getMegaFileInformation("..") ;
  assert_null(res);

  res = getMegaFileInformation("tests/data/formatMimes.py") ;
  assert_nonnull(res) ;
  assert_string_equal(res->mBaseDir, "tests/data/") ;
  assert_string_equal(res->mBaseName, "formatMimes") ;
  assert_string_equal(res->mExtension, ".py") ;
  assert_ullong_equal(res->mFileSize, 39111 ) ;
  assert_string_equal(res->mMimeType, "text/x-python") ;
  assert_ullong_equal(res->mTextFile, true) ;
 
  assert_string_equal(res->mTextEncoding, "UTF-8") ;
  freeMegaFileInfo(res) ;

  res = getMegaFileInformation("tests/data/bin.dat") ;
  assert_nonnull(res);
  assert_string_equal(res->mTextEncoding, "") ;
  freeMegaFileInfo(res);

  res = getMegaFileInformation("tests/data") ;
  assert_null(res) ;
  freeMegaFileInfo(res);

  res = getMegaFileInformation("tests/data/sucus.txt") ;
  assert_null(res);
  freeMegaFileInfo(res);

  res = getMegaFileInformation(NULL) ;
  assert_null(res);
  
/*
  assert_string_equal(getMegaTextFileEncoding("data/utf16_2.dat"), "UTF-16LE") ;
  assert_string_equal(getMegaTextFileEncoding("data/utf16be_2.dat"), "UTF-16BE") ;
  assert_string_equal(getMegaTextFileEncoding("data/utf32be_2.dat"), "UTF-32BE") ;
  assert_string_equal(getMegaTextFileEncoding("data/utf32le.dat"), "UTF-32LE") ;
  assert_string_equal(getMegaTextFileEncoding("data/MegaMimeTypes.json"), "UTF-8") ;

  assert_llong_equal(isTextFile("data/utf16_2.dat"), true) ;
  assert_llong_equal(isTextFile("data/utf16be_2.dat"), true) ;
  assert_llong_equal(isTextFile("data/utf16data.txt"), true) ;
  assert_llong_equal(isTextFile("data/utf32be_2.dat"), true) ;
  assert_llong_equal(isTextFile("data/utf32le_2.dat"), true) ;
  assert_llong_equal(isTextFile("data/utf8data.txt"), true) ;
*/
  assert_llong_equal(isTextFile("tests/data/MegaMimeTypes.json"), true) ;
  assert_llong_equal(isTextFile("tests/data/bin.dat"), false) ;

}
