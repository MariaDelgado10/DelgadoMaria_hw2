#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;



double m =1000.0;
double k=2000.0;
double gama= 0.0;
double w = 1.0 *pow(k/m,0.5);
double f(double t );
double tf=45.0; //tiempo que dura el temblor
int n=100;

void leap_frog(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3);

double f(double t)
{
    return sin(w*t);
}

void leap_frog(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3)
{
    double t_in, dt_in, unuevo_1, unuevo_2, unuevo_3;
    t_in = *t;
    dt_in = *dt;
    unuevo_1 = *unuevo1;
    unuevo_2 = *unuevo2;
    unuevo_3 = *unuevo3;
        
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-(dt_in/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*t_in))/m);
       vviejo2=vviejo2-(dt_in/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-(dt_in/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+dt_in*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*t_in))/m);
       vnuevo2=vviejo2+dt_in*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+dt_in*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       unuevo_1=uviejo1+vnuevo1*dt_in;  
       unuevo_2=uviejo2+vnuevo2*dt_in; 
       unuevo_3=uviejo3+vnuevo3*dt_in; 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       t_in=t_in+dt_in; 
      //std::cout<<unuevo1<< unuevo2<<unueva3<<t <<std::endl;
    }
  
  
     srand((unsigned int)time(NULL));

    float w1 = 0.2*pow(k/m,0.5);
    float w2 = 3.0*pow(k/m,0.5);
    for (int i=0;i<100;i++)
    {
       printf("%f\n", w1+((float)rand()/(float)(RAND_MAX)) * w2);
    }
    
   *t = t_in;
   *dt = dt_in;
   *unuevo1 = unuevo_1;
   *unuevo2 = unuevo_2;
   *unuevo3 = unuevo_3;
}
int main()
{   
    
double t, dt,unuevo1,unuevo2,unuevo3;

  t= 0.0;
  dt= 0.1;
  unuevo1=0.0;
  unuevo2=0.0;
  unuevo3=0.0;
//v = 0.0;
    while(t<tf)
    {//h = 0.01;
      cout<<unuevo1<<" "<< unuevo2<< " " <<unuevo3<< " " <<t <<endl;
      leap_frog(&t, &dt, &unuevo1, &unuevo2, &unuevo3);
    }
return 0;
}