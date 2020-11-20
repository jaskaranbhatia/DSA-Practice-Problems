/*

Time Complexity
Worst and Average Case :- O(n^2)
Best Case :- O(n) when array is sorted

Space Complexity
O(1)

*/


#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;        
        }
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
    bubbleSort(arr,n);
    print(arr,n);
}