#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the size of array: ";
    cin>>num;
    int arr[num];
    cout<<"Enter the array: ";
    for(int i=1; i<=num; i++)
    {
        cin>>arr[i];
    }
    int temp;
    for(int i=1; i<=num; i++)
    {
        for(int j=1; j<num; j++)
        {
            if(arr[j]>arr[j + 1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Sorted array: ";
    for(int i=1; i<=num; i++)
    {
        cout<<" "<<arr[i];
    }
    int key;
    cout<<endl<<"Enter the key you want to search: ";
    cin>>key;
    int left = 1, right = num,found=0,index=0;
    while(left<=right)
    {
        int mid = (left+right)/2;
        index = mid;
        if(arr[mid] == key)
        {
            found++;
            cout<<"Found "<<key<<" at index: "<<index;
            break;

        }
        if(arr[mid]<key)
        {
            left = mid + 1;
        }
        else if(arr[mid]>key)
        {
            right = mid - 1;
        }
    }
    if(found == 0)
    {
        cout<<"Not Found";
    }
}
