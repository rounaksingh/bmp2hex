
#
#
#
#

GCC = gcc

SOURCE = pngimage
SOURCE_EXT = cc

all   :   compile

compile : 
	$(GCC) $(SOURCE).$(SOURCE_EXT) -o $(SOURCE) -I/usr/local/include\
	 -L/usr/local/lib -lpng -lpngwriter -lz -DNO_FREETYPE

