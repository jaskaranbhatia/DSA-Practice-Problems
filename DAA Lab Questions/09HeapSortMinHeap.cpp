#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int idx, int n){
    int leftIdx = 2*idx + 1;
    int rightIdx = 2*idx + 2;
    int smallestIdx = idx;
    if(leftIdx >= n && rightIdx >= n){
        return;
    }
    if(leftIdx < n && heap[leftIdx] < heap[smallestIdx]){
        smallestIdx = leftIdx;
    }
    if(rightIdx < n && heap[rightIdx] < heap[smallestIdx]){
        smallestIdx = rightIdx;
    }
    if(smallestIdx == idx){
        return;
    }
    swap(heap[idx], heap[smallestIdx]);
    heapify(heap, smallestIdx, n);
}

void buildHeap(vector<int> &heap, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(heap, i, n);
    }
}

void heapSort(vector<int> &heap, int n){
    buildHeap(heap, n);
    for(int i=n-1;i>=0;i--){
        swap(heap[0], heap[i]);
        n--;
        heapify(heap, 0, n);
    }
}

void print(vector<int> heap, int n){
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> heap(n);
    for(int i=0;i<n;i++){
        cin>>heap[i];
    }
    heapSort(heap, n);
    print(heap,n);
}