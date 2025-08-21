#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[100];

    cout << "\nMerging from " << left << " to " << right << endl;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            cout << "Taking " << arr[i] << " from left subarray\n";
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            cout << "Taking " << arr[j] << " from right subarray\n";
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= right)
        {
            cout << "Taking " << arr[j] << " from right subarray\n";
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            cout << "Taking " << arr[i] << " from left subarray\n";
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    cout << "After merging, temporary array: ";
    for (int idx = left; idx <= right; idx++)
    {
        cout << temp[idx] << " ";
    }
    cout << endl;

    for (int idx = left; idx <= right; idx++)
    {
        arr[idx] = temp[idx];
    }

    cout << "Array after copying back: ";
    for (int idx = left; idx <= right; idx++)
    {
        cout << arr[idx] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
