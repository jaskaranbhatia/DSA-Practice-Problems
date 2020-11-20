#include<bits/stdc++.h>
using namespace std;

// Time Complexity is O(logn)/O(h) for heapify, h = Height of Tree
void maxheapify(vector<int> &heap,int idx,int n){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= n && rightIdx >= n){
		return;
	}
	int largestIdx = idx;
	if(leftIdx < n && heap[leftIdx] > heap[largestIdx]){
		largestIdx = leftIdx; // Left Node is greater than Root Node
	}
	if(rightIdx < n && heap[rightIdx] > heap[largestIdx]){
		largestIdx = rightIdx; // Right Node is greater than Root Node
	}
	if(largestIdx == idx){
		return; // 
	}
	swap(heap[idx],heap[largestIdx]);
	maxheapify(heap,largestIdx,n);
}

// Time complexity for build heap is O(n)
void buildHeap(vector<int> &heap,int n){
	for(int i=heap.size()/2-1;i>=0;i--){
		maxheapify(heap,i,n);
	}
}

// Time complexity for heapSort is O(nlogn)
void heapSort(vector<int> &arr,int n){
	buildHeap(arr,n); // Build a Max Heap
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]); // The largest goes to last
		n--; // As n is sorted so n--
		maxheapify(arr,0,n); // Call downheapify for n-- as last element is at it's correct position
	}
}

void display(vector<int> &heap){
	for(auto i:heap){
		cout<<i<<" ";
	}	
	cout<<endl;
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

