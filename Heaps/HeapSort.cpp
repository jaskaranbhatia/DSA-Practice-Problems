#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap,int idx,int n){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= n && rightIdx >= n){
		return;
	}
	int largestIdx = idx;
	if(leftIdx < n && heap[leftIdx] > heap[largestIdx]){
		largestIdx = leftIdx;
	}
	if(rightIdx < n && heap[rightIdx] > heap[largestIdx]){
		largestIdx = rightIdx;
	}
 	if(largestIdx == idx){
		return;
	}
	swap(heap[idx],heap[largestIdx]);
	heapify(heap,largestIdx,n);
}

void display(vector<int> &heap){
	for(int i=0;i<heap.size();i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

void buildHeap(vector<int> &heap, int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(heap, i, n);
	}
}

void heapSort(vector<int> &arr,int n){
	buildHeap(arr, n);
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		n--;
		heapify(arr,0,n);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		arr.push_back(data);
	}
	heapSort(arr,n);
	display(arr);
	return 0;
}

