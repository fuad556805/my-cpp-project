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
    cout<<endl;
    int temp[size],x,count=0;
    for(int i=0; i<size; i++)
    {
        for(int j=i; j>0; j--)
        {
            temp[i]=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]= temp[i];
            count++;

            cout<<"step: "<<arr[i]<<"."<<arr[j]<<" : ";
            for(int x=0; x<size; x++)
            {
                cout<<arr[x]<<" ";
            }
            cout<<endl;
        }
    }

    cout<<endl<<"swaping "<<count<<" times.";
    cout <<endl<<"Sorted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
