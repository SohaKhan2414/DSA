/*
Question 2:
Think of this like holding cards in your hand. The first item is considered &quot;sorted.&quot; Take the next item
(the &quot;key&quot;) and compare it with items to its left. If a left item is bigger, shift it right to make space. Place
the key in its correct spot. Repeat for all items.
Your function: insertionArmSorter(int arr[], int size)
What to do:
 Sort the numbers using this method
 After placing each key, print the current array state
 if the key is already in the right place, print &quot;No shift required&quot;
 For each key, print how many positions it shifted
 At the end, print the total shift distance (sum of all shifts)
*/
#include<iostream>
using namespace std;
void InsertionArmSorter(int arr[],int size)
{    int total_shift=0;
    for(int i=1;i<size;i++)
    {
    int shift_count=0;
    int key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key)
    {
    arr[j+1]=arr[j];
    j--;
    shift_count++;
    }
    arr[j+1]=key;
    total_shift+=shift_count;
    if(shift_count==0)
    {
        cout<<"No shift required."<<endl;
    }
    else{
        cout<<"key:"<<key<<" shifted  "<<shift_count<<" positions "<<endl;
        }
    cout<<"Array after key placing: "<<endl;
    for(int k=0;k<size;k++)
    {
        cout<<arr[k];
    }
    cout<<endl;
    }
    cout<<"Total Shifts:"<<total_shift;
}
int main()
{
int *arr,size;
cout<<"Enter number of elements: "<<endl;
cin>>size;
arr=new int[size];
for(int i=0;i<size;i++)
{
    cout<<"Element for index "<<i<<" : "<<endl;
    cin>>arr[i];
}
InsertionArmSorter(arr,size);
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
delete[] arr;
return 0;
}