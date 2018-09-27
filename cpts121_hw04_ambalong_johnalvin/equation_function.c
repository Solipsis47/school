#include <stdio.h>
#include <math.h> // for sqrt()

// defined constants
#define PI 3.14159
#define G 0.0000000000667

// prototypes for 7 equations
double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity_force(double mass1, double mass2, double distance);
double calculate_resistive_divider(double resistance1, double resistance2, double vin);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_general_equation(int a, double x, double z);

int main(void)
{
	// define variables
	float mass, acceleration, radius, height, mass1, mass2, distance, resistance1, resistance2, vin, x1, x2, y1, y2, z, x;
	char equation, plaintext_character, ch;
	int a;

	do {
		// prompt for equation
		printf("\n'N' - Newton's Second Law of Motion\n'V' - Volume of a cylinder\n'C' - Character encoding\n'G' - Gravity formula\n'R' - Resistive divider\n'D' - Distance between two points\n'E' - General Equation\n\nPlease select the equation: ");
		scanf(" %c", &equation);

		// use switch statement for equations
    	// prompt inputs in main()
    	// print result with the argument returned by calling the proper equation function
    	// with the proper parameter inputs passed
		switch (equation) {
			case 'n':
			case 'N':
				mass = 0.0, acceleration = 0.0;
				printf("\nNewton's Second Law of Motion\nEnter mass: ");
				scanf("%f", &mass);
				printf("Enter acceleration: ");
				scanf("%f", &acceleration);

				printf("\nNewton's Second Law of Motion: force = mass * acceleration\n%.2f * %.2f = %.2f\n\n", mass, acceleration, calculate_newtons_2nd_law(mass, acceleration));
			 break;
			case 'v':
	    	case 'V':
			 	radius = 0.0, height = 0.0;
				printf("\nVolume of a cylinder\nEnter radius: ");
				scanf("%f", &radius);
				printf("Enter height: ");
				scanf("%f", &height);

				printf("\nVolume of a cylinder: volume_cylinder = PI * radius * radius * height\nPI * %.2f * %.2f * %.2f = %.2f\n\n", radius, radius, height, calculate_volume_cylinder(radius, height));
			 break;
			case 'c':
	    	case 'C':
				plaintext_character = 0;
				printf("\nCharacter encoding\nEnter character: ");
				scanf(" %c", &plaintext_character);

				printf("\nCharacter encoded: %c\n\n", perform_character_encoding(plaintext_character));
			 break;
			case 'g':
	    	case 'G':
				mass1 = 0.0, mass2 = 0.0, distance = 0.0;
				printf("\nGravity formula\nEnter mass 1: ");
				scanf("%f", &mass1);
				printf("Enter mass 2: ");
				scanf("%f", &mass2);
				printf("Enter distance: ");
				scanf("%f", &distance);

				printf("\nGravity formula: force = G * (( mass1 * mass2) / (distance * distance))\n G * ((%.2f * %.2f) / (%.2f * %.2f)) = %.2f\n\n", mass1, mass2, distance, distance, calculate_gravity_force(mass1, mass2, distance));
			 break;
			case 'r':
	    	case 'R':
				resistance1 = 0.0, resistance2 = 0.0, vin = 0.0;
				printf("\nResistive divider\nEnter resistor value 1: ");
				scanf("%f", &resistance1);
				printf("Enter resistor value 2: ");
				scanf("%f", &resistance2);
				printf("Enter voltage in: ");
				scanf("%f", &vin);

				printf("\nResistive divider: vout = (r2 / (r1 + r2)) * vin = (%.2f / (%.2f + %.2f)) * %.2f = %.2f\n\n", resistance2, resistance1, resistance2, vin, calculate_resistive_divider(resistance1, resistance2, vin));
			 break;
			case 'd':
	    	case 'D':
				x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
				printf("\nDistance between two points\nEnter x1: ");
				scanf("%f", &x1);
				printf("Enter x2: ");
				scanf("%f", &x2);
				printf("Enter y1: ");
				scanf("%f", &y1);
				printf("Enter y2: ");
				scanf("%f", &y2);

				printf("\nDistance between two points: distance = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))) = sqrt (((%.2f - %.2f)*(%.2f - %.2f)) + ((%.2f - %.2f) * (%.2f - %.2f))) = %.2f\n\n", x1, x2, x1, x2, y1, y2, y1, y2, calculate_distance_between_2pts(x1, x2, y1, y2));
			 break;
			case 'e':
	    	case 'E':
				z = 0.0, x = 0.0, a = 0;
				printf("\nGeneral equation:\nEnter z value: ");
				scanf("%f", &z);
				printf("Enter x value: ");
				scanf("%f", &x);
				printf("Enter a value: ");
				scanf("%d", &a);

				printf("\nGeneral equation: y = (89 / 27) - z * x + a / (a %% 2) = (89 / 27) - %.2f * %.2f + %d / (%d %% 2) = %.2f\n\n", z, x, a, a, calculate_general_equation(a, x, z));
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

// def calculate_newtons_2nd_law()
double calculate_newtons_2nd_law(double mass, double acceleration)
{
	double force = 0.0;
	force = mass * acceleration;
	return force;
}

// def calculate_volume_cylinder()
double calculate_volume_cylinder(double radius, double height)
{
	double volume_cylinder = 0.0;
	volume_cylinder = PI * radius * radius * height;
	return volume_cylinder;
}

// def perform_character_encoding()
char perform_character_encoding(char plaintext_character)
{
	char encoded_character = 0;
	encoded_character = (plaintext_character - 'a') + 'A';
	return encoded_character;
}

// def calculate_gravity_force()
double calculate_gravity_force(double mass1, double mass2, double distance)
{
	double force = 0.0;
	force = G * ((mass1 * mass2) / (distance * distance));
	return force;
}

// def calculate_resistive_divider()
double calculate_resistive_divider(double resistance1, double resistance2, double vin)
{
	double vout = 0.0;
	vout = (resistance2 / (resistance1 + resistance2)) * vin;
	return vout;
}

// def calculate_distance_between_2pts
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	double distance = 0.0;
	distance = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	return distance;
}

// def calculate_general_equation
double calculate_general_equation(int a, double x, double z)
{
	double y = 0.0;
	y = ((float) 89 / 27) - z * x + a / (a % 2);
	return y;
}