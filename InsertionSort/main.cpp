//Insertion sorting

#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the array size: ";
    cin>>size;
    int arr[size];

    cout<<endl<<"Enter the elememt of array: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    for(int i=1; i<size; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    cout<<endl<<"Inserted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }
}
