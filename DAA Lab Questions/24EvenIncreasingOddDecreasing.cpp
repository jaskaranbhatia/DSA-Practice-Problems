#include <bits/stdc++.h> 
using namespace std; 
  
void bitonicGenerator(int arr[], int n) 
{ 
    // first odd index 
    int i = 1; 
  
    // last index 
    int j = n - 1; 
  
    // if last index is odd 
    if (j % 2 != 0) 
        // decrement j to even index 
        j--; 
  
    // swapping till half of array 
    while (i < j) { 
        swap(arr[i], arr[j]); 
        i += 2; 
        j -= 2; 
    } 
  
    // Sort first half in increasing 
    sort(arr, arr + (n + 1) / 2); 
  
    // Sort second half in decreasing 
    sort(arr + (n + 1) / 2, arr + n, greater<int>()); 
} 
  
// Driver Program 
int main() 
{ 
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bitonicGenerator(arr, n); 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 
