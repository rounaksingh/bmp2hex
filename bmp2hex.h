/************************************************************************
 *	Author: Rounak SIngh
 *	email : rounaksingh17@gmail.com
 *
 *	Description : This is a header file for bmp2hex.c ,,,, 
 *	required to be included with above mentioned file.
 *
 *	Contain error definition & function prototypes.
 *
 ***********************************************************************/

/*************************************************************************

     This section contains the error occured, when handling the arguments

**************************************************************************/

#define LESS_ARGUMENT 1
#define MORE_ARGUMENT 2			//the program isnot defined for more than 1 arguement. we can write this in TODO list.
#define 

/*************************************************************************

	This section contains the errors occur, when handling the files.

**************************************************************************/

#define FILE_OPEN_ERROR 	1
#define FILE_CLOSE_ERROR 	2
#define FILE_WRITE_ERROR 	3
#define FILE_READ_ERROR 	4
#define FILE_EOF_REACHED 	5
#define FILE_EXISTS		6
#define FILE_SEEK_ERROR		7

/***************************************************************************

	This section contains function prototypes.

***************************************************************************/

unsigned int print_buf(unsigned char *buf_ptr,unsigned int buf_size,long int *count_ptr);

int hex_write(unsigned char *buf_ptr,unsigned int buf_size,long int *count_ptr,FILE *file_write);

int start_of_file(FILE *file_write);

