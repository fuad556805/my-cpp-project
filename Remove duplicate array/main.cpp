#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    int temp[size]={0};
    cout << "After removing repeated element: " ;
    for(int i=0; i<size; i++)
    {
        if(temp[arr[i]]==0)
        {
            cout<<arr[i]<<" ";
            temp[arr[i]]++;

        }
    }
    return 0;
}
