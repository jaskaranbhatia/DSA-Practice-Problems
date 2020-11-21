#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
	int x = arr[r], i = l;
	for(int j=l;j<=r-1;j++){
		if(arr[j] <= x){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i],arr[r]);
	return i;
}

int kthSmallest(int arr[], int l, int r, int k){
	if(k > 0 && k <= r-l+1){
		int pos = partition(arr,l,r);
		if(pos-l == k-1){
			return arr[pos];
		}
		else if(pos-l >= k-1){
			return kthSmallest(arr,l,pos-1,k);
		}
		else{
			return kthSmallest(arr,pos+1,r,k-pos+l-1);
		}
	}
	return INT_MAX;
}

int main(){
	int arr[] = {3,4,2,1,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<kthSmallest(arr,0,n-1,6)<<endl;
	return 0;
}