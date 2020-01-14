#include "MegaMimes.h"

static const char* MegaMimeTypes = "*.1\tRoff Manpage\ttext/troff\t0\n"
"*.3ds\t3DS\timage/x-3ds\t0\n"
"*.3fr\tHasselblad raw image\timage/x-raw-hasselblad\t0\n"
"*.3g2\t3G2\tvideo/3gpp2\t0\n"
"*.3gp\t3GP\tvideo/3gpp\t0\n"
"*.3mf\t3MF 3D Manufacturing Format\tapplication/vnd.ms-package.3dmanufacturing-3dmodel+xml\t0\n"
"*.4th\tForth source code\ttext/x-forth\t0\n"
"*.669\tModule Music Formats (Mods)\taudio/x-mod\t0\n"
"*.6pl\tPerl 6\ttext/x-perl\t0\n"
"*.7z\t7-zip archive\tapplication/x-7z-compressed\t0\n"
"*.8svx\t8-Bit Sampled Voice\taudio/8svx\t0\n"
"*.ML\tStandard ML\ttext/x-ocaml\t0\n"
"*.MYD\tMySQL MISAM Data\tapplication/x-mysql-misam-data\t0\n"
"*.MYI\tMySQL MISAM Compressed Index\tapplication/x-mysql-misam-compressed-index\t0\n"
"*.R\tR\ttext/x-rsrc\t0\n"
"*.TIF\tTIFF Uncompressed File with Exif Metadata\timage/tiff\t0\n"
"*.XXX\tTemplate:File Format/Preload\tapplication/octet-stream\t0\n"
"*.Z\tCompress\tapplication/x-compress\t0\n"
"*.aa\tAudible.Com File Format\taudio/x-pn-audibleaudio\t0\n"
"*.ac3\tDolby Digital AC-3\taudio/ac3\t0\n"
"*.acsm\tAdobe Content Server Message File\tapplication/vnd.adobe.adept+xml\t0\n"
"*.ada\tAda source code\ttext/x-ada\t0\n"
"*.adf\tAppleDouble\tmultipart/appledouble\t0\n"
"*.afa\tAstrotite\tapplication/x-astrotite-afa\t0\n"
"*.afm\tAdobe Font Metric\tapplication/x-font-adobe-metric\t0\n"
"*.ai\tAdobe Illustrator Artwork\tapplication/illustrator\t0\n"
"*.aif\tAudio Interchange File Format\taudio/x-aiff\t0\n"
"*.aifc\tAudio Interchange File Format (compressed)\taudio/x-aiff\t0\n"
"*.aiff\tAIFF\taudio/x-aiff\t0\n"
"*.air\tAdobe Air 1.0\tapplication/vnd.adobe.air-application-installer-package+zip;version=\"1.0\"\t0\n"
"*.aj\tAspectJ source code\ttext/x-aspectj\t0\n"
"*.amr\tAMR, Adaptive Multi-Rate Speech Codec\taudio/amr\t0\n"
"*.anim\tUnity3D Asset\ttext/x-yaml\t0\n"
"*.anpa\tAmerican Newspaper Publishers Association Wire Feeds\ttext/vnd.iptc.anpa\t0\n"
"*.ans\t7-bit ANSI Text\ttext/plain\t0\n"
"*.apl\tAPL\ttext/apl\t0\n"
"*.apng\tAnimated Portable Network Graphics\timage/vnd.mozilla.apng\t0\n"
"*.applescript\tAppleScript source code\ttext/x-applescript\t0\n"
"*.apr\tLotus Approach View File 97\tapplication/vnd.lotus-approach;version=\"97\"\t0\n"
"*.apt\tLotus Approach View File\tapplication/vnd.lotus-approach\t0\n"
"*.arc\tInternet Archive 1.0\tapplication/x-internet-archive;version=\"1.0\"\t0\n"
"*.arw\tSony raw image\timage/x-raw-sony\t0\n"
"*.as\tActionScript source code\ttext/x-actionscript\t0\n"
"*.asc\t7-bit ASCII Text\ttext/plain\t0\n"
"*.asciidoc\tAsciidoc source code\ttext/x-asciidoc\t0\n"
"*.asf\tAdvanced Systems Format\tapplication/vnd.ms-asf\t0\n"
"*.asice\tExtended Associated Signature Container\tapplication/vnd.etsi.asic-e+zip\t0\n"
"*.asics\tSimple Associated Signature Container\tapplication/vnd.etsi.asic-s+zip\t0\n"
"*.asn\tASN.1\ttext/x-ttcn-asn\t0\n"
"*.asp\tASP\tapplication/x-aspx\t0\n"
"*.aspx\tASP .NET\ttext/aspdotnet\t0\n"
"*.asy\tLTspice Symbol\ttext/x-spreadsheet\t0\n"
"*.atom\tAtom\tapplication/atom+xml\t0\n"
"*.au\tuLaw/AU Audio File\taudio/basic\t0\n"
"*.avi\tAVI (Audio Video Interleaved) File Format\tvideo/msvideo\t0\n"
"*.awb\tAdaptive Multi-Rate Wideband Audio\taudio/amr-wb\t0\n"
"*.awk\tAWK script\ttext/x-awk\t0\n"
"*.axc\tAxc\ttext/plain\t0\n"
"*.axx\tAxCrypt\tapplication/x-axcrypt\t0\n"
"*.b\tBrainfuck\ttext/x-brainfuck\t0\n"
"*.b6z\tB6Z\tapplication/x-b6z-compressed\t0\n"
"*.bas\tBasic source code\ttext/x-basic\t0\n"
"*.bay\tCasio raw image\timage/x-raw-casio\t0\n"
"*.bik\tBink Video\tvideo/vnd.radgamettools.bink\t0\n"
"*.bik2\tBink Video Format 2\tvideo/vnd.radgamettools.bink;version=\"2\"\t0\n"
"*.bin\tMacBinary\tapplication/x-macbinary\t0\n"
"*.bmp\tWindows bitmap\timage/bmp\t0\n"
"*.bpg\tBetter Portable Graphics\timage/x-bpg\t0\n"
"*.bpm\tBizAgi Process Modeler\tapplication/bizagi-modeler\t0\n"
"*.bsp\tBSP\tmodel/vnd.valve.source.compiled-map\t0\n"
"*.btf\tBigTIFF\timage/tiff\t0\n"
"*.bw\tSilicon Graphics Image\timage/x-sgi-bw\t0\n"
"*.bz2\tBzip2\tapplication/x-bzip2\t0\n"
"*.c\tC source code\ttext/x-csrc\t0\n"
"*.cab\tCabinet\tapplication/vnd.ms-cab-compressed\t0\n"
"*.cabal\tCabal Config\ttext/x-haskell\t0\n"
"*.cap\tpcap Packet Capture\tapplication/vnd.tcpdump.pcap\t0\n"
"*.catmaterial\tCATIA 5\tapplication/octet-stream;version=\"5\"\t0\n"
"*.catpart\tCATIA Model (Part Description) 5\tapplication/octet-stream;version=\"5\"\t0\n"
"*.catproduct\tCATIA Product Description 5\tapplication/octet-stream;version=\"5\"\t0\n"
"*.cbl\tCOBOL source code\ttext/x-cobol\t0\n"
"*.cbor\tConcise Binary Object Representation container\tapplication/cbor\t0\n"
"*.cbz\tComic Book Archive\tapplication/x-cbr\t0\n"
"*.cca\tcc:Mail Archive Email Format\tapplication/octet-stream\t0\n"
"*.cda\tCD Audio\tapplication/x-cdf\t0\n"
"*.cdf\tnetCDF-3 Classic\tapplication/x-netcdf\t0\n"
"*.cdx\tChemical Draw Exchange Format\tchemical/x-cdx\t0\n"
"*.cfm\tColdFusion source code\ttext/x-coldfusion\t0\n"
"*.cfs\tCompact File Set\tapplication/x-cfs-compressed\t0\n"
"*.cgi\tCGI script\ttext/x-cgi\t0\n"
"*.cgm\tComputer Graphics Metafile\timage/cgm\t0\n"
"*.chm\tMicrosoft Compiled HTML Help\tapplication/vnd.ms-htmlhelp\t0\n"
"*.chrt\tKChart File\tapplication/x-kchart\t0\n"
"*.chs\tC2hs Haskell\ttext/x-haskell\t0\n"
"*.cif\tCIF\tchemical/x-cif\t0\n"
"*.ck\tChucK\ttext/x-java\t0\n"
"*.cl\tCommon Lisp source code\ttext/x-common-lisp\t0\n"
"*.class\tJava Class File\tapplication/x-java\t0\n"
"*.clj\tClojure source code\ttext/x-clojure\t0\n"
"*.cls\tVisual basic source code\ttext/x-vbasic\t0\n"
"*.cmake\tCMake\ttext/x-cmake\t0\n"
"*.cml\tCML\tchemical/x-cml\t0\n"
"*.cob\tCOBOL\ttext/x-cobol\t0\n"
"*.cod\tLightning Strike\timage/cis-cod\t0\n"
"*.coffee\tCoffeeScript\tapplication/vnd.coffeescript\t0\n"
"*.cp\tComponent Pascal\ttext/x-pascal\t0\n"
"*.cpio\tUNIX CPIO Archive\tapplication/x-cpio\t0\n"
"*.cpp\tC++ source code\ttext/x-c++src\t0\n"
"*.cr\tCrystal\ttext/x-crystal\t0\n"
"*.crw\tCamera Image File Format\timage/x-canon-crw\t0\n"
"*.crx\tChrome Extension Package\tapplication/x-chrome-package\t0\n"
"*.cs\tC# source code\ttext/x-csharp\t0\n"
"*.cshtml\tHTML+Razor\ttext/html\t0\n"
"*.cson\tCSON\ttext/x-coffeescript\t0\n"
"*.csr\tPKCS10\tapplication/pkcs10\t0\n"
"*.css\tCascading Style Sheet\ttext/css\t0\n"
"*.csv\tComma Separated Values\ttext/csv\t0\n"
"*.csvs\tCSV Schema\ttext/csv-schema\t0\n"
"*.cu\tCuda\ttext/x-c++src\t0\n"
"*.cur\tMicrosoft Windows Cursor\timage/x-win-bitmap\t0\n"
"*.cwl\tCommon Workflow Language\ttext/x-yaml\t0\n"
"*.cy\tCycript\ttext/javascript\t0\n"
"*.d\tD source code\ttext/x-d\t0\n"
"*.dae\tCOLLADA\ttext/xml\t0\n"
"*.dart\tDart\tapplication/dart\t0\n"
"*.dat\tMapInfo Data File (DAT)\tapplication/dbase\t0\n"
"*.db\tSQLite Database File Format\tapplication/x-sqlite3\t0\n"
"*.dbf\tdBASE Table File Format (DBF)\tapplication/x-dbf\t0\n"
"*.dcm\tDigital Imaging and Communications in Medicine File Format\tapplication/dicom\t0\n"
"*.dcr\tShockwave (Director)\tapplication/x-director\t0\n"
"*.dcx\tMultipage Zsoft Paintbrush Bitmap Graphics\timage/x-dcx\t0\n"
"*.deb\tDeb\tapplication/vnd.debian.binary-package\t0\n"
"*.der\tDER encoded certificate\tapplication/x-x509-ca-cert\t0\n"
"*.dex\tDalvik Executable Format\tapplication/x-dex\t0\n"
"*.dgc\tDGCA\tapplication/x-dgc-compressed\t0\n"
"*.diff\tDiff\ttext/x-diff\t0\n"
"*.dir\tShockwave Movie\tapplication/x-director\t0\n"
"*.dita\tDITA Topic\tapplication/dita+xml;format=topic\t0\n"
"*.ditamap\tDITA Map\tapplication/dita+xml;format=map\t0\n"
"*.ditaval\tDITA Conditional Processing Profile\tapplication/dita+xml;format=val\t0\n"
"*.diz\tFILE ID.DIZ\ttext/plain\t0\n"
"*.djv\tSecure DjVU\timage/vnd.djvu\t0\n"
"*.djvu\tDjVu\timage/vnd.djvu\t0\n"
"*.dll\tWindows Portable Executable\tapplication/octet-stream\t0\n"
"*.dls\tDownloadable Sounds Audio\taudio/dls\t0\n"
"*.dmg\tApple Disk Image\tapplication/x-apple-diskimage\t0\n"
"*.dng\tAdobe Digital Negative\timage/x-raw-adobe\t0\n"
"*.doc\tMicrosoft Word\tapplication/msword\t0\n"
"*.dockerfile\tDockerfile\ttext/x-dockerfile\t0\n"
"*.docm\tOffice Open XML Document (macro-enabled)\tapplication/vnd.ms-word.document.macroenabled.12\t0\n"
"*.docx\tOOXML Format Family -- ISO/IEC 29500 and ECMA 376\tapplication/vnd.openxmlformats-officedocument.wordprocessingml.document\t0\n"
"*.dot\tMicrosoft Word Document Template (Password Protected) 97-2003\tapplication/msword;version=\"97-2003\"\t0\n"
"*.dotm\tOffice Open XML Document Template (macro-enabled)\tapplication/vnd.ms-word.template.macroenabled.12\t0\n"
"*.dotx\tOffice Open XML Document Template\tapplication/vnd.openxmlformats-officedocument.wordprocessingml.template\t0\n"
"*.dpx\tDigital Moving-Picture Exchange (DPX), Version 2.0\timage/x-dpx\t0\n"
"*.drc\tOgg Packaged Dirac Video\tvideo/x-dirac\t0\n"
"*.druby\tMirah\ttext/x-ruby\t0\n"
"*.dtd\tXML Document Type Definition (DTD)\tapplication/xml-dtd\t0\n"
"*.dts\tDTS Coherent Acoustics (DCA) Audio\taudio/vnd.dts\t0\n"
"*.dv\tDigital Video\tvideo/dv\t0\n"
"*.dvi\tDVI (Device Independent File Format)\tapplication/x-dvi\t0\n"
"*.dwf\tAutoCAD Design Web Format 6.0\tapplication/dwf;version=\"6.0\"\t0\n"
"*.dwfx\tAutoCAD Design Web Format\tmodel/vnd.dwfx+xps\t0\n"
"*.dwg\tAutoCad Drawing\timage/vnd.dwg\t0\n"
"*.dwl\tAutoCAD Database File Locking Information\tapplication/octet-stream\t0\n"
"*.dx\tDEC Data Exchange File\tapplication/dec-dx.\t0\n"
"*.dxb\tAutoCAD DXF simplified Binary\timage/vnd.dxb\t0\n"
"*.dxf\tAutoCAD DXF\timage/vnd.dxf\t0\n"
"*.dxr\tPlay SID Audio 1\taudio/prs.sid;version=\"1\"\t0\n"
"*.dylan\tDylan\ttext/x-dylan\t0\n"
"*.e\tEiffel source code\ttext/x-eiffel\t0\n"
"*.eb\tEasybuild\ttext/x-python\t0\n"
"*.ebnf\tEBNF\ttext/x-ebnf\t0\n"
"*.ebuild\tGentoo Ebuild\ttext/x-sh\t0\n"
"*.ecl\tECL\ttext/x-ecl\t0\n"
"*.eclass\tGentoo Eclass\ttext/x-sh\t0\n"
"*.ecr\tHTML+ECR\ttext/html\t0\n"
"*.edc\tEdje Data Collection\tapplication/json\t0\n"
"*.edn\tedn\ttext/x-clojure\t0\n"
"*.eex\tHTML+EEX\ttext/html\t0\n"
"*.el\tEmacs Lisp source code\ttext/x-emacs-lisp\t0\n"
"*.elc\tEmacs Lisp bytecode\tapplication/x-elc\t0\n"
"*.elm\tElm\ttext/x-elm\t0\n"
"*.em\tEmberScript\ttext/x-coffeescript\t0\n"
"*.emf\tEnhanced Metafile\timage/emf\t0\n"
"*.eml\tInternet e-mail message format\tmessage/rfc822\t0\n"
"*.enr\tEndNote Import File\tapplication/x-endnote-refer\t0\n"
"*.ens\tEndNote Style File\tapplication/x-endnote-style\t0\n"
"*.enz\tEndNote Connection File\tapplication/x-endnote-connect\t0\n"
"*.eot\tEmbedded OpenType\tapplication/vnd.ms-fontobject\t0\n"
"*.epj\tEcere Projects\tapplication/json\t0\n"
"*.eps\tEncapsulated PostScript (EPS) File Format, Version 3.x\tapplication/postscript\t0\n"
"*.epub\tElectronic Publication\tapplication/epub+zip\t0\n"
"*.eq\tEQ\ttext/x-csharp\t0\n"
"*.erb\tHTML+ERB\tapplication/x-erb\t0\n"
"*.erf\tEpson raw image\timage/x-raw-epson\t0\n"
"*.erl\tErlang source code\ttext/x-erlang\t0\n"
"*.es\tECMAScript\tapplication/ecmascript\t0\n"
"*.exe\tDOS/Windows executable (EXE)\tapplication/x-dosexec\t0\n"
"*.exp\tExpect Script\ttext/x-expect\t0\n"
"*.exr\tOpenEXR 2\timage/x-exr;version=\"2\"\t0\n"
"*.f\tFortran source code\ttext/x-fortran\t0\n"
"*.f4a\tMPEG-4 Media File\taudio/mp4\t0\n"
"*.f4m\tF4M\tapplication/f4m\t0\n"
"*.f90\tFortran\ttext/x-fortran\t0\n"
"*.factor\tFactor\ttext/x-factor\t0\n"
"*.fb2\tFictionBook document\tapplication/x-fictionbook+xml\t0\n"
"*.fdf\tForms Data Format\tapplication/vnd.fdf\t0\n"
"*.fff\tImacon raw image\timage/x-raw-imacon\t0\n"
"*.fh\tFreeHand image\timage/x-freehand\t0\n"
"*.fig\tMatlab figure\tapplication/x-matlab-data\t0\n"
"*.fits\tFlexible Image Transport System\timage/fits\t0\n"
"*.flac\tFLAC (Free Lossless Audio Codec), Version 1.1.2\taudio/flac\t0\n"
"*.flif\tFree Lossless Image Format (FLIF)\timage/flif\t0\n"
"*.flv\tFLV\tvideo/x-flv\t0\n"
"*.fm\tFrameMaker\tapplication/vnd.framemaker\t0\n"
"*.fmz\tform*Z Project File\tapplication/octet-stream\t0\n"
"*.folio\tFolio\tapplication/vnd.adobe.folio+zip\t0\n"
"*.fp7\tFileMaker Pro 7\tapplication/x-filemaker\t0\n"
"*.fpx\tFlashPix\timage/vnd.fpx\t0\n"
"*.fref\tFreenet node reference\ttext/plain\t0\n"
"*.fs\tF#\ttext/x-fsharp\t0\n"
"*.fth\tForth\ttext/x-forth\t0\n"
"*.g3\tCCITT Group 3\timage/g3fax\t0\n"
"*.gbr\tGerber Format\tapplication/vnd.gerber\t0\n"
"*.gca\tGCA\tapplication/x-gca-compressed\t0\n"
"*.geo\tGeoGebra 1.0\tapplication/vnd.geogebra.file;version=\"1.0\"\t0\n"
"*.gf\tGrammatical Framework\ttext/x-haskell\t0\n"
"*.ggb\tGgb\tapplication/vnd.geogebra.file\t0\n"
"*.gif\tGraphics Interchange Format\timage/gif\t0\n"
"*.gitconfig\tGit Config\ttext/x-properties\t0\n"
"*.gitignore\tIgnore List\ttext/x-sh\t0\n"
"*.glf\tGlyph\ttext/x-tcl\t0\n"
"*.gml\tGeography Markup Language\tapplication/gml+xml\t0\n"
"*.gn\tGN\ttext/x-python\t0\n"
"*.gnumeric\tGnumeric\tapplication/x-gnumeric\t0\n"
"*.go\tGo source code\ttext/x-go\t0\n"
"*.grb\tGeneral Regularly-distributed Information in Binary form\tapplication/x-grib\t0\n"
"*.groovy\tGroovy source code\ttext/x-groovy\t0\n"
"*.gsp\tGroovy Server Pages\tapplication/x-jsp\t0\n"
"*.gtar\tGNU tar Compressed File Archive (GNU Tape Archive)\tapplication/x-gtar\t0\n"
"*.gz\tGzip Compressed Archive\tapplication/gzip\t0\n"
"*.h\tC source code header\ttext/x-chdr\t0\n"
"*.haml\tHAML source code\ttext/x-haml\t0\n"
"*.hcl\tHCL\ttext/x-ruby\t0\n"
"*.hdf\tHierarchical Data Format File\tapplication/x-hdf\t0\n"
"*.hdp\tHD Photo, Version 1.0 (Windows Media Photo)\timage/vnd.ms-photo\t0\n"
"*.hdr\tRadiance HDR\timage/vnd.radiance\t0\n"
"*.hh\tHack\tapplication/x-httpd-php\t0\n"
"*.hpgl\tHewlett Packard Graphics Language\tapplication/vnd.hp-hpgl\t0\n"
"*.hpp\tC++ source code header\ttext/x-c++hdr\t0\n"
"*.hqx\tBinHex\tapplication/mac-binhex\t0\n"
"*.hs\tHaskell source code\ttext/x-haskell\t0\n"
"*.htm\tHypertext Markup Language\ttext/html\t0\n"
"*.html\tHyperText Markup Language\ttext/html\t0\n"
"*.http\tHTTP\tmessage/http\t0\n"
"*.hx\tHaxe source code\ttext/x-haxe\t0\n"
"*.ibooks\tApple iBook format\tapplication/x-ibooks+zip\t0\n"
"*.ico\tICO\timage/vnd.microsoft.icon\t0\n"
"*.ics\tInternet Calendar and Scheduling format\ttext/calendar\t0\n"
"*.idl\tInteface Definition Language\ttext/x-idl\t0\n"
"*.idml\tIDML\tapplication/vnd.adobe.indesign-idml-package\t0\n"
"*.iges\tInitial Graphics Exchange Specification (IGES) 5.x\tmodel/iges;version=\"5.x\"\t0\n"
"*.igs\tInitial Graphics Exchange Specification Format\tmodel/iges\t0\n"
"*.iiq\tPhase One raw image\timage/x-raw-phaseone\t0\n"
"*.ind\tAdobe InDesign Document Generic\tapplication/octet-stream;version=\"generic\"\t0\n"
"*.indd\tAdobe InDesign document\tapplication/x-adobe-indesign\t0\n"
"*.inf\tWindows Setup File\tapplication/inf\t0\n"
"*.ini\tConfiguration file\ttext/x-ini\t0\n"
"*.inx\tAdobe InDesign Interchange format\tapplication/x-adobe-indesign-interchange\t0\n"
"*.ipa\tApple iOS IPA AppStore file\tapplication/x-itunes-ipa\t0\n"
"*.ipynb\tJupyter Notebook\tapplication/json\t0\n"
"*.irclog\tIRC log\ttext/mirc\t0\n"
"*.iso\tISO Disk Image File Format\tapplication/x-iso9660-image\t0\n"
"*.itk\tTcl script\tapplication/x-tcl\t0\n"
"*.j2c\tJPEG 2000 Codestream\timage/x-jp2-codestream\t0\n"
"*.jade\tPug\ttext/x-pug\t0\n"
"*.jar\tJava Archive\tapplication/java-archive\t0\n"
"*.java\tJava source code\ttext/x-java\t0\n"
"*.jinja\tHTML+Django\ttext/x-django\t0\n"
"*.jl\tJulia\ttext/x-julia\t0\n"
"*.jls\tJPEG-LS\timage/jls\t0\n"
"*.jng\tJPEG Network Graphics\timage/x-jng\t0\n"
"*.jnilib\tJava Native Library for OSX\tapplication/x-java-jnilib\t0\n"
"*.jp2\tJPEG 2000\timage/jpx\t0\n"
"*.jpe\tRaw JPEG Stream\timage/jpeg\t0\n"
"*.jpf\tJPX (JPEG 2000 part 2)\timage/jpx\t0\n"
"*.jpg\tJoint Photographic Experts Group\timage/jpeg\t0\n"
"*.jpm\tJPEG 2000 Part 6 (JPM)\timage/jpm\t0\n"
"*.jq\tJSONiq\tapplication/json\t0\n"
"*.js\tJavaScript Source Code\tapplication/javascript\t0\n"
"*.json\tJSON (JavaScript Object Notation)\tapplication/json\t0\n"
"*.json-patch\tJSON Patch\tapplication/json-patch+json\t0\n"
"*.json5\tJSON5\tapplication/json\t0\n"
"*.jsonld\tJSON-LD\tapplication/ld+json\t0\n"
"*.jsp\tJava Server Pages\tapplication/x-jsp\t0\n"
"*.jsx\tJSX\ttext/jsx\t0\n"
"*.jxr\tJPEG Extended Range\timage/jxr\t0\n"
"*.k25\tKodak raw image\timage/x-raw-kodak\t0\n"
"*.kicad_pcb\tKiCad Layout\ttext/x-common-lisp\t0\n"
"*.kid\tGenshi\ttext/xml\t0\n"
"*.kil\tKIllustrator File\tapplication/x-killustrator\t0\n"
"*.kit\tKit\ttext/html\t0\n"
"*.kml\tKeyhole Markup Language\tapplication/vnd.google-earth.kml+xml\t0\n"
"*.kmz\tKeyhole Markup Language (Container)\tapplication/vnd.google-earth.kmz\t0\n"
"*.kpr\tKPresenter File\tapplication/x-kpresenter\t0\n"
"*.kra\tKrita Document Format\tapplication/x-krita\t0\n"
"*.ksp\tKSpread File\tapplication/x-kspread\t0\n"
"*.kt\tKotlin\ttext/x-kotlin\t0\n"
"*.ktx\tKhronos Texture File\timage/ktx\t0\n"
"*.kwd\tKWord File\tapplication/x-kword\t0\n"
"*.l\tLex/Flex source code\ttext/x-lex\t0\n"
"*.latex\tLaTeX Source Document\tapplication/x-latex\t0\n"
"*.latte\tLatte\ttext/x-smarty\t0\n"
"*.less\tLESS source code\ttext/x-less\t0\n"
"*.lfe\tLFE\ttext/x-common-lisp\t0\n"
"*.lha\tLHA\tapplication/x-lzh-compressed\t0\n"
"*.lhs\tLiterate Haskell\ttext/x-literate-haskell\t0\n"
"*.lisp\tCommon Lisp\ttext/x-common-lisp\t0\n"
"*.log\tapplication log\ttext/x-log\t0\n"
"*.lookml\tLookML\ttext/x-yaml\t0\n"
"*.ls\tLiveScript\ttext/x-livescript\t0\n"
"*.lua\tLua source code\ttext/x-lua\t0\n"
"*.lvproj\tLabVIEW\ttext/xml\t0\n"
"*.lwp\tLotus Word Pro\tapplication/vnd.lotus-wordpro\t0\n"
"*.lz\tLzip\tapplication/x-lzip\t0\n"
"*.lzma\tLZMA Alone\tapplication/x-lzma\t0\n"
"*.m\tObjective-C source code\ttext/x-objcsrc\t0\n"
"*.m3\tModula source code\ttext/x-modula\t0\n"
"*.m3u\tMP3 Playlist File\taudio/x-mpegurl\t0\n"
"*.maff\tMAFF\tapplication/x-maff\t0\n"
"*.mak\tMakefile\ttext/x-cmake\t0\n"
"*.marko\tMarko\ttext/html\t0\n"
"*.mas\tLotus Freelance Smartmaster Graphics\tapplication/vnd.lotus-freelance\t0\n"
"*.mat\tMAT-File Level 5 File Format\tapplication/matlab-mat\t0\n"
"*.mathematica\tMathematica\ttext/x-mathematica\t0\n"
"*.matlab\tMATLAB\ttext/x-octave\t0\n"
"*.maxpat\tMax\tapplication/json\t0\n"
"*.mbox\tMBOX Email Format\tapplication/mbox\t0\n"
"*.mbx\tMbox\tapplication/mbox\t0\n"
"*.mcw\tMicrosoft Word for Macintosh Document 5.0\tapplication/msword;version=\"5.0\"\t0\n"
"*.md\tMarkdown\ttext/markdown\t0\n"
"*.mdi\tMicrosoft Document Imaging\timage/vnd.ms-modi\t0\n"
"*.mef\tMamiya raw image\timage/x-raw-mamiya\t0\n"
"*.metal\tMetal\ttext/x-c++src\t0\n"
"*.mht\tMicrosoft Web Archive\tmultipart/related\t0\n"
"*.mid\tMusical Instrument Digital Interface\taudio/midi\t0\n"
"*.mif\tFrameMaker Interchange Format\tapplication/x-mif\t0\n"
"*.mix\tMIX (PhotoDraw)\timage/vnd.mix\t0\n"
"*.mj2\tMJ2 (Motion JPEG 2000)\tvideo/mj2\t0\n"
"*.mkv\tMatroska Multimedia Container\tvideo/x-matroska\t0\n"
"*.ml\tOCaml\ttext/x-ocaml\t0\n"
"*.mlp\tDolby MLP Lossless Audio\taudio/vnd.dolby.mlp\t0\n"
"*.mm\tMm\tapplication/x-freemind\t0\n"
"*.mmp\tMindManager\tapplication/vnd.mindjet.mindmanager\t0\n"
"*.mmr\tXerox EDMICS-MMR\timage/vnd.fujixerox.edmics-mmr\t0\n"
"*.mng\tMultiple-image Network Graphics\tvideo/x-mng\t0\n"
"*.mo\tModelica\ttext/x-modelica\t0\n"
"*.mobi\tMobipocket File Format\tapplication/x-mobipocket-ebook\t0\n"
"*.mod\tCATIA Model 4\tapplication/octet-stream;version=\"4\"\t0\n"
"*.mol\tMOL\tchemical/x-mdl-molfile\t0\n"
"*.mos\tLeaf raw image\timage/x-raw-leaf\t0\n"
"*.mov\tQuickTime File Format\tvideo/quicktime\t0\n"
"*.mp1\tMPEG Audio Layer I\taudio/mpeg\t0\n"
"*.mp2\tMPEG Audio Stream, Layer II\taudio/mpeg\t0\n"
"*.mp3\tMP3 File Format\taudio/mpeg\t0\n"
"*.mp4\tMPEG-4 File Format, Version 2\tvideo/mp4\t0\n"
"*.mpeg\tMPEG Movie Clip\tvideo/mpeg\t0\n"
"*.mpg\tMPEG-1\tvideo/mpeg\t0\n"
"*.mpga\tMPEG-1 Audio Layer 3\taudio/mpeg\t0\n"
"*.mpp\tMicrosoft Project 2010\tapplication/vnd.ms-project;version=\"2010\"\t0\n"
"*.mpx\tMicrosoft Project Export File 4.0\tapplication/x-project;version=\"4.0\"\t0\n"
"*.mrc\tMARC\tapplication/marc\t0\n"
"*.mrw\tMinolta raw image\timage/x-raw-minolta\t0\n"
"*.msg\tMicrosoft Outlook Message\tapplication/vnd.ms-outlook\t0\n"
"*.msi\tMicrosoft Windows Installer\tapplication/x-msi\t0\n"
"*.mso\tActiveMime\tapplication/x-mso\t0\n"
"*.mtml\tMTML\ttext/html\t0\n"
"*.muf\tMUF\ttext/x-forth\t0\n"
"*.mumps\tM\ttext/x-mumps\t0\n"
"*.mxf\tMaterial Exchange Format (MXF)\tapplication/mxf\t0\n"
"*.mxl\tCompressed Music XML\tapplication/vnd.recordare.musicxml\t0\n"
"*.mxmf\tMobile eXtensible Music Format\taudio/mobile-xmf\t0\n"
"*.n3\tNotation3\ttext/n3\t0\n"
"*.nap\tNAPLPS\timage/naplps\t0\n"
"*.nb\tMathematica Notebook\tapplication/mathematica\t0\n"
"*.nc\tNetCDF-3 (Network Common Data Form, version 3)\tapplication/x-netcdf\t0\n"
"*.nef\tNikon raw image\timage/x-raw-nikon\t0\n"
"*.nfo\tNFO\ttext/x-nfo\t0\n"
"*.nginxconf\tNginx\ttext/x-nginx-conf\t0\n"
"*.nif\tNotation Interchange File Format\tapplication/vnd.music-niff\t0\n"
"*.nl\tNewLisp\ttext/x-common-lisp\t0\n"
"*.nlogo\tNetLogo\ttext/x-common-lisp\t0\n"
"*.ns2\tLotus Notes Database 2\tapplication/vnd.lotus-notes;version=\"2\"\t0\n"
"*.ns3\tLotus Notes Database 3\tapplication/vnd.lotus-notes;version=\"3\"\t0\n"
"*.ns4\tLotus Notes Database 4\tapplication/vnd.lotus-notes;version=\"4\"\t0\n"
"*.nsf\tNotes Storage Facility\tapplication/vnd.lotus-notes\t0\n"
"*.nsi\tNSIS\ttext/x-nsis\t0\n"
"*.ntf\tNational Imagery Transmission Format\tapplication/vnd.nitf\t0\n"
"*.nu\tNu\ttext/x-scheme\t0\n"
"*.numpy\tNumPy\ttext/x-python\t0\n"
"*.nut\tSquirrel\ttext/x-c++src\t0\n"
"*.ocaml\tOcaml source code\ttext/x-ocaml\t0\n"
"*.odb\tOpenDocument Database Front End Document Format (ODB), Version 1.2,  ISO 26300-1:2015\tapplication/vnd.oasis.opendocument.database\t0\n"
"*.odc\tOpenDocument v1.0: Chart document\tapplication/vnd.oasis.opendocument.chart\t0\n"
"*.odf\tOpenDocument v1.0: Formula document\tapplication/vnd.oasis.opendocument.formula\t0\n"
"*.odft\tOpenDocument v1.0: Formula document used as template\tapplication/vnd.oasis.opendocument.formula-template\t0\n"
"*.odg\tOpenDocument Drawing\tapplication/vnd.oasis.opendocument.graphics\t0\n"
"*.odi\tOpenDocument v1.0: Image document\tapplication/vnd.oasis.opendocument.image\t0\n"
"*.odm\tOpenDocument\tapplication/vnd.oasis.opendocument.text-master\t0\n"
"*.odp\tOpenDocument Presentation\tapplication/vnd.oasis.opendocument.presentation\t0\n"
"*.ods\tOpenDocument Spreadsheet\tapplication/vnd.oasis.opendocument.spreadsheet\t0\n"
"*.odt\tOpenDocument Text\tapplication/vnd.oasis.opendocument.text\t0\n"
"*.ofx\tOpen Financial Exchange 2.1.1\tapplication/x-ofx;version=\"2.1.1\"\t0\n"
"*.oga\tOgg Vorbis Audio\taudio/ogg\t0\n"
"*.ogg\tOgg Vorbis Codec Compressed Multimedia File\taudio/ogg\t0\n"
"*.ogm\tOgg Packaged OGM Video\tvideo/x-ogm\t0\n"
"*.ogv\tOgg Vorbis Video\tvideo/ogg\t0\n"
"*.ogx\tOgg Skeleton\tapplication/ogg\t0\n"
"*.one\tMicrosoft OneNote\tapplication/msonenote\t0\n"
"*.opf\tDTB (Digital Talking Book), 2005\tapplication/x-dtbook+xml\t0\n"
"*.opus\tOgg Opus Codec Compressed WAV File\taudio/opus\t0\n"
"*.ora\tOpenRaster\timage/openraster\t0\n"
"*.orf\tOlympus raw image\timage/x-raw-olympus\t0\n"
"*.otc\tOpenDocument v1.0: Chart document used as template\tapplication/vnd.oasis.opendocument.chart-template\t0\n"
"*.otf\tOpenType Font\tapplication/x-font-otf\t0\n"
"*.otg\tOpenDocument v1.0: Graphics document used as template\tapplication/vnd.oasis.opendocument.graphics-template\t0\n"
"*.oth\tOpenDocument v1.0: Text document used as template for HTML documents\tapplication/vnd.oasis.opendocument.text-web\t0\n"
"*.oti\tOpenDocument v1.0: Image document used as template\tapplication/vnd.oasis.opendocument.image-template\t0\n"
"*.otm\tOpenDocument v1.0: Global Text document\tapplication/vnd.oasis.opendocument.text-master\t0\n"
"*.otp\tOpenDocument v1.0: Presentation document used as template\tapplication/vnd.oasis.opendocument.presentation-template\t0\n"
"*.ots\tOpenDocument v1.0: Spreadsheet document used as template\tapplication/vnd.oasis.opendocument.spreadsheet-template\t0\n"
"*.ott\tOpenDocument v1.0: Text document used as template\tapplication/vnd.oasis.opendocument.text-template\t0\n"
"*.oxps\tOpenXPS\tapplication/oxps\t0\n"
"*.oz\tOz\ttext/x-oz\t0\n"
"*.p\tPascal source code\ttext/x-pascal\t0\n"
"*.p65\tPagemaker Document (Generic)\tapplication/vnd.pagemaker\t0\n"
"*.pab\tPersonal Folder File\tapplication/vnd.ms-outlook\t0\n"
"*.pack\tPackage (Web)\tapplication/package\t0\n"
"*.pam\tPortable Arbitrary Map\timage/x-portable-arbitrarymap\t0\n"
"*.pas\tPascal\ttext/x-pascal\t0\n"
"*.pbm\tNetpbm formats\timage/x-portable-bitmap\t0\n"
"*.pcap\tTCPDump pcap packet capture\tapplication/vnd.tcpdump.pcap\t0\n"
"*.pcapng\tpcap Next Generation Packet Capture\tapplication/vnd.tcpdump.pcap\t0\n"
"*.pcl\tPCL\tapplication/vnd.hp-pcl\t0\n"
"*.pct\tMacintosh PICT Image 2.0\timage/x-pict;version=\"2.0\"\t0\n"
"*.pcx\tPCX\timage/vnd.zbrush.pcx\t0\n"
"*.pdb\tPalm OS Database\tapplication/vnd.palm\t0\n"
"*.pdf\tPortable Document Format\tapplication/pdf\t0\n"
"*.pfm\tPrinter Font Metric\tapplication/x-font-printer-metric\t0\n"
"*.pfr\tPFR\tapplication/font-tdpfr\t0\n"
"*.pgm\tPortable Graymap Graphic\timage/x-portable-graymap\t0\n"
"*.pgn\tPGN\tapplication/x-chess-pgn\t0\n"
"*.pgsql\tPLpgSQL\ttext/x-sql\t0\n"
"*.php\tPHP script\ttext/x-php\t0\n"
"*.phtml\tHTML+PHP\tapplication/x-httpd-php\t0\n"
"*.pic\tApple Macintosh QuickDraw/PICT Format\timage/x-pict\t0\n"
"*.pict\tPICT\timage/x-pict\t0\n"
"*.pkpass\tPKPass\tapplication/vnd.apple.pkpass\t0\n"
"*.pl\tPerl script\ttext/x-perl\t0\n"
"*.pls\tPLSQL\ttext/x-plsql\t0\n"
"*.png\tPortable Network Graphics\timage/png\t0\n"
"*.pnm\tPortable Any Map\timage/x-portable-anymap\t0\n"
"*.pod\tPod\ttext/x-perl\t1\n"
"*.por\tSPSS Portable File, ASCII encoding\tapplication/x-spss-por\t0\n"
"*.potm\tMicrosoft PowerPoint Macro-Enabled Template 2007\tapplication/vnd.ms-powerpoint.template.macroenabled.12;version=\"2007\"\t0\n"
"*.potx\tOffice Open XML Presentation Template\tapplication/vnd.openxmlformats-officedocument.presentationml.template\t0\n"
"*.pp\tPuppet\ttext/x-puppet\t0\n"
"*.ppam\tOffice Open XML Presentation Add-in (macro-enabled)\tapplication/vnd.ms-powerpoint.addin.macroenabled.12\t0\n"
"*.ppm\tPortable Pixel Map - ASCII\timage/x-portable-pixmap\t0\n"
"*.pps\tMicrosoft Powerpoint Presentation Show 97-2003\tapplication/vnd.ms-powerpoint;version=\"97-2003\"\t0\n"
"*.ppsm\tOffice Open XML Presentation Slideshow (macro-enabled)\tapplication/vnd.ms-powerpoint.slideshow.macroenabled.12\t0\n"
"*.ppsx\tOffice Open XML Presentation Slideshow\tapplication/vnd.openxmlformats-officedocument.presentationml.slideshow\t0\n"
"*.ppt\tMicrosoft Powerpoint Presentation\tapplication/vnd.ms-powerpoint\t0\n"
"*.pptm\tOffice Open XML Presentation (macro-enabled)\tapplication/vnd.ms-powerpoint.presentation.macroenabled.12\t0\n"
"*.pptx\tOffice Open XML Presentation\tapplication/vnd.openxmlformats-officedocument.presentationml.presentation\t0\n"
"*.prc\tPRC (Palm OS)\tapplication/vnd.palm\t0\n"
"*.pro\tProlog source code\ttext/x-prolog\t0\n"
"*.project\tCATIA Project 4\tapplication/octet-stream;version=\"4\"\t0\n"
"*.properties\tJava Properties\ttext/properties\t0\n"
"*.proto\tProtocol Buffer\ttext/x-protobuf\t0\n"
"*.ps\tPostScript\tapplication/postscript\t0\n"
"*.ps1\tPowerShell\tapplication/x-powershell\t0\n"
"*.psb\tAdobe Photoshop Large Document Format\timage/vnd.adobe.photoshop\t0\n"
"*.psd\tAdobe Photoshop\timage/vnd.adobe.photoshop\t0\n"
"*.psid\tPlay SID Audio 2\taudio/prs.sid;version=\"2\"\t0\n"
"*.pst\tOutlook Personal Folders File Format\tapplication/vnd.ms-outlook-pst\t0\n"
"*.ptx\tPentax raw image\timage/x-raw-pentax\t0\n"
"*.purs\tPureScript\ttext/x-haskell\t0\n"
"*.pxn\tLogitech raw image\timage/x-raw-logitech\t0\n"
"*.py\tPython script\ttext/x-python\t0\n"
"*.pyx\tCython\ttext/x-cython\t0\n"
"*.qcd\tQuark Xpress Data File\tapplication/vnd.quark.quarkxpress\t0\n"
"*.qcp\tQCP Audio File Format\taudio/qcelp\t0\n"
"*.qif\tQuicken Interchange Format\tapplication/qif\t0\n"
"*.qxp\tQuarkXPress\tapplication/vnd.quark.quarkxpress\t0\n"
"*.qxp report\tQuark Xpress Report File\tapplication/vnd.quark.quarkxpress\t0\n"
"*.r\tR source code\ttext/x-rsrc\t0\n"
"*.r3d\tRed raw image\timage/x-raw-red\t0\n"
"*.ra\tRealAudio\taudio/vnd.rn-realaudio\t0\n"
"*.raf\tFuji raw image\timage/x-raw-fuji\t0\n"
"*.ram\tRealAudio Metafile\taudio/vnd.rn-realaudio\t0\n"
"*.raml\tRAML\ttext/x-yaml\t0\n"
"*.rar\tRAR\tapplication/vnd.rar\t0\n"
"*.rar \tRAR Archive File Format Family\tapplication/vnd.rar\t0\n"
"*.ras\tSun Raster Image\timage/x-sun-raster\t0\n"
"*.raw\tPanasonic raw image\timage/x-raw-panasonic\t0\n"
"*.rb\tRuby source code\ttext/x-ruby\t0\n"
"*.rdf\tRDF\tapplication/rdf+xml\t0\n"
"*.re\tReason\ttext/x-rustsrc\t0\n"
"*.reg\tWindows Registry Entries\ttext/x-properties\t0\n"
"*.rest\treStructuredText source code\ttext/x-rst\t0\n"
"*.rexx\tRexx source code\ttext/x-rexx\t0\n"
"*.rf64\tBroadcast WAVE 0 WAVEFORMATEXTENSIBLE Encoding\taudio/x-wav;version=\"0waveformatextensibleencoding\"\t0\n"
"*.rfa\tRevit Family File\tapplication/octet-stream\t0\n"
"*.rft\tRevit Family Template\tapplication/octet-stream\t0\n"
"*.rg\tRouge\ttext/x-clojure\t0\n"
"*.rgb\tSilicon Graphics RGB Bitmap\timage/x-rgb\t0\n"
"*.rhtml\tRHTML\tapplication/x-erb\t0\n"
"*.rlc\tXerox EDMICS-RLC\timage/vnd.fujixerox.edmics-rlc\t0\n"
"*.rm\tRealAudio, Version 10\tapplication/vnd.rn-realmedia\t0\n"
"*.rmd\tRMarkdown\ttext/x-gfm\t1\n"
"*.rmi\tRIFF-based MIDI File Format\taudio/mid\t0\n"
"*.rmp\tRealMedia Player Plug-in\taudio/x-pn-realaudio-plugin\t0\n"
"*.roff\tRoff\ttext/troff\t0\n"
"*.rpm\tRedHat Package Manager\tapplication/x-rpm\t0\n"
"*.rs\tRust\ttext/x-rustsrc\t0\n"
"*.rss\tRSS\tapplication/rss+xml\t0\n"
"*.rst\treStructuredText\ttext/x-rst\t1\n"
"*.rte\tRevit Template\tapplication/octet-stream\t0\n"
"*.rtf\tRich Text Format File\tapplication/rtf\t0\n"
"*.rv\tReal Video\tvideo/vnd.rn-realvideo\t0\n"
"*.rvg\tRevit External Group\tapplication/octet-stream\t0\n"
"*.rvt\tRevit Project\tapplication/octet-stream\t0\n"
"*.rws\tRevit Workspace\tapplication/octet-stream\t0\n"
"*.rwz\tRawzor raw image\timage/x-raw-rawzor\t0\n"
"*.s\tAssembler source code\ttext/x-asm\t0\n"
"*.s7m\tSAS DMDB Data Mining Database File\tapplication/x-sas-dmdb\t0\n"
"*.sa7\tSAS Access Descriptor\tapplication/x-sas-access\t0\n"
"*.sage\tSage\ttext/x-python\t0\n"
"*.sam\tAMI Professional Document\tapplication/vnd.lotus-wordpro\t0\n"
"*.sas\tSAS Program\tapplication/x-sas\t0\n"
"*.sas7bbak\tSAS Backup\tapplication/x-sas-backup\t0\n"
"*.sass\tSass\ttext/x-sass\t0\n"
"*.sav\tSPSS System Data File Format Family (.sav)\tapplication/x-spss-sav\t0\n"
"*.sc7\tSAS Catalog\tapplication/x-sas-catalog\t0\n"
"*.scala\tScala source code\ttext/x-scala\t0\n"
"*.sch\tEagle\ttext/xml\t0\n"
"*.scm\tScheme source code\ttext/x-scheme\t0\n"
"*.scores\tXbill.scores\ttext/plain\t0\n"
"*.scss\tSCSS\ttext/x-scss\t0\n"
"*.sd7\tSAS Data Set\tapplication/x-sas-data\t0\n"
"*.sda\tSDA (StarOffice)\tapplication/vnd.stardivision.draw\t0\n"
"*.sdc\tSDC\tapplication/vnd.stardivision.calc\t0\n"
"*.sdn\tSteel Detailing Neutral Format\ttext/plain\t0\n"
"*.sdw\tStarOffice binary formats\tapplication/vnd.stardivision.writer\t0\n"
"*.sed\tSed code\ttext/x-sed\t0\n"
"*.sf7\tSAS FDB Consolidation Database File\tapplication/x-sas-fdb\t0\n"
"*.sfd\tSpline Font Database\tapplication/vnd.font-fontforge-sfd\t0\n"
"*.sgm\tStandard Generalized Markup Language\ttext/sgml\t0\n"
"*.sgml\tSGML\ttext/sgml\t0\n"
"*.sh\tUNIX/LINUX Shell Script\tapplication/x-sh\t0\n"
"*.sh-session\tShellSession\ttext/x-sh\t0\n"
"*.shar\tShell Archive Format\tapplication/x-shar\t0\n"
"*.shtml\tServer Side Includes\ttext/x-server-parsed-html\t0\n"
"*.si7\tSAS Data Set Index\tapplication/x-sas-data-index\t0\n"
"*.sid\tSID\taudio/prs.sid\t0\n"
"*.sit\tStuffIt\tapplication/x-stuffit\t0\n"
"*.sitx\tStuffIt X\tapplication/x-stuffitx\t0\n"
"*.skb\tSketchUp Document\tapplication/octet-stream\t0\n"
"*.skp\tSSEYO Koan File\tapplication/vnd.koan\t0\n"
"*.sla\tScribus\tapplication/vnd.scribus\t0\n"
"*.sld\tAutoCAD Slide\tapplication/sld\t0\n"
"*.sldm\tMicrosoft PowerPoint Macro-Enabled Slide 2007\tapplication/vnd.ms-powerpoint.slide.macroenabled.12;version=\"2007\"\t0\n"
"*.sldprt\tSolidWorks CAD program\tapplication/sldworks\t0\n"
"*.slim\tSlim\ttext/x-slim\t0\n"
"*.sls\tSaltStack\ttext/x-yaml\t0\n"
"*.sm7\tSAS MDDB Multi-Dimensional Database File\tapplication/x-sas-mddb\t0\n"
"*.smi\tSMIL Multimedia\tapplication/smil+xml\t0\n"
"*.smk\tSmacker\tvideo/vnd.radgamettools.smacker\t0\n"
"*.soy\tClosure Templates\ttext/x-soy\t0\n"
"*.sp7\tSAS Permanent Utility\tapplication/x-sas-putility\t0\n"
"*.sparql\tSPARQL\tapplication/sparql-query\t0\n"
"*.spec\tRPM Spec\ttext/x-rpm-spec\t0\n"
"*.spl\tMacromedia FutureSplash File\tapplication/x-futuresplash\t0\n"
"*.spx\tOgg Speex Audio Format\taudio/speex\t0\n"
"*.sql\tSQL code\ttext/x-sql\t0\n"
"*.sr7\tSAS Item Store (ItemStor) File\tapplication/x-sas-itemstor\t0\n"
"*.srl\tSereal binary serialization format\tapplication/sereal\t0\n"
"*.srt\tSRecode Template\ttext/x-common-lisp\t0\n"
"*.ss7\tSAS Stored Program (DATA Step)\tapplication/x-sas-program-data\t0\n"
"*.ssml\tSpeech Synthesis Markup Language\tapplication/ssml+xml\t0\n"
"*.st\tSmalltalk source code\ttext/x-stsrc\t0\n"
"*.st7\tSAS Audit\tapplication/x-sas-audit\t0\n"
"*.stw\tSTW\tapplication/vnd.sun.xml.writer.template\t0\n"
"*.stx\tSAS Transport File\tapplication/x-sas-transport\t0\n"
"*.su7\tSAS Utility\tapplication/x-sas-utility\t0\n"
"*.sublime-build\tJSON with Comments\ttext/javascript\t0\n"
"*.sv\tSystemVerilog\ttext/x-systemverilog\t0\n"
"*.sv7\tSAS Data Set View\tapplication/x-sas-view\t0\n"
"*.svf\tSimple Vector Format\timage/vnd.svf\t0\n"
"*.svg\tScalable Vector Graphics\timage/svg+xml\t0\n"
"*.svgz\tScalable Vector Graphics Compressed\timage/svg+xml\t0\n"
"*.swf\tSWF\tapplication/vnd.adobe.flash-movie\t0\n"
"*.swift\tSwift\ttext/x-swift\t0\n"
"*.sxc\tOpenOffice Calc 1.0\tapplication/vnd.sun.xml.calc;version=\"1.0\"\t0\n"
"*.sxd\tSXD\tapplication/vnd.sun.xml.draw\t0\n"
"*.sxi\tSXI\tapplication/vnd.sun.xml.impress\t0\n"
"*.sxw\tOpenOffice.org XML\tapplication/vnd.sun.xml.writer\t0\n"
"*.sz\tSnappy Framed\tapplication/x-snappy-framed\t0\n"
"*.t\tTADS\tapplication/x-tads\t0\n"
"*.tap\tTAP (Tencent)\timage/vnd.tencent.tap\t0\n"
"*.tar\tTape Archive\tapplication/x-tar\t0\n"
"*.tcl\tTcl\ttext/x-tcl\t0\n"
"*.tcsh\tTcsh\ttext/x-sh\t0\n"
"*.tex\tTeX Source\ttext/x-tex\t0\n"
"*.textile\tTextile\ttext/x-textile\t1\n"
"*.tfw\tESRI World File\ttext/plain\t0\n"
"*.tfx\tTagged Image File Format for Internet Fax (TIFF-FX)\timage/tiff\t0\n"
"*.thmx\tMicrosoft Office Theme\tapplication/vnd.ms-officetheme\t0\n"
"*.tif\tTagged Image File Format for Image Technology (TIFF/IT)\timage/tiff\t0\n"
"*.tif \tDigital Raster Graphic as TIFF\timage/tiff\t0\n"
"*.tiff\tTagged Image File Format\timage/tiff\t0\n"
"*.toml\tTOML\ttext/x-toml\t0\n"
"*.torrent\tTorrent file\tapplication/x-bittorrent\t0\n"
"*.tpl\tSmarty\ttext/x-smarty\t0\n"
"*.ts\tTypeScript\tapplication/typescript\t0\n"
"*.tsv\tTab-separated values\ttext/tab-separated-values\t0\n"
"*.tta\tTrue Audio 1\taudio/tta;version=\"1\"\t0\n"
"*.ttf\tTrueType Font\tapplication/x-font-ttf\t0\n"
"*.ttl\tTurtle\ttext/turtle\t0\n"
"*.twig\tTwig\ttext/x-twig\t0\n"
"*.txt\tPlain text\ttext/plain\t0\n"
"*.u3d\tUniversal 3D (U3D) format family. ECMA-363, Editions 1-4\tmodel/u3d\t0\n"
"*.uc\tUnrealScript\ttext/x-java\t0\n"
"*.ulx\tGlulx\tapplication/x-glulx\t0\n"
"*.uno\tUno\ttext/x-csharp\t0\n"
"*.upc\tUnified Parallel C\ttext/x-csrc\t0\n"
"*.url\tInternet Shortcut\tapplication/x-url\t0\n"
"*.v\tVerilog source code\ttext/x-verilog\t0\n"
"*.vb\tVisual Basic\ttext/x-vb\t0\n"
"*.vbs\tVBScript source code\ttext/x-vbscript\t0\n"
"*.vcd\tVirtual CD-ROM CD Image File\tapplication/x-cdlink\t0\n"
"*.vcf\tVCard\ttext/vcard\t0\n"
"*.vcs\tVCalendar format\ttext/x-vcalendar\t0\n"
"*.vdx\tMicrosoft Visio XML Drawing 2003-2010\tapplication/vnd.visio;version=\"2003-2010\"\t0\n"
"*.vhd\tVHDL source code\ttext/x-vhdl\t0\n"
"*.vhdl\tVHDL\ttext/x-vhdl\t0\n"
"*.viv\tVivoActive\tvideo/vnd-vivo\t0\n"
"*.vmdk\tVirtual Disk Format\tapplication/x-vmdk\t0\n"
"*.vmt\tValve Material Type\tapplication/vnd.valve.source.material\t0\n"
"*.volt\tVolt\ttext/x-d\t0\n"
"*.vot\tVOTable\tapplication/x-votable+xml\t0\n"
"*.vpb\tQuantel VPB image\timage/vpb\t0\n"
"*.vsd\tMicrosoft Visio Diagram\tapplication/vnd.visio\t0\n"
"*.vsdm\tOffice Open XML Visio Drawing (macro-enabled)\tapplication/vnd.ms-visio.drawing.macroenabled.12\t0\n"
"*.vsdx\tVisio VSDX Drawing File Format\tapplication/vnd.visio\t0\n"
"*.vssm\tOffice Open XML Visio Stencil (macro-enabled)\tapplication/vnd.ms-visio.stencil.macroenabled.12\t0\n"
"*.vssx\tOffice Open XML Visio Stencil (macro-free)\tapplication/vnd.ms-visio.stencil\t0\n"
"*.vstm\tOffice Open XML Visio Template (macro-enabled)\tapplication/vnd.ms-visio.template.macroenabled.12\t0\n"
"*.vstx\tOffice Open XML Visio Template (macro-free)\tapplication/vnd.ms-visio.template\t0\n"
"*.vtf\tValve Texture Format\timage/vnd.valve.source.texture\t0\n"
"*.vtt\tWeb Video Text Tracks Format\ttext/vtt\t0\n"
"*.vwx\tVectorworks 2015\tapplication/vnd.vectorworks;version=\"2015\"\t0\n"
"*.w50\tWordPerfect for MS-DOS Document 5.0\tapplication/vnd.wordperfect;version=\"5.0\"\t0\n"
"*.w51\tWordPerfect for MS-DOS/Windows Document 5.1\tapplication/vnd.wordperfect;version=\"5.1\"\t0\n"
"*.w52\tWordPerfect for Windows Document 5.2\tapplication/vnd.wordperfect;version=\"5.2\"\t0\n"
"*.warc\tWARC, Web ARChive file format\tapplication/warc\t0\n"
"*.wast\tWebAssembly\ttext/x-common-lisp\t0\n"
"*.wav\tWaveform Audio\taudio/x-wav\t0\n"
"*.wbmp\tWireless Bitmap File Format\timage/vnd.wap.wbmp\t0\n"
"*.webapp\tOpen Web App Manifest\tapplication/x-web-app-manifest+json\t0\n"
"*.webidl\tWebIDL\ttext/x-webidl\t0\n"
"*.webm\tWebM\tvideo/webm\t0\n"
"*.webp\tWebP\timage/webp\t0\n"
"*.wisp\twisp\ttext/x-clojure\t0\n"
"*.wk1\tLotus 1-2-3 Worksheet 2.0\tapplication/vnd.lotus-1-2-3;version=\"2.0\"\t0\n"
"*.wk3\tLotus 1-2-3 Worksheet 3.0\tapplication/vnd.lotus-1-2-3;version=\"3.0\"\t0\n"
"*.wk4\tLotus 1-2-3 Worksheet 4-5\tapplication/vnd.lotus-1-2-3;version=\"4-5\"\t0\n"
"*.wks\tLotus 1-2-3\tapplication/vnd.lotus-1-2-3\t0\n"
"*.wma\tWMA (Windows Media Audio) File Format\taudio/x-ms-wma\t0\n"
"*.wmf\tWindows Metafile\timage/wmf\t0\n"
"*.wmlc\tCompiled WML Document\tapplication/vnd.wap.wmlc\t0\n"
"*.wmls\tWML Script\ttext/vnd.wap.wmlscript\t0\n"
"*.wmlsc\tCompiled WML Script\tapplication/vnd.wap.wmlscriptc\t0\n"
"*.wmv\tWMV (Windows Media Video) File Format\tvideo/x-ms-wmv\t0\n"
"*.woff\tWeb Open Font Format\tapplication/font-woff\t0\n"
"*.wp4\tWordPerfect 4.0/4.1/4.2\tapplication/vnd.wordperfect;version=\"4.0/4.1/4.2\"\t0\n"
"*.wpd\tWordPerfect\tapplication/vnd.wordperfect\t0\n"
"*.wpl\tWindows Media Playlist\tapplication/vnd.ms-wpl\t0\n"
"*.wrl\tVRML\tmodel/vrml\t0\n"
"*.wsz\tWinamp Skin\tinterface/x-winamp-skin\t0\n"
"*.x3d\tX3D\tmodel/x3d+xml\t0\n"
"*.x3f\tSigma raw image\timage/x-raw-sigma\t0\n"
"*.xap\tSilverlight\tapplication/x-silverlight-app\t0\n"
"*.xar\tXar (vector graphics)\tapplication/vnd.xara\t0\n"
"*.xbm\tXBM\timage/x-xbitmap\t0\n"
"*.xc\tXC\ttext/x-csrc\t0\n"
"*.xcf\tGIMP Image File\timage/xcf\t0\n"
"*.xdm\tX-Windows Screen Dump File X10\timage/x-xwindowdump;version=\"x10\"\t0\n"
"*.xfdf\tXFDF\tapplication/vnd.adobe.xfdf\t0\n"
"*.xhtml\tExtensible HyperText Markup Language (XHTML), 1.0\tapplication/xhtml+xml\t0\n"
"*.xif\tXIFF\timage/vnd.xiff\t0\n"
"*.xla\tMicrosoft Excel Macro 4.0\tapplication/vnd.ms-excel;version=\"4.0\"\t0\n"
"*.xlam\tOffice Open XML Workbook Add-in (macro-enabled)\tapplication/vnd.ms-excel.addin.macroenabled.12\t0\n"
"*.xlc\tMicrosoft Excel Chart 3.0\tapplication/vnd.ms-excel;version=\"3.0\"\t0\n"
"*.xlm\tMicrosoft Excel Macro 3.0\tapplication/vnd.ms-excel;version=\"3.0\"\t0\n"
"*.xls\tMicrosoft Excel Spreadsheet\tapplication/vnd.ms-excel\t0\n"
"*.xlsb\tMicrosoft Excel 2007 Binary Spreadsheet\tapplication/vnd.ms-excel.sheet.binary.macroenabled.12\t0\n"
"*.xlsm\tOffice Open XML Workbook (macro-enabled)\tapplication/vnd.ms-excel.sheet.macroenabled.12\t0\n"
"*.xlsx\tOffice Open XML Workbook\tapplication/vnd.openxmlformats-officedocument.spreadsheetml.sheet\t0\n"
"*.xltm\tOffice Open XML Workbook Template (macro-enabled)\tapplication/vnd.ms-excel.template.macroenabled.12\t0\n"
"*.xltx\tOffice Open XML Workbook Template\tapplication/vnd.openxmlformats-officedocument.spreadsheetml.template\t0\n"
"*.xlw\tMicrosoft Excel 4.0 Workbook (xls) 4W\tapplication/vnd.ms-excel;version=\"4w\"\t0\n"
"*.xm\tExtended Module Audio File\taudio/xm\t0\n"
"*.xmf\tXMF, eXtensible Music File Format, Version 1.0\taudio/mobile-xmf\t0\n"
"*.xmind\tXMind Pro\tapplication/x-xmind\t0\n"
"*.xml\tExtensible Markup Language\tapplication/xml\t0\n"
"*.xmt\tMPEG-4, eXtensible MPEG-4 Textual Format (XMT)\tapplication/mpeg4-iod-xmt\t0\n"
"*.xpi\tCross-Platform Installer Module\tapplication/x-xpinstall\t0\n"
"*.xpl\tXProc\ttext/xml\t0\n"
"*.xpm\tX-Windows Pixmap Image X10\timage/x-xpixmap;version=\"x10\"\t0\n"
"*.xps\tOpen XML Paper Specification\tapplication/oxps\t0\n"
"*.xpt\tSAS Transport File Format (XPORT) Family \tapplication/x-sas-xport\t0\n"
"*.xq\tXQuery source code\tapplication/xquery\t0\n"
"*.xquery\tXQuery\tapplication/xquery\t0\n"
"*.xs\tXS\ttext/x-csrc\t0\n"
"*.xsd\tXML Schema Definition\tapplication/xml\t0\n"
"*.xsl\tExtensible Stylesheet Language\tapplication/xml\t0\n"
"*.xslfo\tXSL Format\tapplication/xslfo+xml\t0\n"
"*.xslt\tXSL Transformations\tapplication/xslt+xml\t0\n"
"*.xsp-config\tXPages\ttext/xml\t0\n"
"*.xspf\tXML Shareable Playlist Format\tapplication/xspf+xml\t0\n"
"*.xwd\tX Windows Dump\timage/x-xwindowdump\t0\n"
"*.xz\tXZ\tapplication/x-xz\t0\n"
"*.y\tYacc/Bison source code\ttext/x-yacc\t0\n"
"*.yaml\tYAML source code\ttext/x-yaml\t0\n"
"*.yml\tYAML\ttext/x-yaml\t0\n"
"*.zip\tCompressed Archive File\tapplication/zip\t0\n";

