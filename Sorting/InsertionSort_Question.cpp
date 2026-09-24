/*Fiber-optic company is installing cables at different locations and has recorded the required cable
lengths as 85, 42, 120, 35, 67, 50. The installation team needs these lengths arranged in ascending
order before preparing the final installation plan. The process starts by considering the first value
as arranged, then takes the next value and stores it temporarily. Compare this value with the
previously arranged values, shift larger values one position to the right, and place the stored
value into its correct position. Your program must take input from the user, display the original
array, display the array after each iteration, and display the final sorted array. Do not use sort (),
another array, or repeated swapping; use a temporary variable and shifting as described.*/
#include<iostream>
using namespace std;
int main()
{
    int *lengths,size,temp;
    cout<<"Enter number of lengths: "<<endl;
    cin>>size;
    lengths=new int[size];
    //Input
    for(int i=0;i<size;i++)
    {
        cout<<"Enter length at index "<<i<<" : "<<endl;
        cin>>lengths[i];
    }
    //Display Inputs
    cout<<"Array without sorting: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<lengths[i]<<" ";
    }
    cout<<endl;
    //Sort
    for(int i=1;i<size;i++)
    {
        temp=lengths[i];
       int j=i-1;
        while(j>=0&&lengths[j]>temp)
        {
            lengths[j+1]=lengths[j];
            j--;
        }
        lengths[j+1]=temp;
        cout<<"After iteration "<<i<<" : "<<endl;
        for(int k=0;k<size;k++)
        {
            cout<<lengths[k]<<" ";
        }
        cout<<endl;
    }
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<lengths[i]<<" ";
    }
    delete[] lengths;
    return 0;
}
