#include <stdio.h>
#define G 9.8
int main(void)
{
	int time = 0;
	double distance = 0.0;

	printf("Enter the seconds the ball is falling as integer: ");
	scanf("%d", &time);

	distance = ((double) 1 / 2) * G * time *time;

	printf("Distance of the ball drop within %d seconds is %.1f.\n", time, distance);

	return 0;
}