static void splitFileParts( const char* path, 
														 char** filename, 
														  char** fileextension, 
														   char** fileparents)
{
	const char* slashPos = strrchr(path, FILE_PATH_SEP) ;
	if(!slashPos){
		*fileparents = malloc(1) ;
		strcpy(*fileparents, "") ;

		const char* dotPos = strrchr(path, '.') ;
		if ( !dotPos ){ // no  extension 
			*fileextension = malloc(1) ;
			strcpy(*fileextension, "") ;
			*filename = malloc(strlen(path)) ;
			strcpy(*filename, path) ;
		} 
		else{
			*fileextension = malloc(strlen(dotPos)) ;
			strcpy(*fileextension, dotPos) ;
			size_t bytes = dotPos - path ; // do not add the dot 
			*filename = malloc(bytes+1) ;
			strncpy(*filename, path , bytes ) ;
			(*filename)[bytes] = '\0';
		}
	}
	else {
		size_t bytes = slashPos - path + 1;
		*fileparents = malloc(bytes+1) ;
		strncpy(*fileparents, path, bytes) ;
		(*fileparents)[bytes] = '\0' ;
		
		const char* dotPos = strrchr(path, '.') ;
		if ( dotPos < slashPos || dotPos == NULL ){ // not an extension 
			*fileextension = malloc(1) ;
			strcpy(*fileextension, "") ;
			*filename = malloc(strlen(slashPos)) ;
			strcpy(*filename, slashPos + 1) ;
		} 
		else{
			*fileextension = malloc(strlen(dotPos)) ;
			strcpy(*fileextension, dotPos) ;
			size_t bytes = dotPos - slashPos - 1;
			*filename = malloc(bytes+1) ;
			strncpy(*filename, slashPos +1 , bytes ) ;
			(*filename)[bytes] = '\0';
		}
		
	}
}

