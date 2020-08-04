#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(int arr1[],int arr2[],int n1,int n2){
	int i = 0, j = 0;
	int k = 0;
	vector<int> arr3(n1+n2);
	while(i<n1 && j<n2){
		if(arr1[i] < arr2[j]){
			arr3[k++] = arr1[i++];
		}
		else{
			arr3[k++] = arr2[j++];
		}
	}
	while(i<n1){
		arr3[k++] = arr1[i++];
	}
	while(j<n2){
		arr3[k++] = arr2[j++];
	}
	return arr3;
}

int main(){
	int arr1[] = {1,3,5,7};
	int arr2[] = {2,4,6};
	int s1 = sizeof(arr1)/sizeof(arr1[0]);
	int s2 = sizeof(arr2)/sizeof(arr2[0]);
	vector<int> ans = mergeArrays(arr1,arr2,s1,s2);
	for(auto num:ans){
		cout<<num<<" ";
	}
}
