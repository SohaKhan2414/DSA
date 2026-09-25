/*
Question 1: Take input for the number of items and their tracking numbers from the user. Write a separate
C++ function for each task below.
Start at the beginning of the list. Compare each pair of neighboring items. If the left item is bigger than
the right one, swap them. Move to the next pair and repeat until you reach the end. The biggest item move
to the end. Go back to the start and repeat until the whole list is sorted.
Your function: adjacentSwapper(int arr[], int size)
What to do:
 Sort the numbers using this method
 Stop early if a full pass has no swaps (means items already sorted)
Print:
 Total number of swaps made
 Total comparisons made
 How many passes you saved compared to the worst case (size-1 passes)
 Show the theoretical worst-case comparisons next to your actual count: N(N-1)/2*/

#include<iostream>
using namespace std;
void AdjacentSwapper(int arr[],int size)

{
    bool swapped=false;
    int swaps=0;
    int comparisons=0;
    int passes=0;
    for(int i=0;i<size-1;i++)
    {
    passes++;
    swapped=false;
for(int j=0;j<size-1-i;j++)
{   
    comparisons++;
    if(arr[j]>arr[j+1])
    {
        int temp=arr[j];
        arr[j]=arr[j+1];
       arr[j+1]=temp;
       swaps++;
       swapped=true;
    }
}
if(swapped==false)
{
    break;
}
    }

int worstComparisons = size * (size - 1) / 2;
int passesSaved = (size - 1) - passes;
cout << "Total swaps: " << swaps << endl;
cout << "Total comparisons: " << comparisons << endl;
cout << "Passes saved: " << passesSaved << endl;
cout << "Theoretical worst-case comparisons: "
     << worstComparisons << endl;
}
int main()
{
 int *tracking_Nos,item_count,temp;
 cout<<"Enter number of items: "<<endl;
 cin>>item_count;
 tracking_Nos=new int[item_count];
 for(int i=0;i<item_count;i++)
 {
    cout<<"Enter tracking number for index: "<<i<<" : "<<endl;
    cin>>tracking_Nos[i];
 }
 AdjacentSwapper(tracking_Nos,item_count);

    return 0;
}