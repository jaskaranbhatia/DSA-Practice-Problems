#include <bits/stdc++.h>
using namespace std;

void mergeArr(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i + l];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int n)
{
    for (int cur_size = 1; cur_size <= n - 1; cur_size = 2*cur_size)
    {
        for (int left = 0; left < n - 1; left += 2 * cur_size)
        {
            int mid = min(left + cur_size - 1, n - 1);
            int right = min(left + 2 * cur_size - 1, n - 1);
            mergeArr(arr, left, mid, right);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting : ";
    printArray(arr, n);
    mergeSort(arr, n);
    cout << "Array after sorting : ";
    printArray(arr, n);
    return 0;
}