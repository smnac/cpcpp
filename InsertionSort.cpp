#include<iostream>
using namespace std;

void insertionsort(int a[],int len)
{
    for(int i=1;i<len;i++)
      {
          int val=a[i];
          int hole=i;
          while(hole>0 && a[hole-1]>val)
          {
              a[hole]=a[hole-1];
              hole=hole-1;
          }

          a[hole]=val;
      }
}
int main(int argc, char const *argv[])
{
    int a[]={20,10,15,30,45,25,33};
    int len = sizeof(a)/sizeof(a[0]);
    insertionsort(a,len);

    for(int i=0;i<len;i++)
    cout<<a[i]<<endl;
    
    return 0;
}
