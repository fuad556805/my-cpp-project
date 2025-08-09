//Merge Sorting

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i= left;
    int j=mid+1;
    int k=left;
    int temp[100];

    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=left; k<=right; k++)
    {
        arr[k]=temp[k];
    }
}

void mergesort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}


int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<endl<<"Enter the element: ";

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    mergesort (arr,0,size-1);
    cout<<"Sorted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
