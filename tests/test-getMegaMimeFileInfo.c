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
 
  freeMegaFileInfo(res) ;

  res = getMegaFileInformation("");
  assert_null(res);
  
  res = getMegaFileInformation("tests/data/bin.dat") ;
  assert_nonnull(res);
  assert_null(res->mTextEncoding) ;
  freeMegaFileInfo(res);

  res = getMegaFileInformation("tests/data/23342342343243242423423/423432432432423423423423432423423423/43242342343242343243242343243243/32423432432432432423432432432432432/432243243434324343434324/32432434324324324234234324324/234234324324324324324324/32432432") ;
  assert_null(res) ;
  freeMegaFileInfo(res);

  res = getMegaFileInformation("tests/data/sucus.txt") ;
  assert_null(res);
  freeMegaFileInfo(res);

  res = getMegaFileInformation(NULL) ;
  assert_null(res);
  
}
