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
    for(int i=0;i<size-1;i++)
    {
        
        for(int j=0;j<size-1-i;j++)
        {

    if(arr[j]>arr[j+1])
    {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
    }        
        }
    }
    cout<<"The Sorted elements are as follows: "<<endl;
    for(int i=0;i<size;i++)
    {
    cout<<arr[i]<<" ";
    } 
    delete[] arr;
    return 0;
}
