#include<iostream>
using namespace std;

int lowerBound(int arr[],int n,int key){
	int s = 0;
	int e = n-1;
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid] == key){
			ans = mid;
			e = mid-1;
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main(){
	int arr[] = {1,1,2,2,2,4,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int ans = lowerBound(arr,n,2);
	cout<<ans;
}
