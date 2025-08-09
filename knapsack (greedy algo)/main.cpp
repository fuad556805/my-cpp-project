#include <iostream>
using namespace std;

int main()
{
    int item[] = {1, 2, 3, 4, 5, 6, 7};
    int profit[] = {12, 5, 16, 7, 9, 11, 6};
    int weight[] = {3, 1, 4, 2, 9, 4, 3};
    float ratio[7];

    int n = 7;
    float capacity = 15;
    float sum = 0;

    for(int i = 0; i < n; i++)
    {
        ratio[i] = (float)profit[i] / weight[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(item[i], item[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
                swap(ratio[i], ratio[j]);
            }
        }
    }

    cout << "Items selected:\n";
    for(int i = 0; i < n; i++)
    {
        if(capacity >= weight[i])
        {
            cout << "Item " << item[i] << " " << endl;
            capacity = capacity + weight[i];
            sum = sum + profit[i];
        }
        else
        {
            float fraction = capacity / weight[i];
            cout << "Item " << item[i] << " " << endl;
            sum = sum +  (profit[i] * fraction);
            capacity = 0;
            break;
        }
    }

    cout << "Total profit: " << sum << endl;

    return 0;
}
