/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include<bits/stdc++.h>
using namespace std;

int rob(vector<int> nums,int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return nums[0];
	}
	if(n == 2){
		return max(nums[0],nums[1]);
	}
	int maxMoney[n];
	maxMoney[0] = nums[0];
	maxMoney[1] = max(nums[0],nums[1]);
	for(int i=2;i<n;i++){
		maxMoney[i] = max(maxMoney[i-1],maxMoney[i-2] + nums[i]);
	}
	return maxMoney[n-1];
}

int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		nums.push_back(data);
	}
	cout<<rob(nums,n);
	return 0;
}
