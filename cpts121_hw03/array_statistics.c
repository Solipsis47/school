#include <stdio.h>
#include <stdlib.h> // For rand() function
#include <time.h> // For time() function

int main(void)
{
   	int arr[100], count[21], i = 0, j = 0;
	
	// Used time(NULL) to seed rand() and generate a different 
	// set of numbers everytime the program is run
	srand(time(NULL));

	// Populates arr[] with 100 random integers from 1 - 20
	// using rand()
   	while(i < 100)
   	{
       		arr[i] = (rand() % 20) + 1;
       		i++;
   	}
	
   	j = 0;
	
	// Initialize each item in the count[] array to 0
   	while(j < 21)
   	{
       		count[j] = 0;
       		j++;
   	}
	
   	i = 0;
	
	// Counts the frequency of integers in arr[] array
   	while(i < 100)
   	{
       		count[ arr[i] ] = count[ arr[i] ] + 1;
       		i++;
   	}
	
   	i = 0;
	
	printf("\n\nThe statistics for the 20 random integers are:\n\n");
	printf("Integer\trepetition");
	
	// Prints the frequency of each integers
	for (i = 1; i < 21; i++)
	{
		printf("\n%d\t%d\n", i, count[i]);
	} 
	
	return 0;
}

