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

    int num;
    cout<<"Enter the number you want to search: ";
    cin>>num;



    int left =0,right = size-1,found=0,index =0;

    while(left<=right)
    {
        int mid =(left+right)/2;
        index = mid;

        if(arr[mid]==num)
        {
            cout<<num<<" found at index "<<mid;
            found++;
            break;
        }
        if(arr[mid]>num)
        {
            right = mid - 1;
        }
        else if(arr[mid]<num)
        {
            left = mid+1;
        }
        if(found==0)
        {
            cout<<num<<" not found .";
        }
    }

    return 0;
}
