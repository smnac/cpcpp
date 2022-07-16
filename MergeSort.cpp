#include<iostream>

using namespace std;

void simplemerge(int a[],int low,int mid,int high)
{
    int c[20];
   // c=new int[20];
   int i=low;
   int j=mid+1;
   int k=low; //imp
   while(i<=mid && j<=high)
   {
       if(a[i]<=a[j])
        c[k++]=a[i++];
        else
        c[k++]=a[j++];
   }

   while(i<=mid)
   c[k++]=a[i++];

  while(j<=high)
   c[k++]=a[j++];

   for(int l=low;l<=high;l++)  //imp loop low to high
     a[l]=c[l];


}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        simplemerge(a,low,mid,high);
    }
}

int main(int argc, char const *argv[])
{
    int a[]={20,10,15,30,45,25,33};
    int len = sizeof(a)/sizeof(a[0]);
    mergesort(a,0,len-1);

    for(int i=0;i<len;i++)
    cout<<a[i]<<endl;
    
    return 0;
}
