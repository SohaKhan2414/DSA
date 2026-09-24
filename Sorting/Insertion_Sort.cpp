#include<iostream>
using namespace std;
int main()
{
    int *arr,size,temp;
    cout<<"Enter number of elements: "<<endl;
    cin>>size;
    arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i<<" : "<<endl;
        cin>>arr[i];
    }
   for(int i=1;i<size;i++)
   {
    temp=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>temp)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
   }
   cout<<"The Sorted elements are as follows: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
