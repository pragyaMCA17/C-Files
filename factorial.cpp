#include<iostream>
#include<math.h>
using namespace std;

int n,p,s;

int fact(int p)
{
    if(p==1)
        return 1;
    else
        return p*fact(p-1);

}
 int main()
 {

     cout<<" FACTORIAL OF A NUMBER "<<endl<<endl;
     cout<< " ENTER THE NUMBER =  " ;
     cin>>n;
     s=fact(n);

     cout<<endl<<n<<"! is = "<<s;
     cout<<endl<<endl<<"*** END OF PROGRAM ***" ;
     return 0;
 }



