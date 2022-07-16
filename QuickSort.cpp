#include<iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int key=a[low];
    int i=low+1;
    int j=high;
    int temp;

    while(i<j)
    {

        while(key>=a[i] && i<=high) i++;
        while(key<a[j] && j>=0) j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j= partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }

}

int main(int argc, char const *argv[])
{
   // int a[]={20,10,15,30,45,25,33};
   int *a;
   int n;
   cin>>n;
   a=new int[n];
    //int a[]
    for(int i=0;i<n;i++)
    cin>>a[i];

   // for(int i=0;i<n;i++)
   // cout<<a[i]<<endl;
    int len = sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);

    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
    return 0;
}
