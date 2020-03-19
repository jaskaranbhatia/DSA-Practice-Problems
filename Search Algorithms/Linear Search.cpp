#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key) {
	for(int i=0;i<n;i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 3;
	int ans = linearSearch(arr,n,key);
	if(ans == -1){
		cout<<"Element not found";
	}
	else{
		cout<<key<<" found at index : "<<ans;
	}
	return 0;
}
