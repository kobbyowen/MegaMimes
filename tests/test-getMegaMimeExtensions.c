#include "megamimetests.h"

#define IMAGES_LENGTH 98 
#define VIDEO_LENGTH 23
#define TEXT_LENGTH 221
#define AUDIO_LENGTH 39 
#define APPLICATION_LENGTH 342
#define ALL_LENGTH 739

size_t countResults( const char** data)
{
  if(!data) return -1 ;
  size_t i = 0 ;
  for ( ;data[i] != NULL ; ++i) ;
  return i;
}

void testGetMegaMimeExtensions ( void* data )
{
  const char** res = getMegaMimeExtensions("*/*") ;
  assert_ullong_equal( countResults(res), ALL_LENGTH ) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("video/*") ;
  assert_ullong_equal( countResults(res), VIDEO_LENGTH ) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("image/*") ;
  assert_ullong_equal( countResults(res), IMAGES_LENGTH ) ;
  freeMegaStringArray((char**)res) ;
  
  res = getMegaMimeExtensions("audio/*") ;
  assert_ullong_equal( countResults(res), AUDIO_LENGTH ) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("application/*") ;
  assert_ullong_equal( countResults(res), APPLICATION_LENGTH ) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("text/*") ;
  assert_ullong_equal( countResults(res), TEXT_LENGTH ) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("video/mp4") ;
  assert_ullong_equal( countResults(res), 2) ;
  assert_string_equal(res[0], "*.f4a") ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("video/mpmp") ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("vid*eo/*") ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("") ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("/") ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions(NULL) ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("*/") ;
  assert_null(res) ;
  freeMegaStringArray((char**)res) ;
  
  res = getMegaMimeExtensions("text/html") ;
  assert_string_equal("*.cshtml", res[0]) ;
  freeMegaStringArray((char**)res) ;

  res = getMegaMimeExtensions("application/zip") ;
  assert_string_equal("*.zip", res[0]) ;
  freeMegaStringArray((char**)res) ;
  
  res = getMegaMimeExtensions("application/xml") ;
  assert_string_equal("*.xml", res[0]) ;
  freeMegaStringArray((char**)res) ;
  
}
