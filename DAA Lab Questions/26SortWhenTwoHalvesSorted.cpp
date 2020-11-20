// C++ program to Merge Two Sorted Halves Of
// Array Into Single Sorted Array
#include <bits/stdc++.h>
using namespace std;
 
void SortTwoHalfSorted(int A[], int n)
{
    int i = 0;
    int j = n / 2;
 
    // loop until end of array
    while (j < n) {
 
        // if two pointer is equal then go
        // to next element of second half.
        if (i == j)
            j++;
 
        // if element of first half is bigger 
        // than element of second half swap two 
        // elements and go next element of first half.
        if (j < n && A[i] > A[j]) {
            swap(A[i], A[j]);
        }
        i++;
    }
}
 
// Driver code
int main()
{
    int A[] = { 2, 3, 8, -1, 7, 10 };
    int n = sizeof(A) / sizeof(A[0]);
    SortTwoHalfSorted(A, n);
 
    // Print sorted Array
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}