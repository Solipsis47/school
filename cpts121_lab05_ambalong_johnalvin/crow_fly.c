#include <stdio.h>
#include <math.h> // for M_PI and trig functions

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

int main(void)
{	
	double latitude0[3], longitude0[3];
	double latitude1[3], longitude1[3];
	
	printf(" from latitude (d m s): ");
	scanf("%lf %lf %lf", &latitude0[0], &latitude0[1], &latitude0[2]);
	printf("from longitude (d m s): ");
	scanf("%lf %lf %lf", &longitude0[0], &longitude0[1], &longitude0[2]);
	
	printf("to latitude (d m s): ");
	scanf("%lf %lf %lf", &latitude1[0], &latitude1[1], &latitude1[2]);
	printf("  to longitude (d m s): ");
	scanf("%lf %lf %lf", &longitude1[0], &longitude1[1], &longitude1[2]);
	
	printf("distance: %.1f km\n", crowFly(latitude0, longitude0, latitude1, longitude1));

	return 0;
}

double dmsToRadians(double dms[3])
{
	double resultRadians = 0.0;
	double resultDegrees = 0.0;

	resultDegrees = dms[0] + (dms[1] / 60) + (dms[2] / 3600);
	resultRadians = resultDegrees * M_PI / 180;

	return resultRadians;
}

void polarToCartesian(double latitude[3], double longitude[3], double position[3])
{
	double theta = 0.0, phi = 0.0;

	theta = dmsToRadians(latitude);
	phi = dmsToRadians(longitude);
	position[0] = cos(theta) * cos(phi);
	position[1] = cos(theta) * sin(phi);
	position[2] = sin(theta);
}

double arcLength(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
	double resultAngle = 0.0;
	double position0[3], position1[3];

	polarToCartesian(latitude0, longitude0, position0);
	polarToCartesian(latitude1, longitude1, position1);

	resultAngle = acos((position0[0] * position1[0]) + (position0[1] * position1[1]) + (position0[2] * position1[2]));

	return resultAngle;
}

double crowFly(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
	double resultDistance = 0.0;
	double arc = 0.0;

	arc = arcLength(latitude0, longitude0, latitude1, longitude1);
	resultDistance = arc * 6378;

	return resultDistance;
}

