#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the element: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    int temp[size];
    for(int i=0; i<size; i++)
    {
        for(int j=i; j>0; j--)
        {
            temp[i]=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]= temp[i];
        }
    }

    cout << "Sorted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
