#include <iostream>
using namespace std;

int main()
{
    int item[] = {1, 2, 3, 4, 5, 6, 7};
    int profit[] = {12, 5, 16, 7, 9, 11, 6};
    int weight[] = {3, 1, 4, 2, 9, 4, 3};

    int n = 7;
    int capacity = 15;
    int totalProfit = 0;

    bool selected[7] = {0};

    for(int i = 0; i < n; i++)
    {
        if(capacity >= weight[i])
        {
            selected[i] = true;
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
    }

    cout << "Items selected: ";
    for(int i = 0; i < n; i++)
    {
        if(selected[i]) cout << item[i] << " ";
    }
    cout << endl;

    cout << "Total profit: " << totalProfit << endl;

    return 0;
}
