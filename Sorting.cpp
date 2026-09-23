#include <iostream>
using namespace std;

int main()
{
    // Bubble Sort
    int a[4] = {2, 8, 6, 1};
    int n = 4;
    int temp;

    for(int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for(int j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                flag = 1;
            }
        }

        if(flag == 0)
        {
            break;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
//insertion sort
for(int i=1;i<n;i++)
{
    temp=a[i];
    j=i-1;
    while(j>=0&&a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
//selection sort
for(int i=0;i<n-1;i++)
{
    int min=i;
    for(int j=i+1;j<n;j++)
    {
if(a[j]<a[min])
{
    min=j;
}
if(min!=i)
{
    swap(a[i],a[min]);
}
    }
}