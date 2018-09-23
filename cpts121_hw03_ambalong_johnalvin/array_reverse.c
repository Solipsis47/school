#include <stdio.h>

int main (void)
{
	int n, j, k, temp, a[100];

	// Prompts for total number of elements
	printf("\nPlease enter the total number of elements: ");
	scanf("%d", &n);

	printf("Please enter the numbers:\n");

	// Enter elements into the array
	for (j = 0; j < n; j++)
	{
		scanf("%d", &a[j]);
	}

	k = j - 1; // Assign k to last array element
	j = 0; // Assign j to first array element

	// Reverse the elements by using a placeholder 'temp'
	while (j < k)
	{
		temp = a[j];
		a[j] = a[k];
		a[k] = temp;
		j++;
		k--;
	}

	printf("The numbers in reverse order: ");
	
	for (j = 0; j < n; j++)
	{
		printf("%d ", a[j]);
	}
	
	printf("\nGood bye!\n");

	return 0;
}

