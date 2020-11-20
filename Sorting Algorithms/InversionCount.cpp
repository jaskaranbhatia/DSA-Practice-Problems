#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll merge(ll arr[], ll l, ll mid, ll r){
	int i = l;
	int j = mid;
	int k = 0;
	int temp[r-l+1];
	int count = 0;
	while(i < mid && j <= r){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			count += (mid-i);
		}
	}
	while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }
	for(ll i=l,k=0;i<=r;i++,k++){
		arr[i] = temp[k];
	}
	return count;
}

ll mergeSort(ll arr[],ll l,ll r){
	ll count = 0;
	if(l<r){
		int mid = l + (r-l)/2;
		ll countLeft = mergeSort(arr,l,mid);
		ll countRight = mergeSort(arr,mid+1,r);
		ll counts = merge(arr,l,mid,r);
		count = countLeft + countRight + counts;
	}
	return count;
}

int main(){
	ll arr[] = {5,4,3,2,1};
	ll n = sizeof(arr)/sizeof(arr[0]);
	cout<<mergeSort(arr,0,n-1);
	return 0;
}
