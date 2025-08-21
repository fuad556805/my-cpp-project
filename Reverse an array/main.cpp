#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the element of array: ";

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cout << "Reverse array: ";

    for(int i=size-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
