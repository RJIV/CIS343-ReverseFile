//R.J. Hamilton
//CIS343 - 01
//September 10, 2018

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int read_file(char* filename, char **buffer)
{
	FILE *filePointer;
	
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	
	filePointer = fopen(filename, "r");

	if(filePointer == NULL)
	{
		fprintf(stderr, "Failed to open the file.\n");
		exit(1);
	}
	else
	{
		*buffer = malloc(sizeof(char) *(size));
		fread(*buffer, sizeof(char), size, filePointer);
		fclose(filePointer);
	}

	return size;

}

int write_file(char* filename, char *buffer, int size)
{
	FILE *filePointer = fopen(filename, "w");

	if (filePointer == NULL)
	{
		fprintf(stderr, "Failed to open the file.\n");
		exit(1);
	}
	else
	{
		fwrite(buffer, sizeof(char), size, filePointer);
	}

	return 0;
}
