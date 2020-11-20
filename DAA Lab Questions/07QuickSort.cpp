#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l;
    for(int j=l;j<=r-1;j++){
        if(arr[j] <= pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int main(){
    int arr[] = {3,4,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}