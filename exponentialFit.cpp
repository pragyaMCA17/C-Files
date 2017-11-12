#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,n;
    cout<<"\nEnter the no. of data pairs to be entered:\n";
    cin>>n;
    double x[n],y[n],lny[n],a,b,c;
    cout<<"\nEnter the x-axis values:\n";
    for (i=0;i<n;i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";
    for (i=0;i<n;i++)
        cin>>y[i];
    for (i=0;i<n;i++)
        lny[i]=log(y[i]);
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];
        ysum=ysum+lny[i];
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*lny[i];
    }
    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);
    c=pow(2.71828,b);
    double y_fit[n];
    for (i=0;i<n;i++)
        y_fit[i]=c*pow(2.71828,a*x[i]);
    cout<<"S.no"<<setw(5)<<"x"<<setw(19)<<"y(observed)"<<setw(19)<<"y(fitted)"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(18)<<y_fit[i]<<endl;
    cout<<"\nThe corresponding line is of the form:\n\nlny = "<<a<<"x + ln"<<b<<endl;
    cout<<"\nThe exponential fit is given by:\ny = "<<c<<"e^"<<a<<"x\n";
    return 0;
}


