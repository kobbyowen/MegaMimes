#include "megamimetests.h"

void getMegaMimeTypeTest(void* data)
{
  char * res = getMegaMimeType(".txt") ;
  assert_string_equal(res, "plain.txt") ;
  freeMegaString(res);

  res = getMegaMimeType(".1") ;
  assert_string_equal(res, "text/roff") ;
  freeMegaString(res);

  res = getMegaMimeType(".zip") ;
  assert_string_equal(res, "application/zip") ;
  freeMegaString(res);
  
  res = getMegaMimeType(".jp2") ;
  assert_string_equal(res, "image/jpx") ;
  freeMegaString(res);
  
  res = getMegaMimeType("/usr/data/owen.zip") ;
  assert_string_equal(res, "application/zip") ;
  freeMegaString(res);


  res = getMegaMimeType("/usr/owen/.zip") ;
  assert_string_equal(res, "application/zip") ;
  freeMegaString(res);


  res = getMegaMimeType(".zissp") ;
  assert_null(res) ;
  freeMegaString(res);


  res = getMegaMimeType("") ;
  assert_null(res) ;
  freeMegaString(res);

  res = getMegaMimeType("owen") ;
  assert_null(res) ;
  freeMegaString(res);
}