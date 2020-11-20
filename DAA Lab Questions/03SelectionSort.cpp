/*

Time Complexity
O(n^2)

Space Complexity
O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    int minIdx;
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
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
    selectionSort(arr,n);
    print(arr,n);
}