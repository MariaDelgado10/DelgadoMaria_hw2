#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include <fstream>
using namespace std;



double m =1000.0;
double k=2000.0;
double gama= 0.0;
double w = 1.0 *pow(k/m,0.5);
double f(double t );
double tf=45.0; //tiempo que dura el temblor
int n=100;

void leap_frog(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3);
void caso1(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w);
void caso2(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w);
void caso3(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w);
void caso4(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w);
double f(double t)
{
    return sin(w*t);
}

void leap_frog(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3)
{
    //double t_in, dt_in, unuevo_1, unuevo_2, unuevo_3;
    //t_in = *t;
    //dt_in = *dt;
    //unuevo_1 = *unuevo1;
    //unuevo_2 = *unuevo2;
    //unuevo_3 = *unuevo3;
        
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    ofstream myfile;
    myfile.open("edificio.dat");
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       *unuevo1=uviejo1+vnuevo1*(*dt);  
       *unuevo2=uviejo2+vnuevo2*(*dt); 
       *unuevo3=uviejo3+vnuevo3*(*dt); 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       *t=(*t)+(*dt); 
      myfile<<*unuevo1<<" "<< *unuevo2<<" "<<*unuevo3<<" "<<*t << " " <<std::endl;
      //std::cout<<"ssss"<<*unuevo1<< *unuevo2<<*unuevo3<<t_in <<std::endl;
    }
myfile.close();
  
  
     srand((unsigned int)time(NULL));

ofstream myfile2;
myfile2.open("omegasyumax.dat");
float w1 = 0.2*pow(k/m,0.5);
float w2 = 3.0*pow(k/m,0.5);
int c=100;    
double delta=w2-w1/c-1;
    
float omega[100];
double u_maxi[100];
double u_maxi2[100];
double u_maxi3[100];
for (int i=0;i<c;i++)
{
 omega[i]= (w1+delta);
 
      // myfile2<<omega[i]<<std::endl;
int max=0;
//int j=0;

for(int j=0; j<10000; j++)
{
if(j%100==0)
{
max=max+j;
}
vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
*unuevo1=uviejo1+vnuevo1*(*dt);  
if(*unuevo1>u_maxi[max])
{
u_maxi[max]=(*unuevo1);
}
else
{
u_maxi[max]=uviejo1;
}
vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
*unuevo2=uviejo2+vnuevo2*(*dt); 
if(*unuevo2>u_maxi2[max])
{
u_maxi2[max]=(*unuevo2);
}
else
{
u_maxi2[max]=uviejo2;
}
vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
*unuevo3=uviejo3+vnuevo3*(*dt); 
if(*unuevo3>u_maxi3[max])
{
u_maxi3[max]=(*unuevo3);
}
else
{
u_maxi3[max]=uviejo3;
}
myfile2<<u_maxi<<" "<< u_maxi2<<" "<<u_maxi3<<" " <<omega <<std::endl;
}
}    
myfile2.close();

}


void caso1(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w)
{
      
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    ofstream myfilec1;
    myfilec1.open("caso1.dat");
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       *unuevo1=uviejo1+vnuevo1*(*dt);  
       *unuevo2=uviejo2+vnuevo2*(*dt); 
       *unuevo3=uviejo3+vnuevo3*(*dt); 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       *t=(*t)+(*dt); 
      myfilec1<<*unuevo1<<" "<< *unuevo2<<" "<<*unuevo3<<" "<<*t << " " <<w<<std::endl;
      //std::cout<<"ssss"<<*unuevo1<< *unuevo2<<*unuevo3<<t_in <<std::endl;
    }
myfilec1.close();
     
    
}    

void caso2(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w)
{
      
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    ofstream myfilec2;
    myfilec2.open("caso2.dat");
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       *unuevo1=uviejo1+vnuevo1*(*dt);  
       *unuevo2=uviejo2+vnuevo2*(*dt); 
       *unuevo3=uviejo3+vnuevo3*(*dt); 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       *t=(*t)+(*dt); 
      myfilec2<<*unuevo1<<" "<< *unuevo2<<" "<<*unuevo3<<" "<<*t << " " <<w<<std::endl;
      //std::cout<<"ssss"<<*unuevo1<< *unuevo2<<*unuevo3<<t_in <<std::endl;
    }
