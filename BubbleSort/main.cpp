//Bubble sort

#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];

    for(int i=0; i<size; i++)
    {
        cout<<"enter element- "<<i+1<<" :";
        cin>>arr[i];
    }
    for(int i=0; i<size-1; i++)
    {
        for(int j=1; j<size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl<<"Sorted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }
}
