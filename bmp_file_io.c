#include<stdio.h>
#include "file_io.h"
/*
	-BMP_READ to read the bmp file & write into hex.
	-BMP_WRITE to read the text file from microController
			& write into bmp.
*/
#define BUFFER_SIZE 1			//don't make too large for small files.
#define BMP_WRITE 1

int main()
{
	FILE *file_stream_in;
	FILE *file_stream_out;
	
	unsigned char c[BUFFER_SIZE];
	
////////////////////////////////////////////////////////////////////////////
	#if defined BMP_READ
	file_stream_in=fopen("Logo.bmp","rb");
	fread(&c[0],1,sizeof(unsigned char),file_stream_in);
	
//////////////////////////////////////////////////////////////////////////
	#elif defined BMP_WRITE
	
	file_stream_in=fopen("libbmp-testing-hyper.txt","r");
	if(file_stream_in==NULL)
	return OPEN_ERROR_FILE_STREAM_OUT;
	file_stream_out=fopen("test.bmp","wb");
	if(file_stream_in==NULL)
	return OPEN_ERROR_FILE_STREAM_IN;
	
	puts("Starting Reading & Writing");
	while(!feof(file_stream_in))
	{
		fread(&c[0],BUFFER_SIZE,sizeof(unsigned char),file_stream_in);
		fwrite(&c[0],BUFFER_SIZE,sizeof(unsigned char),file_stream_out);
	}
	puts("Completed Read & Write");
	fclose(file_stream_in);
	fclose(file_stream_out);
	
	#endif
	//////////////////////////////////////////////////////////////////////////
	return 0;
}

