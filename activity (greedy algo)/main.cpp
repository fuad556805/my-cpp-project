#include <iostream>

using namespace std;

int main()
{
    char arr[5] = {'A','B','C','D','E'};
    int start[5] = {1, 2, 4, 7, 4};
    int end[5] = {3, 5, 6, 8, 6};

    cout<<"You can pick: "<<endl;
    cout<<arr[0]<<endl;
    int lastSelected = 0;
    for(int i=1; i<5; i++)
    {
        if(start[i] >= end[lastSelected])
        {
            cout<<arr[i]<<" "<<endl;
            lastSelected = i;
        }
    }
    return 0;
}

