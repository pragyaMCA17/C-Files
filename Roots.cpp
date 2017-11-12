#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main ()
{
    float a,b,c,r1,d,r2;
        char ans;
    cout<<"***ROOTS OF QUADRATIC EQUATIONS***"<<endl;
    do
    {
    cout<<endl<<" Enter coefficient of X^2 = ";
    cin>>a;
    cout<<endl<<" Enter coefficient of X^1 = ";
    cin>>b;
    cout<<endl<<" Enter coefficient of X^0 = ";
    cin>>c;

    cout<<endl<<endl<<" EQUATION : "<<a<<"X^2 + "<<b<<"X^1 + "<<c<<endl<<endl;

    d= (b*b)-4*a*c;
    if(d>0)
    {
        cout<<"Roots are real and distinct !!"<<endl;
        r1=(-b+sqrt(d))/2*a;
        r2=(-b-sqrt(d))/2*a;
        cout<<endl<<"Root 1 = "<<r1<<endl<<"Root 2 = "<<r2<<endl;

    }

    else if(d==0)
    {

        cout<<"Roots are real and equal !!"<<endl;
        r1=(-b+sqrt(d))/2*a;
        cout<<endl<<"Root 1 = "<<r1<<endl<<"Root 2 = "<<-r1<<endl;
    }

    else
    {
        cout<<"Roots are imaginary and distinct !!"<<endl;
    r1=-b/2*a;
    cout<<endl<<"Root 1 = "<<r1<<"+ i"<<sqrt(-d)/2*a<<endl<<"Root 2 = "<<r1<<"- i"<<sqrt(-d)/2*a<<endl;
    }

    cout<<endl<<endl<<" continue(y/n)..";
    cin>>ans;
}while(ans=='y');
    return 0;
}





