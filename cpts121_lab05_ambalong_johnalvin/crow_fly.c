#include <stdio.h>
#include <math.h> // for M_PI and trig functions

// Proto dmsToRadians()
double dmsToRadians(double dms[3]);
/*
* converts the values in the 3-element array `dms` (degrees,
* minutes, and seconds) to a single double value in radians and
* returns it
*
* pseudocode:
*     convert dms[] into a single (fractional) degree value
*     convert the degree value to radians and return that value
*/

// Proto polarToCartesian()
void polarToCartesian(double latitude[3], double longitude[3], double position[3]);
/*
* converts `latitude` and `longitude` (both are 3-element --
* degrees, minutes, and seconds -- arrays) to `position`: a
* 3-element double array in Cartesian (x, y, and z) coordinates
* on the unit sphere.
*
* pseudocode:
*     convert latitude to a polar angle `theta` using
*    dmsToRadians()
*     convert longitude to an azimuthal angle `phi` using
*       dmsToRadians()
*     convert `theta` and `phi` to the x, y, and z components of
*       `position`
*/

// Proto arcLength()
double arcLength(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3]);
/*
* computes the length (in radians) of an arc ("geodesic") on the
* unit sphere between points (longitude0, latitude0) and
* (longitude1, latitude1)
*
* pseudocode:
*     convert `latitude0` and `longitude0` to `position0`
*       using polarToCartesian()
*     convert `latitude1` and `longitude1` to `position1`
*       using polarToCartesian()
*     compute the cosine of the arc using the formula below
*     use the acos() (arc cosine) math function to convert the
*       cosine back to an angle and return it
*/

// Proto crowFly()
double crowFly(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3]);
/*
* computes and returns the distance in km from (latitude0,
* longitude0) to (latitude1, longitude1) on the Earth's surface
*
* pseudocode:
*     compute the arc length from (latitude0, longitude0) to
*       (latitude1, longitude1) using arcLength()
*   multiply the arc length by the radius of the Earth (6378 km)
*       and return that value
*/

// Def main()
int main(void)
{
	// Init latitude0, longitude0, latitude1, longitude1
	double latitude0[3], longitude0[3];
	double latitude1[3], longitude1[3];

	// Prompt latitude0, longitude0
	printf(" from latitude (d m s): ");
	scanf("%lf %lf %lf", &latitude0[0], &latitude0[1], &latitude0[2]);
	printf("from longitude (d m s): ");
	scanf("%lf %lf %lf", &longitude0[0], &longitude0[1], &longitude0[2]);
	// Prompt latitude1, longitude1
	printf("to latitude (d m s): ");
	scanf("%lf %lf %lf", &latitude1[0], &latitude1[1], &latitude1[2]);
	printf("  to longitude (d m s): ");
	scanf("%lf %lf %lf", &longitude1[0], &longitude1[1], &longitude1[2]);

	// Print result; argument is the value returned by calling crowFly with
	// latitude0, longitude0, latitude1, longitude1 passed
	printf("distance: %.1f km\n", crowFly(latitude0, longitude0, latitude1, longitude1));

	// Exit program
	return 0;
}

// Def dmsToRadians()
double dmsToRadians(double dms[3])
{
	// Init resultRadians, resultDegrees
	double resultRadians = 0.0;
	double resultDegrees = 0.0;

	// Assign resultRadians, resultDegrees
	resultDegrees = dms[0] + (dms[1] / 60) + (dms[2] / 3600);
	resultRadians = resultDegrees * M_PI / 180;

	// Return resultRadians
	return resultRadians;
}

// Def polarToCartesian()
void polarToCartesian(double latitude[3], double longitude[3], double position[3])
{
	// Init theta, phi
	double theta = 0.0, phi = 0.0;

	// Assign theta, phi; by calling dmsToRadians
	theta = dmsToRadians(latitude);
	phi = dmsToRadians(longitude);
	// Assign position
	position[0] = cos(theta) * cos(phi);
	position[1] = cos(theta) * sin(phi);
	position[2] = sin(theta);
}

// Def for arcLength()
double arcLength(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
	// Init resultAngle, position0, position1
	double resultAngle = 0.0;
	double position0[3], position1[3];

	// Call polarToCartesian, parameters are passed
	polarToCartesian(latitude0, longitude0, position0);
	polarToCartesian(latitude1, longitude1, position1);

	// Assign resultAngle
	resultAngle = acos((position0[0] * position1[0]) + (position0[1] * position1[1]) + (position0[2] * position1[2]));

	// Return resultAngle
	return resultAngle;
}

// Def crowFly()
double crowFly(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
	// Init resultDistance
	double resultDistance = 0.0;
	double arc = 0.0;

	// Assign arc, by calling arcLength; Assign resultDistance
	arc = arcLength(latitude0, longitude0, latitude1, longitude1);
	resultDistance = arc * 6378;

	// Return resultDistance
	return resultDistance;
}
