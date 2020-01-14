/**
 * @file "MegaMimes.h"
 */
/**
 * @mainpage 
 * MegaMimes is a simple C Library that is used to get the mime type information
 * about a file. It is a lightweight library that is tested accross all platforms.
 * The library does not have any dependencies. The library determines the mime type
 * of a file based on its extension. The library also includes functions to determine 
 * whether a file is a binary file or a textfile . The library is really simple to use.
 * @n
 * @n
 * 
 * @b Installation 
 * @b On @b Unix @b Systems
 * @code 
 * cd MegaMimes 
 * make 
 * sudo make install 
 * @endcode 
 * 
 * @b On @b Windows 
 * \n It is recommended that you copy the two files in the src sub directory 
 * and directly include them in your project directory. This is easy because 
 * the who library is a single file. Other than that you can also use the
 * precompiled binaries that are located in win32 sub folder.
 * 
 * 
 * \n @b Examples \n 
 * @b Getting @b the @b mime @b type @b of @b a @b file.\n
 * @code
 * 
 * #include "MegaMimes.h"
 *  
 *	int main( int argc, char** argv)
 *	{
 *		char* mimetype  = getMegaMimeType("/etc/settings.ini") ; // returns ''
 *		
 *		// must not necessarily be a file which exists on the disk. 
 *		char* mimetype2 = getMegaMimeType(".mp4") ; // returns 'video/mp4'
 *		
 *		char* mimetype3 = getMegaMimeType("owen"); // returns NULL ;
 *
 *		freeMegaString(mimetype);
 *		freeMegaString(mimetype2);
 *		freeMegaString(mimetype3);
 *	}
 *  
 * @endcode
 * 
 * @b Getting @b The @b File @b Extension @b Associated @b With @b A @b Mime @b Type
 * @code
 * #include "MegaMimes.h"
 *  
 *	int main( int argc, char** argv)
 *	{
 *		char** extensions = getMegaMimeExtensions("video/mp4") ;
 *		// returns {'*.mp4', NULL}
 *		freeMegaStringArray(extensions);
 *
 *		// get all video file extensions
 *    extensions = getMegaMimeExtensions("video") ; 
 *    // returns {'*.3g2', '*.3gp', '*.avi', .... ,NULL}
 *    freeMegaStringArray(extensions) ;
 * 
 *    extensions = getMegaMimeExtensions("*") ;
 *    // returns all file extensions
 *    freeMegaStringArray(extensions);
 *
 *    extensions = getMegaMimeExtensions("text/rr") ;
 *    // returns NULL because no extension has that mime name 
 * 
 *	}
 * @endcode 
 * 
 * @b Getting @b Information @b About @b A @b File 
 * @code 
 * #include "MegaMimes.h"
 *  
 *	int main( int argc, char** argv)
 *	{
 *		MegaFileInfo* fileinfo = getMegaFileInformation("/usr/package.json") ;
 *    	
 * 		if (!fileinfo) 
 * 		{ 
 * 				printf("The file does not exits or you may not have read permission.");
 * 				return 1 ;
 * 		}
 * 		else
 * 		{	
 * 			printf("Directory : %s\n", fileinfo->mBaseDir) ;
 * 			printf("Base Name : %s\n", fileinfo->mBaseName) ;
 * 			printf("File Extension : %s\n", fileinfo->mExtension) ;
 * 			printf("File Size : %lld Bytes\n", fileinfo->mFileSize ) ;
 * 			printf("Mime Type : %s\n", fileinfo->mMimeType) ;
 * 			printf("Mime Name : %s\n", fileinfo->mMimeName) ;
 * 			
 * 			if(fileinfo->mTextFile)
 * 			{
 * 				printf("File Type : Text File , Encoding : %s", fileinfo->mTextEncoding);
 * 			}
 * 			else printf("File Type : Binary File") ;
 * 		}
 * 		// Output 
 * 		// Directory : /usr/
 * 		// Base Name : package
 *         // File Extension : .json 
 * 		// File Size : 124564 Bytes
 * 		// Mime Type : application/json 
 * 		// Mime Name : JSON (JavaScript Object Notation)
 *         // File Type : Text File, Encoding : UTF-8
 * 
 * 		freeMegaFileInfo(fileinfo) ;
 *	}
 * @endcode 
 * 
 * @b Determing @b Whether @b A  @b File @b Is @b A @b Text @b File @b Or @b Not 
 * @code
 * #include "MegaMimes.h"
 * 
 * int main(int argc, char** argv)
 * {
 * 	bool istext = isTextFile("../data/formatMimes.py") ;
 *     if(istext)
 * 	{
 * 		printf("The file is a text file") ;
 * 	}
 *     else
 * 	{
 * 		printf("The file is a binary file") ;
 * 	}
 *  
 * }
 * @endcode 
 * 
 * @b Determing @b The @b Encoding @b Of @b A @b Text @b File
 * @code
 * #include "MegaMimes.h"
 * 
 * int main( int argc, char** argv)
 * {
 * 	 const char* file = "../data/MegaMimeTypes.txt" ;
 * 
 *      if (isTextFile(file))
 * 	 {
 * 		 const char* enc = guessMegaTextFileEncoding(file) ;
 * 		 printf("The file is encode in %s", enc) ; //Output: UTF-8
 * 	 }
 *      else
 * 	 {
 * 		 printf("The file is a binary file") ;
 * 	 }
 * } 
 * @endcode 
 * 
 */ 
