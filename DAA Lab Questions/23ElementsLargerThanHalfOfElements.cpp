#include <bits/stdc++.h> 
using namespace std; 
  
void findLarger(int arr[], int n) 
{  
    sort(arr, arr + n); 
  
    for (int i = n-1; i >= n/2; i--) 
        cout << arr[i] << " ";     
} 
  
int main()  
{ 
    int arr[] = {1, 3, 6, 1, 0, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findLarger(arr, n); 
    return 0; 
} 
