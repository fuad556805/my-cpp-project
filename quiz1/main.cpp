#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int a = 0, b = 1, sum = 0;

    cout << "Fibonacci series: ";
    for (int i = 0; i < num; i++)
    {
        cout << a << " ";
        sum = sum + a;

        int next = a + b;
        a = b;
        b = next;
    }

    return 0;
}
