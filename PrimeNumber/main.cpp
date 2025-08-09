#include<iostream>
using namespace std;
int main()
{
    int num,sum=0,count=0;
    cout<<"Enter the number: ";
    cin>>num;

    cout<<"Prime Factors: ";
    for(int i=2; i<=num; i++)
    {
        if(num%i==0)
        {
            cout<<" "<<i;
            sum = sum + i;
            count++;
            while(num%i == 0)
                num = num/i;
        }
    }

    cout<<endl<<"Output:"<<count<<endl;
    cout<<"Sum of Prime Factors: "<<sum;
}
