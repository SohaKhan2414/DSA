/*
Start by comparing items that are far apart. Use a gap of N/2 and sort items separated by that gap. Then
cut the gap in half and repeat. Continue until the gap becomes 1, then do a final check of adjacent items.
Your function: diminishingDistanceScanner(int arr[], int size)
What to do:
 Sort the numbers using this gap method
For each gap size, print:
 The current gap size
 The gap as a percentage of array size: (Gap / N) × 100%
 Number of comparisons made in this phase
 Number of swaps made in this phase
*/
#include<iostream>
using namespace std;
void diminishingDistanceScanner(int arr[],int size)
{ 
    for(int gap=size/2;gap>=1;gap=gap/2)
    {
        int swaps=0;
        int comparisons=0;
        for(int j=gap;j<=size-1;j++)
        {
            for(int i=j-gap;i>=0;i=i-gap)
            {
                comparisons++;
                if(arr[i+gap]>arr[i])
                {
                    break;
                }
                else
                {
                    int temp=arr[i];
                    arr[i]=arr[i+gap];
                    arr[i+gap]=temp;
                    swaps++;
                    
                }
            }
        }
        double gapPercentage=((double)gap/size)*100;
        cout<<"Current Gap size: "<<gap<<endl;
        cout<<"Gap Percentage: "<<gapPercentage<<"%"<<endl;
        cout<<"Number of swaps: "<<swaps<<endl;
        cout<<"Number of comparisons: "<<comparisons<<endl;
    }
}
int main()
{
int *arr,size;
cout<<"Enter number of elements: "<<endl;
cin>>size;
arr=new int [size];
for(int i=0;i<size;i++)
{
    cout<<"Enter item for index "<<i<<" : "<<endl;
    cin>>arr[i];
}
diminishingDistanceScanner(arr,size);
cout<<"Sorted Array: "<<endl;
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
delete[] arr;
return 0;
}