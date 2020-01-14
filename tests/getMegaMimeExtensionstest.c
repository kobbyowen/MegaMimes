#include "megamimetests.h"

#define IMAGES_LENGTH 98 
#define VIDEO_LENGTH 22
#define TEXT_LENGTH 221
#define AUDIO_LENGTH 40 
#define APPLICATION_LENGTH 342
#define ALL_LENGTH 739

size_t countResults( char** data)
{
  if(!data) return -1 ;
  size_t i = 0 ;
  for ( ;data[i] != NULL ; ++i) ;
  return i;
}

void testGetMegaMimeExtensions ( void* data )
{
  char** res = getMegaMimeExtensions("*/*") ;
  assert_ullong_equal( countResults(res), ALL_LENGTH ) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("video/*") ;
  assert_ullong_equal( countResults(res), VIDEO_LENGTH ) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("image/*") ;
  assert_ullong_equal( countResults(res), IMAGES_LENGTH ) ;
  freeMegaStringArray(res) ;
  
  res = getMegaMimeExtensions("audio/*") ;
  assert_ullong_equal( countResults(res), AUDIO_LENGTH ) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("application/*") ;
  assert_ullong_equal( countResults(res), APPLICATION_LENGTH ) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("text/*") ;
  assert_ullong_equal( countResults(res), TEXT_LENGTH ) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("video/mp4") ;
  assert_ullong_equal( countResults(res), 1 ) ;
  assert_string_equal(res[0], "*.mp4") ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("video/mpmp") ;
  assert_null(res) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("vid*eo/*") ;
  assert_null(res) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("") ;
  assert_null(res) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("/") ;
  assert_null(res) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions(NULL) ;
  assert_null(res) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("*/") ;
  assert_null(res) ;
  freeMegaStringArray(res) ;
  
  res = getMegaMimeExtensions("text/html") ;
  assert_string_equal("*.cshtml", res[0]) ;
  freeMegaStringArray(res) ;

  res = getMegaMimeExtensions("application/zip") ;
  assert_string_equal("*.zip", res[0]) ;
  freeMegaStringArray(res) ;
  
  res = getMegaMimeExtensions("application/xml") ;
  assert_string_equal("*.xml", res[0]) ;
  freeMegaStringArray(res) ;
  
}