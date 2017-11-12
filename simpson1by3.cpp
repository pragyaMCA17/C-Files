
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int i,n,order,k;
float a,b,h,c[20],val,y,e;
float func(float x)
{
  float fn=c[0];
  for(i=1;i<=order;i++)
   { fn+=c[i]*pow(x,i); }

   return fn;

}

int main()
{

    cout<<" ****Simpson 1/3  Rule **** "<<endl;
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


    cout<<endl<<" Integrating..."<<endl;

    val=func(a)+func(b);
    for(k=1;k<=n-1;k=k+2)
    {
        y=a+(k*h);
        val+= (4*(func(y)));

    }

     y=0;
     for(k=2;k<=n-2;k=k+2)
    {
        y=a+(k*h);
        val+= (2*(func(y)));
    }



    cout<<endl<<" I of f(x) = " <<(h*val)/3;
    cout<<endl<<endl<<"***Over***";

    return 0;

}
