#include <iostream>

using namespace std;

int main()
{
    int num,count=0;
    cout<<"Enter the number: ";
    cin>>num;

    cout<<num<<" divisors are: ";
    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            cout<<i<<" ";
            count++;
        }
    }
    cout <<endl<<"Count all divisors: "<<count<< endl;
    return 0;
}
