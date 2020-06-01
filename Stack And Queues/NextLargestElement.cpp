#include<bits/stdc++.h>
using namespace std;

vector<int> findNextLargest(int arr[],int n){
	stack<int> s;
	s.push(0);
	vector<int> ans(n,0);
	for(int i=1;i<n;i++){
		if(arr[i] <= arr[s.top()]){
			s.push(i);
		}
		else{
			ans[s.top()] = arr[s.top()];
			s.pop();
		}
	}
	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
	}
	return ans;
}
//Performs very bad when arrat is in descending order
int main(){
	int arr[] = {11,13,21,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> ans;
	ans = findNextLargest(arr,n);
	for(auto num:ans){
		cout<<num<<" ";
	}
}
