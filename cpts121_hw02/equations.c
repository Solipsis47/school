#include <stdio.h>
#include <math.h>

// define constants
#define PI 3.14159
#define G 0.0000000000667

int main (void)
{
	// define variables
	float mass, accel, radius, height, mass1, mass2, distance, r1, r2, vin, x1, x2, y1, y2, z, x;
	double force, volume_cylinder, vout, y;
	char equation, encoded_character, plaintext_character, ch;
	int a;
do {
	printf("'N' - Newton's Second Law of Motion\n'V' - Volume of a cylinder\n'C' - Character encoding\n'G' - Gravity formula\n'R' - Resistive divider\n'D' - Distance between two points\n'E' - General Equation\nPlease select the equation: ");
	scanf(" %c", &equation);
	// prompt for which equation to use
	// use switch statement
	// initialize variables when needed
	switch (equation) {
		case 'n':
		case 'N':
			mass = 0.0, accel = 0.0, force = 0.0;
			printf("Newton's Second Law of Motion\nEnter mass: ");
			scanf("%f", &mass);
			printf("Enter acceleration: ");
			scanf("%f", &accel);

			force =  mass * accel;

			printf("Newton's Second Law of Motion: force = mass * acceleration\n%f * %f = %f\n", mass, accel, force);
		 break;
		case 'v':
                case 'V':
		 	radius = 0.0, height = 0.0, volume_cylinder = 0.0;
			printf("Volume of a cylinder\nEnter radius: ");
			scanf("%f", &radius);
			printf("Enter height: ");
			scanf("%f", &height);

			volume_cylinder = PI * (float) radius * (float) radius * (float) height;

			printf("Volume of a cylinder: volume_cylinder = PI * radius * radius * height\nPI * %f * %f * %f = %f\n", radius, radius, height, volume_cylinder);
		 break;
		case 'c':
                case 'C':
			encoded_character = 0, plaintext_character = 0;
			printf("Character encoding\nEnter character: ");
			scanf(" %c", &plaintext_character);

			encoded_character = (plaintext_character - 'a') + 'A';

			printf("Character encoded: %c\n", encoded_character);
		 break;
		case 'g':
                case 'G':
			mass1 = 0.0, mass2 = 0.0, distance = 0.0, force = 0.0;
			printf("Gravity formula\nEnter mass 1: ");
			scanf("%f", &mass1);
			printf("Enter mass 2: ");
			scanf("%f", &mass2);
			printf("Enter distance: ");
			scanf("%f", &distance);

			force = G * (((float) mass1 * (float) mass2) / ((float) distance * (float) distance));

			printf("Gravity formula: force = G * (( mass1 * mass2) / (distance * distance))\n G * ((%f * %f) / (%f * %f)) = %f\n", mass1, mass2, distance, distance, force);
		 break;
		case 'r':
                case 'R':
			r1 = 0.0, r2 = 0.0, vin = 0.0, vout = 0.0;
			printf("Resistive divider\nEnter resistor value 1: ");
			scanf("%f", &r1);
			printf("Enter resistor value 2: ");
			scanf("%f", &r2);
			printf("Enter voltage in: ");
			scanf("%f", &vin);

			vout = ((float) r2 / ((float) r1 + (float) r2)) * (float) vin;

			printf("Resistive divider: vout = (r2 / (r1 + r2)) * vin = (%f / (%f + %f)) * %f\n", r2, r1, r2, vout);
		 break;
		case 'd':
                case 'D':
			x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;
			printf("Distance between two points\nEnter x1: ");
			scanf("%f", &x1);
			printf("Enter x2: ");
			scanf("%f", &x2);
			printf("Enter y1: ");
			scanf("%f", &y1);
			printf("Enter y2: ");
			scanf("%f", &y2);

			distance = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

			printf("Distance between two points: distance = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))) = sqrt (((%f - %f)*(%f - %f)) + ((%f - %f) * (%f - %f))) = %f\n", x1, x2, x1, x2, y1, y2, y1, y2, distance);
		 break;
		case 'e':
                case 'E':
			z = 0.0, x = 0.0, a = 0, y = 0.0;
			printf("General equation:\nEnter z value: ");
			scanf("%f", &z);
			printf("Enter x value: ");
			scanf("%f", &x);
			printf("Enter a value: ");
			scanf("%d", &a);

			y = ((float) 89 / 27) - z * x + a / (a % 2);

			printf("General equation: y = (89 / 27) - z * x + a / (a %% 2) = (89 / 27) - %f * %f + %d / (a %% 2) = %f\n", z, x, a, y);
		 break;
		default:
		 printf("ERROR: Please choose a valid equation\n");
		 return 0; }
	printf("Please enter 'C' to continue or 'S' to stop\n");
	scanf(" %c", &ch);
	// prompts to continue or to stop
} while (ch == 'c' || ch == 'C');
	return 0;
}
