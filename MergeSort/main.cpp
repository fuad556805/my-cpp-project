// MergeSort
#include <iostream>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int h = right;

    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= h)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int k = left; k <= right; k++)
    {
        arr[m] = temp[m];
    }
}

void mergeSort(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;

    int arr[size];
    int temp[size];

    cout << "\nEnter the element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, temp, 0, size - 1);

    cout << "\nArray after merge: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
