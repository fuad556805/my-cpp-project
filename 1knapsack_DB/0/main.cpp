#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    string name[101];
    int w[101], v[101], B[101][1001] = {0};

    cout << "Enter item names: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> name[i];
    }

    cout << "Enter weights of the items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    cout << "Enter values of the items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (w[i] <= j)
            {
                B[i][j] = max(B[i - 1][j], B[i - 1][j - w[i]] + v[i]);
            }
            else
            {
                B[i][j] = B[i - 1][j];
            }
        }
    }

    cout << "\nDP Table (B[i][j]):\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nMaximum value achievable in the knapsack = " << B[n][W] << "\n";

    cout << "\nSelected items:";
    int j = W;
    for (int i = n; i >= 1; i--)
    {
        if (B[i][j] != B[i - 1][j])
        {
            cout << name[i] <<" ";
            j = j - w[i];
        }
    }

    return 0;
}
