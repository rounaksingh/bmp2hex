
/*
 *	Author: Rounak SIngh
 *	email: rounaksingh17@gmail.com
 *	
 *	Purpose of program : Convert a bmp or any file to a hex like format.
 *			(for hex like format, please refer Wikipedia, search for "hex file")
 *
 *	Description: This Program reads byte by byte a bmp file(Tested) or any other file (not Tested), to store in a buffer.
 *	Afterwards write to a txt file in a hex like format to read single byte value.This type of program are useful for detailed
 *	analysis of the file structures.
 *
 *	IMPORTANT POINT to NOTE:
 *	> BMP_READ to read the bmp file & write into hex.
 *	
 *	> The Buffer must be unsigned char type because 
 *	if just char is written its magnitude becomes negative for certain fread.
 *	so when writing that negative value of buffer to stdout or file in hexadecimal
 *	it prints the complement or the Signed Hex number for it.
 */

#include<stdio.h>
#include "file_error.h"

/*
 define the FILE_OUT to make this program function to write to a file
*/
#define FILE_OUT 1

/* 
 *	>Make the BUFFER_SIZE a multiple of MAX_COLUMN &
 *	>BUFFER_SIZE>=MAX_COLUMN
 */

#define BUFFER_SIZE 4096
#define MAX_COLUMN 0x10

int main(int argc, char *argv[])
{
	FILE *file_stream_in;
	#ifdef FILE_OUT
	FILE *file_stream_out;
	#endif

	unsigned char c[BUFFER_SIZE];
	long int i=0;
	long int counter=0;
////////////////////////////////////////////////////////////////////////////

	file_stream_in=fopen("Cover.bmp","rb");
	if(file_stream_in==NULL)
	return FILE_OPEN_ERROR;

	#ifdef FILE_OUT
	file_stream_out=fopen("Cover_test.txt","wb");
	if(file_stream_out==NULL)
	return FILE_OPEN_ERROR;
	#endif

	/*
	fseek(file_stream_in, 0, SEEK_END);
	i = ftell(file_stream_in);
	printf("%ld",i);
	*/
	/*
	This program reads the data & return the last seek location(offset 
	from the begining.). 
	IMP point to notice is the fread function stops at the eof 
	automatically.
	try any bmp file,,,first check the size of file in bytes.
	*/
	
	//while(!feof(file_stream_in))
	//{
	i=fread(&c[0],sizeof(unsigned char),BUFFER_SIZE,file_stream_in);
	
	//i=ftell(file_stream_in);	
	//printf("%ld ",i);

	/*TTesting fseek changing the seek one by one & printing the s
	seek value one by one.
	while(!feof(file_stream_in))
	{
		i++;
		fseek(file_stream_in,i,SEEK_SET);
		if(i==ftell(file_stream_in));
		printf("%ld ",i);

	}
*/
	/* TO print each byte with its offset number
	

		if(i!=BUFFER_SIZE)

		#ifdef FILE_OUT
		fwrite(&c[0],sizeof(char),i,file_stream_out);		
		#endif
		#ifndef FILE_OUT		
		print_buf(&c[0],i,&counter);
		#endif
			//i=0;
			//fread(&c[0],sizeof(char),i,file_stream_in);	
			//fseek(file_stream_in,-i,SEEK_END);		
			//i=ftell(file_stream_in);	
			//printf("%ld ",i);
		else
		#ifndef FILE_OUT		
		print_buf(&c[0],BUFFER_SIZE,&counter);
		#endif
		#ifdef FILE_OUT
		fwrite(&c[0],sizeof(char),BUFFER_SIZE,file_stream_out);
		#endif	
	
	}
	*/
	start_of_file(file_stream_out);
	hex_write(&c[0],BUFFER_SIZE,&counter,file_stream_out);
	fclose(file_stream_in);
	#ifdef FILE_OUT
	fclose(file_stream_out);
	#endif
	
return 0;
}

unsigned int print_buf(unsigned char *buf_ptr,unsigned int buf_size,long int *count_ptr)
{
	int i;
	char c;
	for(i=0;i<=buf_size;i++)
	{
		c=*buf_ptr;
		printf("%ld %c %x\n",*count_ptr,c,c);
		buf_ptr++;
		/*increase the value of the content of the count_ptr*/
		(*count_ptr)++;
	}
return (buf_size);

}

int hex_write(unsigned char *buf_ptr,unsigned int buf_size,long int *count_ptr,FILE *file_write)
{
	int i,j;
	int number_of_line=(buf_size/MAX_COLUMN);
	for(j=0;j<number_of_line;j++)
	{
		/* write the counter to note the total no of bytes */
		fprintf(file_write,"%06lX :",*count_ptr);

		for(i=1;i<=MAX_COLUMN;i++)	
		{
			fprintf(file_write,"%02X ",*buf_ptr);
			//fprintf(file_write,"%02d ",*buf_ptr);
			buf_ptr++;
			(*count_ptr)++;
		}
	
		fprintf(file_write,"\n");
	}
	return 0;

}

int start_of_file(FILE *file_write)
{
	char c;
	int i;

	fprintf(file_write,"\n");	
	/*
		TO synchronize the start of line with the buffer line. since it starts eight character from left so 
		shifting the start with eight char or whitespace.
	*/
	fprintf(file_write,"        ");

	for(i=1;i<=MAX_COLUMN;i++)
	{
		c=i;
		fprintf(file_write,"%02X ",c);
	}
	
	fprintf(file_write,"\n");
	//fprintf(file_write,"\n");

	return 0;
}