static size_t readNextMimeLine( const char* mimetypes, char* buffer, size_t size, size_t pos) 
{
	const char* startingPosition = mimetypes + pos ;
	const char* newLinePos = strchr(startingPosition, '\n') ;
	
	if 	(newLinePos) {
		size_t distance = newLinePos - startingPosition ;
		size_t nBytes =  distance < size - 1 ? distance : size - 1 ;
	
		strncpy( buffer, startingPosition, nBytes + 1 ) ;
		buffer[nBytes] = '\0' ;
		return distance + 1 ;
	}
	else return 0 ;
}

static void parseMegaMimeLine ( const char* buffer, char** ext, char** name, char** mimetype) 
{
	//printf("%s\n", buffer) ;
	const char* firstTab = strchr(buffer, '\t') ;
	const char* secondTab = strchr(firstTab+1, '\t') ;
	const char* lastTab = strchr(secondTab+1, '\t') ;
	
	assert ( firstTab != NULL && secondTab != NULL && lastTab != NULL) ;
	
	size_t extLen = firstTab - buffer;
	size_t nameLen = secondTab - firstTab ;
	size_t mimeLen = lastTab - 	secondTab ;
	
	if(name){
		*name = malloc( nameLen + 1 ) ;
		assert(*name != NULL );
		strncpy(*name, firstTab + 1, nameLen - 1) ;
		(*name)[nameLen] = '\0' ;
	}
	if(mimetype){
		*mimetype = malloc( mimeLen + 1 ) ;
		assert(*mimetype != NULL );
		strncpy(*mimetype, secondTab + 1, mimeLen -1 ) ;
		(*mimetype)[mimeLen] = '\0' ;
	}
	if (ext){
		*ext = malloc( extLen+1) ;
		assert(*ext != NULL);
		strncpy(*ext, buffer, extLen) ;
		(*ext)[extLen] = '\0' ; 
	}
}

