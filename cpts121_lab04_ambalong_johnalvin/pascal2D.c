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
#define MAX_ROWS 16

int main(void)
{
	int m, n, acum, pascal[MAX_ROWS+1][MAX_ROWS+1];
	
	for (n = 0; n <= MAX_ROWS-1; n++) {
                for (m = 0; m <= MAX_ROWS-1; m++) {
                        pascal[n][m] = 0;
                }
        }


	for (n = 0; n <= MAX_ROWS-1; n++) {

		for (m = 0; m <= n; m++) {
			if (m == 0) {
				pascal[n][m] = 1;
			} else if (m == n) {
				pascal[n][m] = 1;
			} else {
				pascal[n][m] = pascal[n - 1][m] + pascal[n - 1][m - 1];
			}
		}

	}
	for (n = 0; n <= MAX_ROWS-1; n++) {
		for (m = 0; m <= MAX_ROWS-1; m++) {
			acum += pascal[n][m];
		}
	}
	
	printf("The sum: %d\n ", acum);

	return 0;
}
