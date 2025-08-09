#include <iostream>
using namespace std;
int main()
{
    int num, sum = 0, count = 0;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Prime factors: ";
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout <<" "<< i;
            sum += i;
            count++;
            while (num % i == 0)
                num /= i;
        }
    }
    cout << endl << "Output: " << count << endl;
    cout << "Sum of prime factors: " << sum << endl;
    return 0;
}
