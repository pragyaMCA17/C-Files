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

    cout<<" ****Simpson 3/8  Rule **** "<<endl;
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
    for(k=1;k<=n-1;k++)
    {
         y=a+(k*h);
        if(k%3==0)
        {
            val+=(2*(func(y)));
        }
        else
        val+=(3*(func(y)));

    }

    cout<<endl<<" I of f(x) = " <<0.38*(h*val);
    cout<<endl<<endl<<"***Over***";

    return 0;

}
