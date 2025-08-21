#include <iostream>
using namespace std;

int main()
{
    string job[5] = {"job1", "job2", "job3", "job4", "job5"};
    int deadline[5] = {4, 1, 1, 1, 3};
    int profit[5] = {20, 10, 40, 30, 50};

    int temp[5+1] = {0};
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (profit[i] < profit[j])
            {
                swap(job[i], job[j]);
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);

            }
        }
    }

    int max_deadline = 0;
    for (int i = 0; i < 5; i++)
    {
        if (deadline[i] > max_deadline)
            max_deadline = deadline[i];
    }

    cout<<"Job Selected: ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = deadline[i]; j > 0; j--)
        {
            if (temp[j] == 0)
            {
                temp[j] = 1;
                sum = sum + profit[i];
                cout << job[i] << " ";
                break;
            }
        }
    }

    cout << endl << "Total Profit: " << sum << endl;

    return 0;
}
