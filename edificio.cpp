#include<iostream>
#include<cmath>


double m =1000.0;
double k=2000.0;
double gama= 0.0;
double omega = 1.0 *pow(k/m,0.5);
double f(double t );
void leap_frog(double *t, double *x, double *v, double h);

double f(double t)
{
    return sin(omega*t);
}
//double F=sin(omega*t)

void leap_frog(double *t, double *x, double *v, double h)
{
    
}
int main()
{
    
return 0;
}