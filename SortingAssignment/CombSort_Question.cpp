/*
A warehouse management system stores the package weights in the following order:120, 35, 90,
15, 75, 10, 60, 25. The system needs to arrange these weights in ascending order. However,
instead of repeatedly comparing only neighboring elements, the sorting process is designed to first
compare elements that are separated by a large distance. This distance is called the gap. Initially,
the gap is related to the size of the array. After every pass, the gap is reduced using a shrink factor
of 1.3. Elements separated by the current gap are compared and swapped when they are in the
wrong order. The process continues until the gap becomes 1 and a complete pass is performed
without any swaps.
Your program must take the array values as input from the user, display the original array, display
the gap value used in each iteration/pass, display the array after each pass, display the final sorted
array, use a gap-based comparison approach, and must not use sort(), another array, or any other
sorting algorithm.
*/
#include<iostream>
using namespace std;
int main()
{
int *arr,size;
cout<<"Enter number of elements: "<<endl;
cin>>size;
arr=new int [size];
int gap=size;
bool swapped=false;

for(int i=0;i<size;i++)
{
    cout<<"Enter element for index "<<i<<" : "<<endl;
    cin>>arr[i];
}
cout<<"Original Array: "<<endl;
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
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
    cout<<"Gap value: "<<gap<<endl;
    cout<<"Array: "<<endl;
    for(int k=0;k<size;k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    
}
cout<<endl;
cout<<"Final Sorted Array: "<<endl;
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
delete[] arr;
return 0;
}