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
        cout<<"Enter elements for index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<size-1;i++)
    {
    int min=i;
    for(int j=i+1;j<size;j++)
    {
        if(arr[j]<arr[min])
        {
            min=j;
        }
    }
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    }
    for(int k=0;k<size;k++)
    {
        cout<<arr[k]<<" ";
    }
    delete[] arr;
    return 0;
    
}