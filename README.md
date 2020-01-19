# MegaMimes

MegaMimes is a C Library that is used to get the mimetype of a file, determine
whether a file is binary or text file and get a text file encoding. The library 
has no dependencies. It is tested on all major operating systems( windows, Linux, Mac OS)

## Installation

### On Unix

```
$ cd MegaMimes 
$ ./configure
$ make 
$ sudo make install 
```

### On Windows 

It is recommended that you copy the two files in the src sub directory 
and directly include them in your project directory. This is easy because 
the whole library is a single file. You can also use the
precompiled binaries that are located in win32 sub folder.

## Usage

### Getting  the  mime  type  of  a  file.
  
```c

#include "MegaMimes.h"
   
int main( int argc, char** argv)
{
    char* mimetype  = getMegaMimeType("/etc/settings.ini") ; // returns ''
 		
    // must not necessarily be a file which exists on the disk. 
    char* mimetype2 = getMegaMimeType(".mp4") ; // returns 'video/mp4'
 	
    char* mimetype3 = getMegaMimeType("owen"); // returns NULL ;
    
    freeMegaString(mimetype);
    freeMegaString(mimetype2);
    freeMegaString(mimetype3);
}
  ``` 

### Getting The File Extension Associated With A Mime Type
  
  ```c
  
  #include "MegaMimes.h"
  
  int main( int argc, char** argv)
  {
  
    char** extensions = getMegaMimeExtensions("video/mp4") ;
    // returns {'*.mp4', NULL}
    freeMegaStringArray(extensions);
    
    //get all video file extensions
    extensions = getMegaMimeExtensions("video/*") ;
    
    // returns {'*.3g2', '*.3gp', '*.avi', .... ,NULL}
    freeMegaStringArray(extensions) ;
    
    extensions = getMegaMimeExtensions("*/*") ;
    // returns all file extensions
 	freeMegaStringArray(extensions);
    
    extensions = getMegaMimeExtensions("text/rr") ;
    // returns NULL because no extension has that mime name  
 }
  ```
   
  
### Getting Information About A File 
  
  ```c
 #include "MegaMimes.h"
   
 int main( int argc, char** argv)
 {
    MegaFileInfo * fileinfo = getMegaFileInformation("/usr/package.json") ;
  	
    if (!fileinfo) 
  	{ 
        printf("The file does not exits or you may not have read permission.");
        return 1 ;
    }
    else
    {	
        printf("Directory : %s\n", fileinfo->mBaseDir) ;
        printf("Base Name : %s\n", fileinfo->mBaseName) ;
        printf("File Extension : %s\n", fileinfo->mExtension) ;
        printf("File Size : %lld Bytes\n", fileinfo->mFileSize ) ;
        printf("Mime Type : %s\n", fileinfo->mMimeType) ;
        printf("Mime Name : %s\n", fileinfo->mMimeName) ;
        
        if(fileinfo->mTextFile)
        {
            printf("File Type : Text File , Encoding : %s", fileinfo->mTextEncoding);
        }
        else printf("File Type : Binary File") ;
        
        // Output 
        // Directory : /usr/
        // Base Name : package
        // File Extension : .json 
        // File Size : 124564 Bytes
        // Mime Type : application/json 
        // Mime Name : JSON (JavaScript Object Notation)
        // File Type : Text File, Encoding : UTF-8
        
        freeMegaFileInfo(fileinfo) ;
 	}
   
  ```

### Determing The Encoding Of A Text File

  ```c
  #include "MegaMimes.h"
  
  int main( int argc, char** argv)
  {
    const char* file = "../data/MegaMimeTypes.txt" ;
    
    if (isTextFile(file))
    {
        const char* enc = guessMegaTextFileEncoding(file) ;
        printf("The file is encode in %s", enc) ; //Output: UTF-8
    }
    else
    {
        printf("The file is a binary file") ;
    }
  } 
  ```

### Determing Whether A  File Is A Text File Or Not 
  
  ```c
  #include "MegaMimes.h"
  
  int main(int argc, char** argv)
  {
    bool istext = isTextFile("../data/formatMimes.py") ;
    
    if(istext)
    {
        printf("The file is a text file") ;
    }
    else
    {
        printf("The file is a binary file") ;
    }
    
  }
  ```
  
## Contributing
Pull requests are welcome. For major changes or to add new mime types, please open an issue first to discuss what you would like to change or the mime type you would like to add.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
