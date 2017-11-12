#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int f;
void prime(int c)
{
    for(int i=2; i<=c/2; i++)
    {
        if(c%i==0)
        {f=0;
        break;
        }
    }

}



int main()
{
    int n=2,count=0;
    cout<<" TO CALCULATE FIRST 100 PRIME NUMBERS "<<endl<<endl;
   do{
        f=1;
    prime(n);
    if(f==1)
    {
        cout<<n<<"\t";
        count++;
    }
    n++;
   }while(count<100);
   return 0;
}