static bool splitMimeTypeParts( const char* target, char** firstPart, char** lastPart, char** trailingPart )
{
	const size_t MAX_PART_SIZE= 64 ;
	char* mimeFirstPart = malloc(MAX_PART_SIZE),  *mimeLastPart = malloc(MAX_PART_SIZE) , 
						*trailingDetails =      malloc(MAX_PART_SIZE * 2) ;
	const char* slashPosition = strchr(target, '/') ;
	if(!slashPosition) return false ;
	const char* colonPosition = strchr(target, ';') ;
	if(!colonPosition) colonPosition = target + strlen(target);
	
	size_t firstPartLen = slashPosition - target ;
	assert(firstPartLen < MAX_PART_SIZE );
	strncpy( mimeFirstPart, target, firstPartLen) ;
	mimeFirstPart[firstPartLen] = '\0';
	
	size_t lastPartLen = colonPosition - slashPosition ;
	assert(lastPartLen < MAX_PART_SIZE) ;
	strncpy( mimeLastPart, slashPosition+1, lastPartLen -1 );
	mimeLastPart[lastPartLen-1] = '\0';
	
	if(*colonPosition){
		size_t trailingLen = target + strlen(target) - colonPosition ;
		assert(trailingLen < MAX_PART_SIZE * 2 ) ;
		strncpy( trailingDetails , colonPosition + 1 , trailingLen -1 );
		trailingDetails[trailingLen-1] = '\0';	
	}
	else{
		trailingDetails[0] ='\0';
	}
	*firstPart = mimeFirstPart ;
	*lastPart = mimeLastPart ;
	*trailingPart = trailingDetails ;
	
	return true ;
}

