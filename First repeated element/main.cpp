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
    int temp[size]={0};

    for(int i=0; i<size; i++)
    {
        if(temp[arr[i]]==0)
        {
            temp[arr[i]]++;
        }
        else
        {
             cout<<"First repeated element: "<<arr[i];

        }
    }
    return 0;
}
