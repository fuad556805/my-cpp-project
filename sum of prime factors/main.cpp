#include<iostream>
using namespace std;

int main()
{
    int num = 12, sum = 0;

    for(int i = 2; i <= num; i++)
    {
        if(num % i == 0)
        {
            cout << i << " ";
            sum = sum + i;
            while(num % i == 0)
            {
                num /= i;
            }
        }
    }

    if(num > 1)
    {
        cout << num << " ";
        sum += num;
    }

    cout << "\nPrime factors sum: " << sum << endl;

    return 0;
}
