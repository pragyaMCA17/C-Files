
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float c[100],a0,a1,a2num,a2deno,a2,a3,p;
int order,i,s=0;

float fn(float x)
{
  float func=c[0];
  for(i=1;i<=order; i++)
   { func+=c[i]*pow(x,i); }
   return func;
}

int main()
{
    cout<<"*** Roots of a given equation using Secant method ***"<<endl<<endl;
    float e,mod;
    cout<<"Enter the specified accuracy : ";
    cin>>e;

   cout<<endl<<"Input the order of the equation : ";
   cin>>order;

   cout<<endl<<"write the coefficients : ";
   for(i=0;i<=order;i++)
{
    cout<<endl<<"coefficient of x^"<<i<<"=";
    cin>>c[i];
}

   cout<<endl<<endl<<"Enter initial approximation I: ";
   cin >>a0;
   cout<<endl<<"Enter initial approximation II: ";
   cin>>a1;

    a2num = (a0*fn(a1))-(a1*fn(a0));
    a2deno=(fn(a1)-fn(a0));
    a2=a2num/a2deno;




do{
    a3= ((a1*fn(a2))-(a2*fn(a1)))/(fn(a2)-fn(a1));
    mod = fabs(a3-a2);
     a1=a2;
     a2=a3;

}while(mod>=e);

cout.ios::fixed;
   cout<<endl<<endl<<"The root is : "<<setprecision(4)<<a3;

   return 0;

}

