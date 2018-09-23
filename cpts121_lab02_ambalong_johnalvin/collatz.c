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
	int n = 0;/* define variable n */

	printf ("enter integer:\n");/* prompt user for an integer n */
	scanf ("%d", &n);/* scan input from user */

	if (n <= 0)
	{
		printf ("ERROR: integer must be positive.\n");
		return 0;
	}

	while (n > 1)

        {
	       	if (n%2 == 0)
		{

			n /= 2;/* Divide integer by 2 if even */

		} else {

			n = 3 * n + 1;/* multiply by 3 and add 1 if odd */
		}

		printf ("%d\n", n);/* prints n */
        }
	return 0;
}
