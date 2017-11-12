#include <iostream>
#include <math.h>
using namespace std;

int main ()
{   int n,num,i,j;
    cout<<"*** Forward Difference ***"<<endl;
    cout<<endl<<"Enter number upto which forward difference has to be calculated :";
    cin>>n;
    cout<<endl<<"Enter the number of data points :";
    cin>>num;

    double Xval[num];
    double y[num][n+1];
    cout<<endl<<"Enter data X values :"<<endl;

    for(i=1;i<=num;i++)
    {
        cout<<"X"<<i<<" : ";
        cin>>Xval[i];
        cout<<endl;
        }

    cout<<endl<<"Enter data Y values :"<<endl;

        for(i=1;i<=num;i++)
        {
            cout<<"y"<<i<<" : ";
            cin>>y[i][1];
            cout<<endl;
        }


    cout<<endl<<"Table for differences : "<<endl<<endl;


        for(j=2;j<=n+1;j++)
    {
        cout<<j-1<<" order Difference "<<endl<<endl;
        for(i=1;i<=num-1;i++)

        {

            y[i][j]=y[i+1][j-1]-y[i][j-1];
            cout<<y[i][j]<<endl;
        }

    cout<<endl;
    num--;

    }

    cout<<endl<<"***Over***";
    return 0;

}
