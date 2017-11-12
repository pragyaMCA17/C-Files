#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int i,n,k,order;
float a,b,h,c[20],val,derval,y,e;
float func(float x)
{
  float fn=c[0];
  for(i=1;i<=order;i++)
   { fn+=c[i]*pow(x,i); }
   return fn;

}

float dobder(float m)
{     float s=0;
    for(i=2;i<=order; i++)
   { s+=i*(i-1)*c[i]*pow(m,i-2); }
   return s;
}
int main()
{

    cout<<" ****Trapezoidal Rule **** "<<endl;
    cout<<" Enter the order of polynomial function : ";
    cin>>order;

    cout<<endl<<"write the coefficients : ";
   for(i=0;i<=order;i++)
{
    cout<<endl<<"coefficient of x^"<<i<<"=";
    cin>>c[i];
}

     cout<<" Enter Upper limit : "<<endl;
    cin>>b;
    cout<<" Enter Lower Limit : "<<endl;
    cin>>a;
    cout<<" Enter h: "<<endl;
    cin>>h;
    n=(b-a)/h;

    cout<<" Integrating..."<<endl;

    val=func(a)+func(b);
    for(k=1;k<n;k++)
    {
        y=a+(k*h);
        val+=(2*(func(y)));
    }

cout <<endl<<val;
    cout<<endl<<" I of f(x) = " <<0.5*(h*val);


    e=0,y=0,derval=0;
    for(i=0;i<n;i++)
    {
        y=a+i*h;
        derval+=dobder(y);

    }

    cout<<endl<<" Error In estimation = "<<setprecision(2)<<(((h*h*h)/12)*derval);
    cout<<endl<<endl<<"***Over***";

    return 0;

}
