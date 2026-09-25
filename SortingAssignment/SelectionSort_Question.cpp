/*
Question 3:
Look through the unsorted part of the list and find the smallest number. Swap it with the first item of that
unsorted part. Move to the next position and repeat until the whole list is sorted. This uses fewer swaps
than other methods.
Your function: minimalSwapCrane(int arr[], int size)
What to do:
 Sort the numbers using this method
 If the smallest item is already in the right spot, skip the swap (count it as a "skipped swap")
Print:
 Total actual swaps
 Number of skipped swaps
 Swap-to-Comparison Ratio: (Actual Swaps / Total Comparisons) × 100%
 Note: Total comparisons for this method is always N(N-1)/2
*/
#include<iostream>
using namespace std;
void minimalSwapCrane(int arr[],int size)
{
    int skippedswaps=0;
    int actualswaps=0;

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
    if(min==i)
    {
        cout<<"Skipped swaps."<<endl;
        skippedswaps++;
    }
    else
    {
    int temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    actualswaps++;
}
    }
    int totalComparisons=size*(size-1)/2;
    double SwaptoComparisonRatio=(double)actualswaps / totalComparisons*100;
    cout<<"Actual swaps: "<<actualswaps<<endl;
    cout<<"Skipped swaps: "<<skippedswaps<<endl;
    cout<<"Total Comparisons: "<<totalComparisons<<endl;
    cout<<"Ratio: "<<SwaptoComparisonRatio<<"%"<<endl;
    
}
int main()
{
int *arr,size;
cout<<"Enter number of elements: "<<endl;
cin>>size;
arr=new int[size];
for(int i=0;i<size;i++)
{
    cout<<"Enter element for index "<<i<<" : "<<endl;
    cin>>arr[i];
}
minimalSwapCrane(arr,size);
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";

}
delete[] arr;
return 0;
}