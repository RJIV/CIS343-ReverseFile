/* R.J. Hamilton
 * CIS343 - 01
 * September 10, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/* Reads a file using pointers and dynamic memory allocation.
 *
 * @param filename: A file name is passed in as an array of characters.
 * @param buffer: A pointer to a pointer of character values to store information.
 * @return: Returns the size of the file.
 */
int read_file(char* filename, char **buffer)
{
	FILE *filePointer;
	
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	
	filePointer = fopen(filename, "r");

	// Checks to see if the file being read is NULL.
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

/* Writes to a file using pointers and dynamic memory allocation.
 *
 * @param filename: A file name is passe din as an array of characters.
 * @param buffer: A pointer of character values to store information.
 * @param size: A size is determined by the user.
 */
int write_file(char* filename, char *buffer, int size)
{
	FILE *filePointer = fopen(filename, "w");
	
	// Checks to see if the file being read is NULL.
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
