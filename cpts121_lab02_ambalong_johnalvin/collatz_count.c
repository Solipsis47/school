/* 
* Programmer: John Alvin Ambalong
* Class: Cpt121, Fall  2018 
* Programming lab: Lab 2
* Date: 08/31/2018
* Description: Repitition Lab
*/
#include <stdio.h>
int main(void)
{
	int maxN, initialN, count;/* define variables */
	maxN = 0;

	printf ("enter maximum n: ");/* prompt user for maximum  n */
	scanf ("%d", &maxN);/* scan input from user */

	if (maxN < 0)/* check if maximum number is positive */
	{
		printf ("ERROR: integer must be positive.\n");
		return 0;
	}

	printf ("initial n\tcount\n");

	for (int i = 0; i  <= maxN; i++)/* iterations */
	{
		count = 0;
		initialN = i;
		while (initialN > 1)/* collatz conjecture */

        	{
	       		if (initialN%2 == 0)
			{

				initialN /= 2;/* divide integer by 2 if even */

			} else {

				initialN = 3 * initialN + 1;/* multiply integer by 3 and add 1 if odd */
			}

			count++;/* adds counter */
        	}
		
		printf ("%d\t\t%d\n", i, count);/* prints the results */
	}
	return 0;
}
