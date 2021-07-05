#include<bits/stdc++.h>
using namespace std;

int smallestSum(int arr[], int n){
    int cs = INT_MAX, ms = INT_MAX;
    for(int i=0; i<n; i++){
        if(cs > 0){
            cs = arr[i];
        }
        else{
            cs += arr[i];
        }
        ms = min(ms, cs);
    }
    return ms;
}

int main(){
    int arr[] = {3,-4,2,-6,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<smallestSum(arr,n)<<endl;
}