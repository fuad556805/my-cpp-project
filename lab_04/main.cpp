#include <iostream>
using namespace std;
int main()
{
    int arr[]= {1,2,3,4,5,3,6,7};
    int n = 8;
    int temp[n+1] = {0};

    for (int i = 0; i < n; i++)
    {
        if (temp[arr[i]] == 0)
        {
            temp[arr[i]]++;
        }
        else
        {
            cout << "First duplicate value: " << arr[i] << endl;
            break;
        }
    }
}
