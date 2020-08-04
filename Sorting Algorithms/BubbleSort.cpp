// Time Complexity
// Worst Case -> O(n^2)
// Best Case -> O(n) , occurs when array is already sorted
#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
    	bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
        	break;
		}
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,5,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    print(arr,n);
    return 0;
}
