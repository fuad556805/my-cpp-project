#include <iostream>
using namespace std;

int main()
{
    string item[5] = {"A", "B", "C", "D", "E"};
    int weight[5] = {4, 5, 3, 6, 2};
    int profit[5] = {50, 70, 60, 90, 40};

    float ratio[5];

    int n = 5;
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

    cout <<"Items selected: "<<endl;
    for(int i = 0; i < n; i++)
    {
        if(capacity >= weight[i])
        {
            cout << "Item " << item[i] << " " << endl;
            capacity = capacity - weight[i];
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

    cout <<endl<<"Total profit: " << sum << endl;

    return 0;
}
