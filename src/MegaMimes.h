/** @file */
/*
 MIT License

Copyright (c) 2020 Owen Trump

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
 * ./configure
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
 *    extensions = getMegaMimeExtensions("`video/`") ; 
 *    // returns {'*.3g2', '*.3gp', '*.avi', .... ,NULL}
 *    freeMegaStringArray(extensions) ;
 * 
 *    extensions = getMegaMimeExtensions("`*`") ;
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
 *  structure is returned by  getMegaFileInfo. It contains all the details 
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
  char*	mTextEncoding ;
  
} MegaFileInfo ;


/**
  @brief Get The Mime Type Of A File Or A File Extension
  
  The function gets the mime type of the file specified by the path. 
  The function does not check if the file exists or not. It just uses the file's basename 
  including the extension to lookup the mime type. The filename can also be an extension
  only, which is preceeded by a ".". Example (.mp3, mega.mp3, /usr/lib/mega.mp3 ) will all 
  return the same thing.
  
  @param pFileName
    The name of the file whose mime type should be determined
  @return 
    the mimetype of the file or NULL if no mimetype is known 
    for the file. The string returned should be freed
*/
char* getMegaMimeType ( const char* pFileName );


/**
  @brief Get The Extensions associated with Mime Types
  
  The function gets the file extensions for the mimetype. The mimetype should be 
  in the form type/sub-type, otherwise it is invalid. An optional version can be 
  added to the string. Any other trailing details are ignored. * character can be used to match
  everything. Eg `video/` returns all video file extensions and `*` returns all file extensions
  
  @param pMimeType
    The mimetype whose extension is to be determined 
  
  @return 
    An array of extension names. The array is terminated by a NULL. The function 
    returns NULL if no extensions were found for the mime types given.		 
*/
char** getMegaMimeExtensions ( const char* pMimeType );

/**
  @brief Get information about a file.
  
  Gets information about the file, such as the encoding, the mime name  the mime type and the the file size.
    
  @param pFilePath
    The name of the file whose information is to be determined. 
    
  @return 
    the information about the file. The structure returned should be freed 
    with freeMegaFileInfo. The function returns NULL if the file does not exists, or the user does not 
    have permissions to read from the file
*/
MegaFileInfo* getMegaFileInformation( const char* pFilePath );

/**
  @brief Determines if a file is a text file 
    
  Returns whether the file is a text file or not. The function
  is a really slow function, as it scans through every byte, checking
  to see if it is a control character or not. The encoding is taken into consideration.	
  
  @param path
    The path name for the file. If the file des not exist, false is returned.
  @return 
    whether the file is a text file or not. Returns false if the file does not eixist. 		
*/
bool isTextFile ( const char* path ); 

/**
  @brief Determines if ia file is a binary file
  
  Returns whether the file is a binary file or not 	
  
  @param path
    The path name for the file. 
  @return 
    whether the file is a binary file or not. Reutrns false if the file does not exist. 		
  
*/
bool isBinaryFile (const char* path );

/**
  @brief Gets the encoding for a text file.
  @pre The file is assumed to be a text file. Use isTextFile() to check the file before calling 
  		this function. 
  
  The function gets the encoding of the file. The string can be UTF-8, UTF-8, UTF-16LE, UTF-16
  UTF-32, UTF-32BE, UTF-32LE. The function does not check if the file is binary file or a text file.
  It is assumend that you are really sure that it is a binary file. You can use  isTextFile() to 
  first check if it is a text file, before using the function. 
  
  @param path
    The path name for the file  
  @return 
    the file encoding or empty string if the file does not exist or cannot be read.
*/
const char* getMegaTextFileEncoding( const char* path );

/**
  @brief Frees a MegaFileInfo structure
  
  The function deallocates and destroys a MegaFileInfo structure. If the structure is NULL, the function 
  simply and does nothing. 
  
  @param pData 
    The MegaFileInfo structure to be freed 
*/

void freeMegaFileInfo(MegaFileInfo* pData );

/**
  @brief Frees a string 
  
  The function deallocates and frees a string returned by any of the functions. The difference between
  this function and the std library  free , is that this function does nothing if its 
  argument is NULL
  
  @param pData
    The string to be freed 
*/
void freeMegaString( char* pData );

/**
  @brief Frees an array of strings.
  
  The function frees the dynamically allocated array of dynamically allocated strings returned by 
   getMegaMimeExtensions. The function simply does nothing if its argument is NULL
  
  @param pData 
    The string array to be freed.
*/
void freeMegaStringArray( char** pData) ;


#endif 
