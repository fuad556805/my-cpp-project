#include <iostream>
using namespace std;

int main()
{
    int num,sum=0;
    cout<<"Enter the number: "
    cin>>num;
    int arr[num];
    cout<<"Factor 2 to num:";
    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
            cout<<i<<" ";
        }
    }

    for(int i=0; i<num; i++)
    {
        bool isprime = true;
        for(int j=2; j<num; j++)
        {
            if(arr[i]%j==0)
            {
                isprime=false;
                break;
            }
        }
        if(isprime == true)
        {
            sum = sum + arr[i];
        }
    }
}
