#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
	int i,key,j;
	for(int i=1;i<n;i++){
		key = arr[i];
		j = i - 1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,n);
	print(arr,n);
	return 0;
}
