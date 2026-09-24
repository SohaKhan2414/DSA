#include<iostream>
using namespace std;
int main()
{
    int *arr,size,temp,gap;
    bool swapped=false;
    cout<<"Enter number of elements: "<<endl;
    cin>>size;
    gap=size;
    arr=new int [size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter elements for index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
    while(gap!=1||swapped)
    {
        gap=gap/1.3;
        if(gap<1)
        {
            gap=1;
           
        }
        swapped=false;
        for(int i=0;i+gap<size;i++)
        {
            if(arr[i]>arr[i+gap])
            {
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
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