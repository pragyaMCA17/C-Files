#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
float a1,b1,m, m1,c,d,f,j,coffar[10];
int n,p,i,order,s=0;
float func(float z)
{
    float fn=coffar[0];
  for(i=1;i<=order; i++)
   { fn+=coffar[i]*pow(z,i); }
   return fn;

}
int check( float a, float b)
{
    a1= func(a);
    b1= func(b);
    if((a1*b1)<0)
     return 1;
    else
     return 0;
}
int main()
{
  float e=0.0001;
  cout<<endl<<"**** BISECTION METHOD ****"<<endl;
   cout<<endl<<"Input the order of the equation : ";
   cin>>order;

   cout<<endl<<"write the coefficients :";
   for(i=0;i<=order;i++)
{
    cout<<endl<<"coefficient of x^"<<i<<"= ";
    cin>>coffar[i];
}
    start:
    cout<<endl<<"Enter the initial value of the range :"<<endl;
    cin>>c;
    cout<<"Enter the final value of the range :"<<endl;
    cin>>d;

p=check(c,d);
    if (p==1)
    {

    j=fabs(c-d);
    n=((log10(j/e))/0.3010);

    while(s<=n)
    {
        m=(c+d)/2;
    m1=func(m);
        if(m1*a1<0)
            d=m;
        else if(m1*b1<0)
        c=m;
            s++;

    }
    }
    else
    {
        cout<<endl<<endl<<"WRONG GUESSES!!"<<endl;
        goto start;
        }

        cout<<endl<<endl<<"The Value of root is = "<<m;

}


