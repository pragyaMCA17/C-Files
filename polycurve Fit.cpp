#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

main()
{
    float hold,mx;

    int n,n1,n2,n3,c,i,j,order,p,diag,k;

    cout<<"TO FIT CURVE USING GIVEN SET OF DATA VALUES"<<endl;
    cout<<endl<<"Enter the order of polynomial curve to fit : ";
    cin>>order;
    cout<<endl<<"Enter the number of data values";
    cin>>n;

    float x[n],y[n],sumX[(2*order)+1],sumXY[order+1],a[order+1][order+2],sol[order+1];

    cout<<endl<<"Enter values of x :"<<endl;

    for(i=1;i<=n;i++)
    {
        cout<<"x"<<i<<"= ";
        cin>>x[i];
        cout<<endl;
        }

    cout<<"-----Values Of X entered-----"<<endl;
     sumX[0]=n;

      for(k=1;k<=(2*order);k++)
        {
        for(i=1;i<=n;i++)
        {
        sumX[k]+=(pow(x[i],k));
        }
        }
        cout<<endl<<sumX[2*order];
       cout<<endl<<"Enter values of y :"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"y"<<i<<"= ";
        cin>>y[i];
        cout<<endl;

    }

    cout<<"-----Values Of Y entered------"<<endl;
     for(k=1;k<=(order+1);k++)
        {

             for(i=1;i<=n;i++)
        {
        sumXY[k]+=((pow(x[i],(k-1)))*y[i]);
        }
        }

    cout<<endl;
    int h;
    cout<<" Coefficient matrix formed : "<<endl;
    for(i=1;i<=order+1;i++)
    {
          h=i-1;
    for(j=1;j<=order+2;j++)
    {
        if(j!=(order+2))
        {a[i][j]=sumX[h];
        h++;}

        else
        {
            a[i][j]=sumXY[i];
        }
    }

    }

    for(i=1;i<=(order+1);i++)
    {

    for(j=1;j<=(order+2);j++)
    {
        cout<<a[i][j];
        if (j==n)
        {cout <<setw(5)<<"|";}

        cout<<setw(2)<<" ";

    }
    cout <<endl;
    }

   //pivoting..
    diag=1;
    p=0;
    k=0;
do
{
     mx=a[diag][diag];
 for(i=diag+1;i<=(order+1);i++)
 {
     if(a[i][diag]>mx)
        {mx=a[i][diag];
          p=i;}
 }
 if(p!=0)
{
 for(k=1;k<=(order+2);k++)
        {
          hold=a[diag][k];
          a[diag][k]=a[p][k];
          a[p][k]=hold;

        }
}

        diag++;
        p=0;
}while(diag<=order);

/*cout <<endl<<" Display of Pivoted matrix: "<<endl;
    for(i=1;i<=(order+1);i++)
    {

    for(j=1;j<=(order+2);j++)
    {
        cout<<a[i][j];
        if (j==n)
        {cout <<setw(5)<<"|";}

        cout<<setw(2)<<" ";

    }
    cout <<endl;
    }*/


// forward elimination

   diag=1;
    j=2;
elimination:
    do
    {
    float z=a[j][diag]/a[diag][diag];
for(i=1;i<=(order+2);i++)
{
    a[j][i]=a[j][i]-(z*a[diag][i]);
}
j++;
}while(j<=order+1);

diag++;
j=diag+1;

if(diag<=order)
goto elimination;

// backward substitution
n1=order+1;
n2=order;

float m;
sol[n1]=a[n1][n1+1]/a[n1][n1];
while(n2>=1)
{
        m=a[n2][n1+1];
        n3=n1;
        for(c=1;c<=(n1-n2);c++)
        {
            m-=(a[n2][n3]*sol[n3]);

        n3--;}

        sol[n2]=m/a[n2][n2];

        n2--;

      }

      cout<<endl<<endl<<" The solution matrix :"<<endl;

for(i=1;i<=(order+1);i++)
{
    cout<<"a["<<i-1<<"] = "<<sol[i]<<endl;
}


    cout<<endl<<"Best Fit Curve Of Order "<<order<<" For given set of data values :"<<endl;
    for(int g=0;g<=order;g++)
    {
        cout<<sol[g+1]<<"x^"<<g;
        if(g!=order)
            cout<<" + ";

    }
    cout<<endl;
    return 0;




}






