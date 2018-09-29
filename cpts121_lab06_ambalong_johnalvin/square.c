#include "grafic.h"

void init(const char **appTitle_pp)
{
    // window title
    *appTitle_pp = "\"grafic\" square demo";
}

void redraw(void)
{
    // 2-element array as coordinates of four corners of the square
    double p0[2], p1[2], p2[2], p3[2];

    p0[0] = -0.5; p0[1] = -0.5;
    p1[0] =  0.5; p1[1] = -0.5;
    p2[0] =  0.5; p2[1] =  0.5;
    p3[0] = -0.5; p3[1] =  0.5;

    // call line() to draw a square
    line(p0, p1);
    line(p1, p2);
    line(p2, p3);
    line(p3, p0);
}
