
#
#
#
#

GCC = gcc

SOURCE = bmp2hex
SOURCE_EXT = c

all   :   compile

compile : 
	$(GCC) $(SOURCE).$(SOURCE_EXT) -o $(SOURCE) -Wall

clean :
	rm -f $(SOURCE)
