#include <iostream>

using namespace std;

int main()
{
    int arr[]= {1,2,5,10,20,50,100,500,1000};
    int sum=0;
    int coin ;
    cout<<"Enter the coin: ";
    cin>> coin;

    for(int i=8; i>=0; i--)
    {
        while(coin >= arr[i])
        {
            cout<<arr[i]<<" "<<endl;
            coin = coin - arr[i];
            sum = sum + arr[i];
            if(coin ==0)
            {
                break;
            }
        }
    }

    cout << "sum of coin: " <<sum<<endl;
    return 0;
}
