/* Programmer:
* Class: CptS121, Fall 2018
* Programming lab: 4
* Date: Sept. 14, 2018
* Description: Pascal Triangle Array/Algorithm
* This will work with any positive value of MAX_ROWS. This one
* produces cool-looking results on an 80-character width console, but
* you might want to set it to a lower value like 5 while debugging.
* (Or a higher value if you want to print a poster!)
*/
#include <stdio.h>

int main(void)
{
/*
* declare int arrays oldRow[] and newRow[] to hold MAX_ROWS+1 elements
* for n from 0 to MAX_ROWS-1 (thus looping MAX_ROWS times)
*     compute and output appropriate indentation (see text below)
*     for m from 0 to n, inclusive
*         if m is zero (first item on row)
*             set newRow[m] to 1
*         else if m is n (last item on row)
*             set newRow[m] to 1
*         else (middle items on row)
*             set newRow[m] to the sum of the m'th and the m-1'st
*              elements of oldRow[]
*     for m from 0 to n, inclusive
*       print the m'th element of newRow[] (without a newline)
*         set oldRow[m] to newRow[m] (for the next iteration)
*     print a newline
*/
	// declare row loops
	int max_rows, m, n;
	// prompts max rows
	printf("Please enter the max rows of Pascal Triangle: ");
	scanf("%d", &max_rows);
	// declare 2 arrays for loop
	int oldRow[max_rows+1], newRow[max_rows+1];
	
	// pascal triangle loop
	for (n = 0; n <= max_rows-1; n++) {
		// indentation
		for (int a = 0; a <= max_rows-1-n; a++) {
			printf(" ");
		}
		// set value to each elements
		for (m = 0; m <= n; m++) {
			if (m == 0) {
				newRow[m] = 1;
			} else if (m == n) {
				newRow[m] = 1;
			} else {
				newRow[m] = oldRow[m] + oldRow[m - 1];
			}
		}
		// print the row
		for (m = 0; m <= n; m++) {
			printf(" %i", newRow[m]);
			oldRow[m] = newRow[m];
		}
		// print new line
		printf("\n");
	}
	return 0;
}
