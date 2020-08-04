#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
	if(nums.size()<3){
		return false;
	}        
	int f = nums[0], s;
	bool first = true;
	for(int i=1;i<nums.size();i++){
		if(nums[i] <= f){
			f = nums[i];
		}
		else if(nums[i] > f && first){
			s = nums[i];
			first = false;
		}
		else if(nums[i] > f && nums[i] <= s){
			s = nums[i];
		}
		else if(nums[i] > s){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> nums = {5,4,3,2,1};
	cout<<increasingTriplet(nums);
}
