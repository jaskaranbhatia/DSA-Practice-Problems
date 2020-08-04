#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateTreeLazy(int *tree,int *lazy,int low,int high,int startR,int endR,int curPos,int inc){
	if(low > high){
		return;
	}
	if(lazy[curPos] != 0){
		tree[curPos] += lazy[curPos];
		if(low != high){
			lazy[2*curPos] += lazy[curPos];
			lazy[2*curPos+1] += lazy[curPos];
		}
		lazy[curPos] = 0;
	}
	// Now we have 3 conditions of overlapping
	// 1. No overlap
	if(startR > high || endR < low){
		return;
	}
	// 2. Complete Overlap
	if(startR >= low && high <= endR){
		tree[curPos] += inc;
		if(low != high){
			lazy[2*curPos] += inc;
			lazy[2*curPos+1] += inc;
		}
		return;
	}
	// 3. Partial Overlap
	int mid = (low+high)/2;
	updateTreeLazy(tree,lazy,low,mid,startR,endR,2*curPos,inc);
	updateTreeLazy(tree,lazy,mid+1,high,startR,endR,2*curPos+1,inc);
	tree[curPos] = min(tree[2*curPos],tree[2*curPos+1]);
}

int main(){
	int arr[] = {1,3,-2,4};
	int *tree = new int[12];
	buildTree(arr,tree,0,3,1);
	int *lazy = new int[12];
	updateTreeLazy(tree,lazy,0,3,0,3,1,3);
	updateTreeLazy(tree,lazy,0,3,0,3,1,2);
	for(int i=0;i<7;i++){
		cout<<tree[i];
	}
}

