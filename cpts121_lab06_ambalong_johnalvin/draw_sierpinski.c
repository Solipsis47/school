#include "grafic.h"


void init(const char **appTitle_pp)
{
    // window title
    *appTitle_pp = "\"grafic\" sierpinski demo";
}


void triangleDraw(double p0[],double p1[],double p2[])
{
    // call line() to draw a triangle
    line(p0, p1);
    line(p1, p2);
    line(p2, p0);
}

/*
* this function finds the midpoint of a line in the triangle and uses the new "coordinates" 
* to draw three triangles within a triangle then repeats for the new triangles using a recursive function
*/
void fractal_triangle(double p0[], double p1[], double p2[], int i)
{
    double auxp0[2], auxp1[2], auxp2[2];

    // if else statement to stop the recursive function
    if(i>10){
        triangleDraw(p0,p1,p2);

    } else {

        // assign the average of two "x,y" points
        auxp0[0] = (p1[0]+ p0[0])*0.5; auxp0[1] = (p1[1]+ p0[1])*0.5;
        auxp1[0] = (p2[0]+ p1[0])*0.5; auxp1[1] = (p2[1]+ p1[1])*0.5;
        auxp2[0] = (p0[0]+ p2[0])*0.5; auxp2[1] = (p0[1]+ p2[1])*0.5;
 
        // draws the three triangle and increment the counter
        fractal_triangle(auxp0,p0,auxp2,i+1);
        fractal_triangle(p1,auxp0,auxp1,i+1);
        fractal_triangle(auxp1,auxp2,p2,i+1);
    }
}

void redraw(void)
{
    double p0[2], p1[2], p2[2];

    // the outer triangle coordinates
    p0[0] = -0.5; p0[1] = 0;
    p1[0] = 0; p1[1] = 1;
    p2[0] = 0.5; p2[1] = 0;

    fractal_triangle(p0,p1,p2,0);

}
