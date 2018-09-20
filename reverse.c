// R.J. Hamilton
// CIS 343 - 01
// September 10, 2018

#include <stdio.h>
#include "file_utils.h"
#include <sys/stat.h>

int main(int argc, char** argv)
{	
	char* inputFile = argv[1]; //Stores the input file in a char pointer
	char* outputFile = argv[2]; //Stores the output file in a char pointer
	char* buffer;
	int fileSize;

	// Checks to make sure three arguments are being passed when 
	// this program is run. Displays the proper usage of this 
	// program to the user.
	if ((argc < 3) || (argc > 3))
	{
		printf ("Proper usage of this command is as follows:\n."
			"/reverse <INPUT_FILENAME> <OUTPUT_FILENAME>");
		return 1;
	}
	
	fileSize = read_file(inputFile, &buffer); // Stores the size of the input file 
						  // in an integer.
	char tempArray[fileSize]; // Creates a temporary array of a size that 
				  // will be able to hold the contents of the input file.
	
	// Iterates for the size of the file and assigns the contents of
	// the file to the temporary array.
	for(int i = 0; i < fileSize; i++)
	{
		tempArray[i] = *(buffer + fileSize - 1 - i);
	}

	buffer = tempArray; // The buffer pointer is given a copy of the
  			    // elements in the temporary array.

	// The contents of buffer are written onto the output file.
	write_file(outputFile, buffer, fileSize); 	
	return 0;
}

