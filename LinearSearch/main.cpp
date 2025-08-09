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
    int key,found=0;
    cout<<endl<<"Enter the key you want to search: ";
    cin>>key;
    for(int i=1; i<=num; i++)
    {
        if(arr[i] == key)
        {
            found = found +1;
            cout<<"Found "<<key<<" at index : "<<i<<endl;
            break;

        }
    }
    if(found==0)
    {
        cout<<"Not Found";
    }
}

