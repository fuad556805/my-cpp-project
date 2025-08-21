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

    int targetSum,found=0;
    cout<<"Enter the target sum: ";
    cin>>targetSum;

    for(int i=0; i<size; i++)
    {
        int sum=0;
        for(int j=i; j<size; j++)
        {
            sum = sum + arr[j];
        }
        if(sum==targetSum)
        {
            found++;
        }
    }
    if(found==0)
    {
        cout<<targetSum<<" is not exists.
        ";
    }
    else
    {
        cout<<targetSum<<" is exists.";
    }


    return 0;
}
