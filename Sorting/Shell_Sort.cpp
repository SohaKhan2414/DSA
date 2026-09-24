#include<iostream>
using namespace std;
int main()
{
    int *arr,size,gap,temp;
    cout<<"Enter number of elements:"<<endl;
    cin>>size;
    arr=new int [size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element for index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
for(gap=size/2;gap>=1;gap=gap/2)
{
for(int j=gap;j<=size-1;j++)
{
    for(int i=j-gap;i>=0;i=i-gap)
    {
    if(arr[i+gap]>arr[i])
    {
        break;
    }    
    else
    {
     temp=arr[i];
     arr[i]=arr[i+gap];
     arr[i+gap]=temp;
    }

    }
}
}
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
delete[] arr;
return 0;
}