static bool matchesMimeType ( const char* target, const char* mimetype )
{
	char* targetFirstPart , *targetLastPart, *targetDetailsPart ;
	char* mimeFirstPart, *mimeLastPart, *mimeDetailsPart ;
	
	if(!splitMimeTypeParts( target, &targetFirstPart, &targetLastPart, &targetDetailsPart))  return false ;
	if(!splitMimeTypeParts( mimetype, &mimeFirstPart, &mimeLastPart, &mimeDetailsPart)) {
		free(targetFirstPart) ; free(targetLastPart) ; free(targetDetailsPart) ;
		return false ;	
	}
	bool ret =  ( (strcmp(targetFirstPart, mimeFirstPart) == 0 || strcmp(targetFirstPart , "*") == 0 ) &&
			 (strcmp(targetLastPart, mimeLastPart) == 0 || strcmp(targetLastPart , "*") == 0 ) ) ;
	
	free(targetFirstPart) ; free(targetLastPart) ; free(targetDetailsPart) ;
	free(mimeFirstPart) ; free(mimeLastPart) ; free(mimeDetailsPart) ;

	return ret ;
}

static bool isDirectory(const char* url)
{
	FILE* file = fopen(url, "rb") ;
	if(!file) return false ;

	char c = fgetc(file) ;
	fseek(file, 0, SEEK_END) ;
	long long pos = ftell(file);
	
	fclose(file);

	return pos == LLONG_MAX && c == WEOF ;
} 

