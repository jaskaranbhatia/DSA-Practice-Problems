#include <bits/stdc++.h> 
using namespace std; 
  
bool cmp(int a, int b){
    return a > b; // Comparator function for sorting in decreasing order
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sortEvenOdd(vector<int> &arr, int n) 
{ 
    int oddIdx = 1; 
    int evenIdx = n - 1;  
    if ((evenIdx & 1)){
        evenIdx--;
    }  
    while (oddIdx < evenIdx) { 
        swap(arr[oddIdx], arr[evenIdx]); 
        evenIdx -= 2;
        oddIdx += 2;  
    } 
    int half = (n+1)/2;
    sort(arr.begin(), arr.begin()+half); // Using inbuilt randomized quicksort with o(nlogn) time complexity
    sort(arr.begin()+half, arr.begin() + n, cmp); // Here half is inclusive while above was exclusive
} 
  
int main() 
{ 
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortEvenOdd(arr,n); 
    for(int i=0; i<n; i++){
         cout<<arr[i]<<" ";
    }  
    cout<<endl;
    return 0; 
} 
