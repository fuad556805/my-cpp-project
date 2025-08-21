#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the array elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    int key,found=0;
    cout<<"Enter the key to search: ";
    cin>>key;

    for(int i=0; i<size; i++)
    {
        if(arr[i]==key)
        {
            cout<<key<<" found at index "<<i;
            found++;
            break;
        }
    }
    if(found==0)
    {
        cout<<key<<" not found in the array.";
    }
    return 0;
}
