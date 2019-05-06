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

void leap_frog(double *t, double *u, double *v, double h)
{
    double dt;
    double ac1;
    double v1;
    
   // ac1=//-gama*v
    ac1=-2*k;//*u+k*u+sin(omega*t);
    
    
    for(int i=0; i<=2;  i++)
    {
    v1=v[i]-(dt/2)*ac1;;
    }
    
}
int main()
{   
    
double k=2000.0;
double m =1000.0;
//double k=2000.0;
double gama= 0.0;
double omega = 1.0 *pow(k/m,0.5);
double t, u, v, h;
double delta_t, delta_u, delta_v;
  t = 0.0;
  u = 0.0;
  v = 0.0;
  h = 0.01;
  std::cout <<  t << " " <<  u  << " " <<  v << std::endl;
  leap_frog(&t, &u,&v,h);
return 0;
}