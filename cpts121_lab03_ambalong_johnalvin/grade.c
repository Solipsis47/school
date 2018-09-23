/* 
* Programmer: John Alvin Ambalong 
* Class: CptS 121, Spring 2018
* Programming lab: Lab 3
* Date: 9/7/2018
* Description: Letter Grade program
*/
#include <stdio.h>
int main(void)
{
/*
* The main function should implement these steps:
*
* 1. Prompt the user to enter the four double values.
*
* 2. Check to make sure the double is positive. If it isn't, print
*    out an error message and exit.
*
* 3. Implement this pseudocode:
*      calculate the average for the 4 values
*      use a if else and else if statement to implement the   
*      conversion to letter grade
*      print the numerical grade and the letter grade
*/
	double score, score_final, grade;
	score_final = 0;

	for (int i = 1; i <= 4; i++) { /* prompt user for score */
		score = 0;
		printf("enter score %d: ", i);
		scanf("%le", &score);
		if (score < 0) { /* check double is positive */
			printf("ERROR: score must be positive!\n");
			return 0;
		}

		score_final  = score_final + score;
	}
	grade = score_final / 4; /* average of scores */

	/* print numerical grade and letter grade */
	if ((grade >= 90) && (grade <= 100)) {
		printf("Your numerical grade is %.2f and your letter grade A\n", grade);
	} else if ((grade >= 80) && (grade < 90)) {
		printf("Your numerical grade is %.2f and your letter grade B\n", grade);
	} else if ((grade >= 70) && (grade < 80)) {
		printf("Your numerical grade is %.2f and your letter grade C\n", grade);
	} else if ((grade >= 60) && (grade < 70)) {
		printf("Your numerical grade is %.2f and your letter grade D\n", grade);
	} else {
		printf("Your numerical grade is %.2f and your letter grade F\n", grade);
	}
	return 0;
}