#ifndef _MEGAMIMES_H_
#define _MEGAMIMES_H_

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <wctype.h>
#include <limits.h>
 

#ifdef __unix__
  #define FILE_PATH_SEP '/'
#else 
  #define FILE_PATH_SEP '\\'
#endif 

/**
 * 	MegaFileInfo is the structure that conains information about a file.  The 
 *  structure is returned by @func getMegaFileInfo. It contains all the details 
 *  that is needed about a file. 
 */
typedef struct
{
  char*	mBaseDir ;
  char* 	mBaseName ;
  char*	mExtension ;
  long long mFileSize ;
  
  char* 	mMimeType ;
  char* 	mMimeName ;
  
  bool 	mTextFile ;
  const char*	mTextEncoding ;
  
} MegaFileInfo ;


/**
  @brief
    The function gets the mime type of the file specified by the path. 
    The function does not check if the file exists or not. It just uses the file basename 
    including the extension to lookup the mime type. The filename can also be an extension
    only, which is preceeded by a ".". Example (.mp3, mega.mp3, /usr/lib/mega.mp3 ) will all 
    return the same thing.
  @param pFileName
    The name of the file whose mime type should be guessed
  @return 
    the mimetype of the file or NULL if no mimetype is known 
    for the file. The string returned should be freed
*/
char* getMegaMimeType ( const char* pFileName );


/**
  @brief 
    The function guesses the file extension for the mimetype. The mimetype should be 
    in the form first-part/second-part, otherwise it is invalid. An optional version can be 
    added to the string. Any other trailing details are ignored. Pattern matching could also be
    used
  
  @param pMimeType
    The mimetype whose extension is to be determined 
  
  @return 
    An array of extension names. The array is terminated by a NULL. The function 
    returns NULL if no extensions were found for the mime types given.		 
*/
char** getMegaMimeExtensions ( const char* pMimeType );

/**
  @brief
    Gets information about the file. The file need not exist.
    If the file name has no extension, NULL is returned.
    
  @param pFilePath
    The name of the file whose information is to be determined. Can be 
    and extension, which in that case a dot must be the first character.
    
  @return 
    the information about the file. The structure returned should be freed 
    with ot_fileinfo_free
*/
MegaFileInfo* getMegaFileInformation( const char* pFilePath );

/**
  @brief 
    Returns whether the fileis a text file or not. The function
    is a really slows function, as it scans through every byte, checking
    to see if it is a control character or not. 	
  @param pUrl 
    The path name for the file. If the file des not exist, false is returned.
  @return 
    whether the file is a text file or not 		
*/
bool isTextFile ( const char* path ); 

/**
  @brief 
    Returns whether the file is a binary file or not 	
  @param pUrl 
    The path name for the file. If the file des not exist, false is returned.
  @return 
    whether the file is a bnary file or not 		
  
*/
bool isBinaryFile (const char* path );

/**
  @brief 
    The function gets the encoding of the file. The string can be utf-8, utf-16BE, utf-16LE, utf-16
    utf-32, urtf-32BE, utf-32LE. The function does not check if the file is binary file or a text file.
    It is assumend that you are really sure that it is a binary file. You can use @func isTextFile to 
    first check if it is a text file, before using the function. 
  @param path
    The path name for the file. If the file des not exist, NULL is returned if the file does not exist, or
    you do not have permissions to read from the file or any of its parent directories.
  @return 
    the file encoding or NULL 		
*/
const char* getMegaTextFileEncoding( const char* path );

/**
  @brief 
    The function deallocates and destroys a MegaFileInfo structure. If the structure is NULL, the function 
    simply returns nothing and does nothing. 
  @param pData 
    The MegaFileInfo structure to be freed 
*/

void freeMegaFileInfo(MegaFileInfo* pData );

/**
  @brief 
    The function deallocates and frees a string returned by any of the functions. The difference between
    this function and the std library @func free , is that this function does nothing if its 
    argument is NULL
  @param pData
    The string to be freed 
*/
void freeMegaString( char* pData );

/**
  @brief
    The function frees the dynamically allocated array of dynamically allocated strings returned by 
    @func getMegaMimeExtensions. The function simply does nothing ig its argument is NULL
  @param pData 
    The string array to be freed.
*/
void freeMegaStringArray( char** pData) ;


#endif 
