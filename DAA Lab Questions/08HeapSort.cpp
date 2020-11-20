#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int idx, int n){
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
    swap(heap[largestIdx], heap[idx]);
    heapify(heap, largestIdx, n);
}

void buildHeap(vector<int> &heap, int n){
    for(int i=n-1;i>=0;i--){
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