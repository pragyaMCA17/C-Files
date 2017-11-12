#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int i=0,j,pp,count=0;
float a[1000],p;
fstream file;

void search(float n1)
{

    for(i=0;i<count;i++)
    {
        if(a[i]==n1)
        {
            pp=i;
            break;
        }
    }
pp=i;

}

void asc()
{

for(i=0;i<count;i++)
{

      for(j=i+1;j<count;j++)
   {
       if(a[i]>a[j])
      {
          p=a[i];
       a[i]=a[j];
       a[j]=p;
       }
   }
}


   for(i=0;i<count;i++)
   {cout<<a[i]<<"\t";
   file<<a[i];
   }

}

void dsc()
{
for(i=0;i<count;i++)
{

      for(int j=i+1;j<=count;j++)
   {
       if(a[i]<a[j])
      {p=a[i];
       a[i]=a[j];
       a[j]=p;}
   }

}


   for(i=0;i<count;i++)
   {cout<<a[i]<<"\t";
   file<<a[i];
   }


}


int main()
{   int x,mx,mn;
    float s,n;
    char ans;

    file.open("LIST.txt");

    while(!file.eof())
    {

        file>>s;
        a[count]=s;

        count++;


    }
 cout<<endl<<"No. of elements in the File = "<<count<<endl<<endl;
 cout<<"Elements in the list are : "<<endl;

 for(i=0;i<count;i++)
 {
     cout<<a[i]<<"   ";

 }
cout<<endl;

start:

    do{
        cout<<endl<<" MAIN MENU : ";
        cout<<endl<<"1.Linear Search ";
        cout<<endl<<"2.Ascending order" ;
        cout<<endl<<"3.Descending order ";
        cout<<endl<<"4.Maximum Number";
        cout<<endl<<"5.Minimum Number"<<endl;
        cin>>x;

        switch(x)
        {

      case 1:
          cout <<endl<<" Enter the number to be searched = ";
          cin>>n;
          search(n);
          if(pp<count)
            cout<<endl<<" Number Found at "<<pp+1<<"th place in the list";
          else
            cout<<endl<<" Oops SORRY !! Number is not there. ";
            break;
      case 2:

          cout<<" Ascending Order Of Numbers In The List : "<<endl;
          asc();
          break;

      case 3:

           cout <<" Descending Order Of Numbers In The List : "<<endl;
           dsc();
           break;
      case 4:

        mx=a[0];
    for(i=1;i<count;i++)
    {
        if(a[i]>mx)
        mx=a[i];


    }
            cout<<endl<<" The max number is :"<<mx<<endl;

        break;

      case 5:
               mn=a[0];
               for(i=1;i<count;i++)
                  {
                    if(a[i]<mn)
                    mn=a[i];


                  }

   cout<<endl<<" The min number is "<<mn<<endl;
   break;

      default :
        cout<<endl<<endl<<" WRONG CHOICE ... Choose Again ";
        goto start;
        break;
        }

    cout<<endl<<endl<<" Continue...(y/n)";
    cin>>ans;
    }while(ans=='y');

    file.close();

    return 0;

    }