static bool searchThroughMimes(const char* target,  
								char** extension,
								 char** name, 
								  char** type,
								   bool mimename,
								    bool reset ) 
{

	static _Thread_local size_t position = 0 ;
	if ( reset) position = 0 ;
	
	if(!target) return false ;

	const int BUFFER_SIZE = 256 ;
	char buffer[BUFFER_SIZE];
	
	size_t pos = position ;
	size_t len = strlen(MegaMimeTypes);
	
	for ( size_t i = position ; i < len ; i += pos )
	{
		pos = readNextMimeLine( MegaMimeTypes, buffer, BUFFER_SIZE, i) ;
		
		position += pos ;
		if (pos){
			char* nameBuff, *mimetypeBuff , *extBuff;
			parseMegaMimeLine ( buffer, &extBuff, &nameBuff, &mimetypeBuff) ;
			if ( mimename ){
				if (matchesMimeType( target, mimetypeBuff)){
					if (extension) *extension = extBuff; else free(extBuff);
					if (name) *name = nameBuff ; else free(nameBuff); 
					if (type) *type = mimetypeBuff ; else free(mimetypeBuff);
					return true ;
				}
			}
			else{ // search extension 
				if (strcmp(extBuff+1, target) == 0 ){
					if (extension) *extension = extBuff; else free(extBuff);
					if (name) *name = nameBuff ; else free(nameBuff); 
					if (type) *type = mimetypeBuff ; else free(mimetypeBuff);
					return true ; 
				} 
			}
		} 
	}
	return false ;
}


