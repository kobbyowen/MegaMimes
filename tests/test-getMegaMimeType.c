#include "megamimetests.h"

void getMegaMimeTypeTest(void* data)
{
  const char * res = getMegaMimeType(".txt") ;
  assert_string_equal(res, "text/plain") ;

  res = getMegaMimeType(".1") ;
  assert_string_equal(res, "text/troff") ;
 
  res = getMegaMimeType(".zip") ;
  assert_string_equal(res, "application/zip") ;
  
  res = getMegaMimeType(".jp2") ;
  assert_string_equal(res, "image/jpx") ;
  
  res = getMegaMimeType("/usr/data/owen.zip") ;
  assert_string_equal(res, "application/zip") ;
 

  res = getMegaMimeType("/usr/owen/.zip") ;
  assert_string_equal(res, "application/zip") ;
 

  res = getMegaMimeType(".zissp") ;
  assert_null(res) ;
 

  res = getMegaMimeType("") ;
  assert_null(res) ;
 
  res = getMegaMimeType("owen") ;
  assert_null(res) ;

}
