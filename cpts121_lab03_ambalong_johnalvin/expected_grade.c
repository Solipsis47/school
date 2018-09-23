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
* 1. Prompt the user to enter the three double values and the final 
*    letter grade(score1, score2, score3, final_score_letter)
.
* 2. Check to make sure the double is positive and the letter is 
*    correct. If it isn't, printout an error message and exit.
* 3. Implement this pseudocode:
*    calculate the minimum numerical value for the final_score_letter
*      use the formula to calculate the fourth score
* 
*        score4 = 4*final_score-score1-score2-score3
*	print the numerical grade for score4
*/
	double score, score4, grade, score_123;
	char letter;
	score_123 = 0;

	for (int i = 1; i <= 3; i++) { /* prompt user for score */
		score = 0;
		printf("enter score %d: ", i);
		scanf("%le", &score);
		if (score < 0) { /* check double is positive */
			printf("ERROR: score must be positive!\n");
			return 0;
		}

		score_123  = score_123 + score;
	}
	printf("enter letter : ");
        scanf(" %c", &letter);

	switch (letter) {
		case 'a':
		case 'A':
			 grade = 90;
		 break;
 		case 'b':
                case 'B':
                        grade = 80;
                 break;
 		case 'c':
                case 'C':
                        grade  = 70;
                 break;
		case 'd':
                case 'D':
                        grade = 60;
                 break;
		case 'f':
                case 'F':
                        grade = 0;
                 break;

		default: /* anything but 'a' , 'b' , 'c' , 'd' , 'f' */
		 printf ("Unrecognized letter grade.\n");
		 return 0;
		 }
	score4 = 4 * grade - score_123;
	printf("The minimum numerical grade for the fourth score to get a final grade %c is %.2f.\n", letter, score4);

	return 0;
}
