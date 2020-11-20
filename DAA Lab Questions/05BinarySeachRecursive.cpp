#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int key){
    if(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            return binarySearch(arr,l,mid-1,key);
        }
        else{
            return binarySearch(arr,mid+1,r,key);
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,4,1,2,3};
    int key = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Element found at index : "<<binarySearch(arr,0,n-1,key)<<endl;
}