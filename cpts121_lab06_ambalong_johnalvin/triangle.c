#include "grafic.h"

void init(const char **appTitle_pp)
{
    // window title
    *appTitle_pp = "\"grafic\" triangle demo";
}

void triangleDraw(double p0[],double p1[],double p2[])
{
    // call line() to draw a triangle
    line(p0, p1);
    line(p1, p2);
    line(p2, p0);
}


void redraw(void)
{
    // 2-element array as coordinates of three corners of the square
    double p0[2], p1[2], p2[2];

    p0[0] = -0.5; p0[1] = 0;
    p1[0] = 0; p1[1] = 1;
    p2[0] = 0.5; p2[1] = 0;

    // call triangleDraw() and pass the coordinates
    triangleDraw(p0,p1,p2);
 
}