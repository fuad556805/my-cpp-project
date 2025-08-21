#include <iostream>

using namespace std;

int main()
{
    int num,found=0;
    cout<<"Enter the number: ";
    cin>>num;

    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
            cout<<num<<" is divided by "<<i<<endl;
            found++;
            break;
        }
    }
    if(found==0)
    {
        cout<<num<<" is prime.";
    }
    else
    {
        cout<<num<<" is not prime.";
    }
    return 0;
}
