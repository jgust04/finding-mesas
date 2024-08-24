#include "array.h"

unsigned int* create_array( FILE* in, unsigned int *size )
{
	// Reads in the input file and stores the int at the memory location of size
	fscanf(in, "%u", size);

	// Creates a dynamically allocated integer array with size based on number read in 
	unsigned int* arr = malloc(*size * sizeof(int)); 

	return arr;
}

unsigned int* free_memory( unsigned int* pointer )
{
	// frees memory and returns NULL
	free(pointer);
	return NULL;
}

void read_data( FILE* in, unsigned int *data, unsigned int count )
{
	for ( unsigned int i=0; i<count; i++ )
		fscanf(in, "%u", &data[i]);

	/*get rid of the newline -- the * indicates to ignore this
	field that was read in via fscanf*/
	fscanf(in, "%*c" ); 
}

void display_data( FILE* out, unsigned int count, unsigned int* data )
{
	// Variable declarations and initializations
	int column = 0;
	unsigned int index = 0;

	// First index of grid - left empty
	fprintf(out, "%s ", "\t");

	// If array is less than or equal to 10 indicies
	if (count <= 10)
	{
		// Displays the 1 - count in the first row
		for (unsigned int i = 0; i < count; i++)
		{
			fprintf(out, "%d\t ", i);
		}

		// First index in second row (column number)
		fprintf(out, "\n%d ", column);

		// Displays the array values of 1 - count in the second row
		for (unsigned int i = 0; i < count; i++)
		{
			fprintf(out, "%d ", data[i]);
		}
	}

	// If array is larger than 10 indicies
	else 
	{
		// Displays the 1 - 9 in the first row
		for (int i = 0; i < 10; i++)
		{
			fprintf(out, "%d\t ", i);
		}
		
		// While loop to display values of the array
		while (index < count)
		{
			// First value of each row (column number)
			if (index % 10 == 0)
			{
				fprintf(out, "\n%d ", column);
				column++;
				fprintf(out, "%d ", data[index]);
				index++;
			}

			// All other array values
			else
			{
				fprintf(out, "%d ", data[index]);
				index++;
			}
		}
	}
}
