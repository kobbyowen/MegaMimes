#include "megamimetests.h"

int main(int argc, char** argv)
{
  TestStructure st ;
  test_init(&st) ;

  test_add_func(&st, "getMegaMimeType()", getMegaMimeTypeTest, NULL) ;
  test_add_func(&st, "getMegaMimeExtensions()", testGetMegaMimeExtensions, NULL) ;
  test_add_func(&st, "getMegaFileInformation()", getMegaMimeFileInformationtest, NULL);
  test_add_func(&st, "getMegatextFileEncoding()", getMegaMimeFileEnc, NULL);
  run_tests(&st) ;
} 