myfilec2.close();
     
    
}  


void caso3(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w)
{
      
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    ofstream myfilec3;
    myfilec3.open("caso3.dat");
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       *unuevo1=uviejo1+vnuevo1*(*dt);  
       *unuevo2=uviejo2+vnuevo2*(*dt); 
       *unuevo3=uviejo3+vnuevo3*(*dt); 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       *t=(*t)+(*dt); 
      myfilec3<<*unuevo1<<" "<< *unuevo2<<" "<<*unuevo3<<" "<<*t << " " <<w<<std::endl;
      //std::cout<<"ssss"<<*unuevo1<< *unuevo2<<*unuevo3<<t_in <<std::endl;
    }
myfilec3.close();
     
    
} 


void caso4(double *t, double *dt, double *unuevo1, double *unuevo2, double *unuevo3, double w)
{
      
 
    double uviejo1;
    double uviejo2;
    double uviejo3;
    double vviejo1;
    double vviejo2;
    double vviejo3;
    
    double vnuevo1=0.0;
    double vnuevo2=0.0;
    double vnuevo3=0.0;

    ofstream myfilec4;
    myfilec4.open("caso4.dat");
    
    for(int i=1; i<=n; i++)
    {
       vviejo1=vviejo1-((*dt)/2)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vviejo2=vviejo2-((*dt)/2)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vviejo3=vviejo3-((*dt)/2)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       vnuevo1=vviejo1+(*dt)*((-gama*vviejo1-2*k*uviejo1+k*uviejo2+sin(w*(*t)))/m);
       vnuevo2=vviejo2+(*dt)*((-gama*vviejo2+k*uviejo1-2*k*uviejo2+k*uviejo3)/m);
       vnuevo3=vviejo3+(*dt)*((-gama*vviejo3+k*uviejo2-k*uviejo3)/m);
       *unuevo1=uviejo1+vnuevo1*(*dt);  
       *unuevo2=uviejo2+vnuevo2*(*dt); 
       *unuevo3=uviejo3+vnuevo3*(*dt); 
        
        
       vviejo1=vnuevo1;
       vviejo2=vnuevo2;
       vviejo3=vnuevo3;
       *t=(*t)+(*dt); 
      myfilec4<<*unuevo1<<" "<< *unuevo2<<" "<<*unuevo3<<" "<<*t << " " <<w<<std::endl;
      //std::cout<<"ssss"<<*unuevo1<< *unuevo2<<*unuevo3<<t_in <<std::endl;
    }
myfilec4.close();
     
    
} 


int main()
{   
    
double t, dt,unuevo1,unuevo2,unuevo3, w1,w2,w3,w4;

  t= 0.0;
  dt= 0.1;
  unuevo1=0.0;
  unuevo2=0.0;
  unuevo3=0.0;
  w1= 0.5*pow(k/m,0.5);
  w2= 1.0*pow(k/m,0.5);
  w3= 1.5*pow(k/m,0.5);
  w4= 2.5*pow(k/m,0.5);  
//v = 0.0;

    while(t<tf)
    {//h = 0.01;
      //cout<<unuevo1<<" "<< unuevo2<< " " <<unuevo3<< " " <<t <<endl;
      leap_frog(&t, &dt, &unuevo1, &unuevo2, &unuevo3);
      caso1(&t, &dt, &unuevo1, &unuevo2, &unuevo3, w1);
      caso2(&t, &dt, &unuevo1, &unuevo2, &unuevo3, w2); 
      caso3(&t, &dt, &unuevo1, &unuevo2, &unuevo3, w3); 
      caso4(&t, &dt, &unuevo1, &unuevo2, &unuevo3, w4);   
    }



return 0;
}
