#include <iostream>
#include <math>
using namespace std;

int main ()
{

    cout <<" *** GAUSS SEIDAL METHOD *** ";
    cout <<endl<< " Enter number of variables to be solved for= ";
    cin>>n;

cout <<endl<<" Input For Coefficient Matrix [A] :"<<endl;
    for(i=1;i<=n;i++)
    {
    cout <<endl<<" Enter coefficients of "<<i<<" equation :"<<endl;

    for(j=1;j<=n;j++)
    {
        cin>>a[i][j];
        cout <<"   ";

    }
    cout<<endl;
    }

cout<<endl<<"Input B matrix :"<<endl;
for(i=1;i<=n;i++)
{
    cin>>b[i];
    cout<<endl;
}

// D matrix
 for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
        if(j==i)
        d[i][j]=a[i][j];
        else
            d[i][j]=0;

    }
    cout<<endl;
    }

//L matrix

for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
        if(i>j)
        l[i][j]=a[i][j];
        else
            l[i][j]=0;

    }
    cout<<endl;
    }

// U matrix

for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
        if(j>i)
        u[i][j]=a[i][j];
        else
            u[i][j]=0;

    }
    cout<<endl;
    }


