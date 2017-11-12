#include<iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
int n,n2,n1,i,j,p,k,c;
float a[10][10],hold,mx;



int main ()
{

    cout <<" *** GAUSS ELIMINATION METHOD *** ";
    cout <<endl<< " Enter number of variables to be solved for= ";
    cin>>n;

cout <<endl<<" Input For Augmented Matrix [A|b] :"<<endl;
    for(i=1;i<=n;i++)
    {
    cout <<endl<<" Enter coefficients of "<<i<<" equation :"<<endl;

    for(j=1;j<=n+1;j++)
    {
        cin>>a[i][j];
        cout <<"   ";

    }
    cout<<endl;
    }

cout <<endl<<" Display of Augmented matrix entered : "<<endl;
    for(i=1;i<=n;i++)
    {

    for(j=1;j<=n+1;j++)
    {
        cout<<a[i][j];
        if (j==n)
        {cout <<setw(5)<<"|";}

        cout<<setw(2)<<" ";

    }
    cout <<endl;
    }

cout <<endl<<"Pivoting......"<<endl;

int diag=1;
p=0;
do
{
     mx=a[diag][diag];
 for(i=diag+1;i<=n;i++)
 {
     if(a[i][diag]>mx)
        {mx=a[i][diag];
          p=i;}
 }
 if(p!=0)
{
 for(k=1;k<=n+1;k++)
        {
          hold=a[diag][k];
          a[diag][k]=a[p][k];
          a[p][k]=hold;

        }
}

        diag++;
        p=0;
}while(diag<n);

cout <<endl<<" Display of Pivoted matrix: "<<endl;
    for(i=1;i<=n;i++)
    {

    for(j=1;j<=n+1;j++)
    {
        cout<<a[i][j];
        if (j==n)
        {cout <<setw(5)<<"|";}

        cout<<setw(2)<<" ";

    }
    cout <<endl;
    }


// forward elimination

   diag=1;
    j=2;
elimination:
    do
    {
    float z=a[j][diag]/a[diag][diag];
for(i=1;i<=n+1;i++)
{
    a[j][i]=a[j][i]-(z*a[diag][i]);
}
j++;
}while(j<=n);

diag++;
j=diag+1;

if(diag<=n-1)
goto elimination;


cout <<endl<<endl<<"Matrix  after forward elimination :"<<endl;

 for(i=1;i<=n;i++)
    {

    for(j=1;j<=n+1;j++)
    {
        cout<<a[i][j];
        if (j==n)
        {cout <<setw(5)<<"|";}

        cout<<setw(2)<<" ";

    }
    cout <<endl;
    }


// backward substitution

float x[n];
n2=n-1;

float m;
x[n]=a[n][n+1]/a[n][n];
while(n2>=1)
{
        m=a[n2][n+1];
        n1=n;
        for(c=1;c<=(n-n2);c++)
        {
            m-=(a[n2][n1]*x[n1]);

        n1--;}

        x[n2]=m/a[n2][n2];

        n2--;

      }




cout<<endl<<endl<<" The solution matrix :"<<endl;

for(i=1;i<=n;i++)
{
    cout<<"X["<<i<<"] = "<<x[i]<<endl;
}

cout<<endl<<endl<< "       OVER !!       ";
return 0;
}












