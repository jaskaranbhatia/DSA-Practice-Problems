#include<bits/stdc++.h>
using namespace std;

void binarySearch(int arr[], int n, int key){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            cout<<"Element found at index : "<<mid<<endl;
            return;
        }
        else if(arr[mid] > key){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<"Element not found"<<endl;
}

int main(){
    int arr[] = {5,4,1,2,3};
    int key = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    binarySearch(arr, n, key);
    return 0;
}