static const char* guessFileEncoding( const char* url )
{
	FILE* pFile = fopen(url, "rb");
	if(!pFile) return NULL ;
	
	unsigned char firstByte =  fgetc(pFile) ;
	unsigned char secondByte = !feof(pFile)? fgetc(pFile) : 'A' ;
	unsigned char thirdByte =  !feof(pFile)? fgetc(pFile) : 'A' ;
	unsigned char fourthByte = !feof(pFile)? fgetc(pFile) : 'A' ;
	
	if ( firstByte == 0xEF && secondByte == 0xBB && thirdByte == 0xBF ){
		return "UTF-8" ;
	}	
	else if ( firstByte == 0xFF && secondByte == 0xFE ){
		return "UTF-16LE";
	}
	else if ( firstByte == 0xFE && secondByte == 0xFF ){
		return "UTF-16BE";
	}
	else if ( firstByte == 0xFF && secondByte == 0xFE && thirdByte == 0x0 && fourthByte == 0x0){
		return "UTF-32LE";
	}
	else if ( firstByte == 0x00 && secondByte == 0x00 && thirdByte == 0xFE && fourthByte == 0xFF){
		return "UTF-32BE";
	}
	else return "UTF-8";
}

char* getMegaMimeType ( const char* pFilePath )
{
	if ( pFilePath == NULL ) return NULL ;
	
	char* pDotPos = strrchr(pFilePath, '.');
	char* pSeparator = strrchr(pFilePath, FILE_PATH_SEP );
	
	// no extension. Cannot determine mime type 
	if (!pDotPos ) return NULL ;
	
	if(pSeparator)
		if ( pDotPos < pSeparator ) 
			return NULL ;
	
	char* name, *type , *ext;		
	if(searchThroughMimes(pDotPos, &ext, &name, &type, false, true)){
		free(name) ;
		free(ext);
		return type ;
	}
	return NULL ;
}


