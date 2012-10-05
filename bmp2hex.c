#include<stdio.h>
#include "file_error.h"
/*
	-BMP_READ to read the bmp file & write into hex.
	-BMP_WRITE to read the text file from microController
			& write into bmp.
*/
#define FILE_OUT
#define BUFFER_SIZE 4096		//don't make too large for small files.
//#define BMP_WRITE 1

//function prototype
//unsigned int print_buf(char *buf_ptr,unsigned int buf_size);
unsigned int print_buf(char *buf_ptr,unsigned int buf_size,long int *count_ptr);

int main()
{
	FILE *file_stream_in;
	#ifdef FILE_OUT
	FILE *file_stream_out;
	#endif

	unsigned char c[BUFFER_SIZE];
	long int i=0; 		//if BUFFER_SIZE is long make it long.
	long int counter=0;
////////////////////////////////////////////////////////////////////////////
	//#if defined BMP_READ
	file_stream_in=fopen("Cover.bmp","rb");
	if(file_stream_in==NULL)
	return FILE_OPEN_ERROR;

	#ifdef FILE_OUT
	file_stream_out=fopen("Cover_test.bmp","wb");
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
	while(!feof(file_stream_in))
	{
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
	*/
	
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

	fclose(file_stream_in);
	#ifdef FILE_OUT
	fclose(file_stream_out);
	#endif
return 0;
}

unsigned int print_buf(char *buf_ptr,unsigned int buf_size,long int *count_ptr)
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
