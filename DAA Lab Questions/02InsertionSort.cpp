/*

Time Complexity
Worst and Average Case :- O(n^2)
Best Case :- O(n) when array is sorted

Space Complexity
O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    for(int i=1;i<n;i++){
        int ele = arr[i];
        int j = i-1;
        while(arr[j] > ele && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = ele;
    }
}

void print(vector<int> arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    print(arr,n);
}