char** getMegaMimeExtensions ( const char* pMimeType )
{
	char* ext ;
	size_t number = 5 , pos = 0 ;
	char** extensions = calloc(sizeof(char*), number) ;
	
	searchThroughMimes(NULL, NULL, NULL, NULL, true, true) ;
	while( searchThroughMimes( pMimeType, &ext, NULL, NULL, true, false )) {
		if ( pos == number - 1 ){
			number += 5 ;
			extensions = (char**)realloc(extensions, (sizeof(char*)) * (number)); 
		}
		extensions[pos++] = ext ;
	}
	extensions[pos] = NULL ;
	if(!pos){
		free(extensions);
		return NULL ;
	}
	else return extensions ;
}


bool isTextFile ( const char* url )
{
	if(isDirectory(url))
	{
		return false ;
	}
	const char* zEnc = guessFileEncoding (url);
	if (strcmp(zEnc , "UTF-8") == 0 ){
		FILE* pFile = fopen(url, "r");
		if (!pFile) return false;

		char ch = fgetc(pFile);
		while(!feof(pFile) && ch != EOF ){
			if ( iscntrl(ch) && !isspace(ch)) {  fclose(pFile); return 0;}
			ch = fgetc(pFile);
		}
		fclose(pFile);
		return true ;
	} 		
	else{
		FILE* pFile = fopen(url, "r,ccs=UNICODE");
		if (!pFile) return false;
		
		for ( wint_t ch = fgetwc(pFile) ; ch != WEOF && !feof(pFile); ch = fgetwc(pFile)){
			if (iswcntrl(ch) && !iswspace(ch)) { fclose(pFile) ; return 0; }
		}
		fclose(pFile);
		return true ;
	}
	return false;
}


bool isBinaryFile (const char* url )
{
	return !isTextFile(url);
}



MegaFileInfo* getMegaFileInformation( const char* pFilePath )
{
	FILE* fp = fopen(pFilePath, "rb");
	if(!fp) return NULL ;
	if(isDirectory(pFilePath)){  return NULL; }

	MegaFileInfo* info = malloc(sizeof(MegaFileInfo));
	char* filename, *fileextension, *fileparents ;
	splitFileParts( pFilePath, &filename, &fileextension, &fileparents) ;

	info->mBaseDir = fileparents ;
	info->mBaseName = filename ;
	info->mExtension = fileextension ;

	fseek(fp, 0, SEEK_END) ;
	info->mFileSize = ftell(fp) ;

	char* mimetype, *mimename ;
	searchThroughMimes(fileextension, NULL, &mimename, &mimetype, false, true) ;
	info->mMimeName = mimename ;
	info->mMimeType = mimetype ;
	
	info->mTextFile = isTextFile(pFilePath) ;
	if(info->mTextFile){
		const char* enc = getMegaTextFileEncoding(pFilePath);
		info->mTextEncoding = malloc(strlen(enc)+1);
		assert(info->mTextEncoding != NULL);
		strcpy(info->mTextEncoding, enc);
	}
	else{
		char* sp = malloc(1) ;
		assert(sp != NULL);
		strcpy(sp, "") ;
	}
	
	return info ;
}

const char* getMegaTextFileEncoding( const char* path )
{
	return guessFileEncoding(path);
}

void freeMegaFileInfo(MegaFileInfo* pData )
{
	if(!pData) return ;
	
	free(pData->mBaseDir) ;
	free(pData->mBaseName) ;
	free(pData->mExtension );

	if(pData->mMimeType) free(pData->mMimeType) ;
	if(pData->mMimeName) free(pData->mMimeName) ;
	free(pData->mTextEncoding);
		
	free(pData)	;
}

void freeMegaString( char* pData )
{
	if(pData) free(pData) ; 
}

void freeMegaStringArray( char** pData) 
{
	if(!pData) return ;
	for ( size_t i = 0 ; pData[i] ; ++i){
		freeMegaString(pData[i]) ;		
	} 
	free(pData) ;
}
