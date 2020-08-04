#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
	if(nums.size() < 3){
		return {};
	}
	int n = nums.size();
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	set<vector<int>> s;
	for(int i=0;i<n;i++){
		int value = nums[i];
		int l = i+1, r=n-1;
		while(l<r){
			int sum = value + nums[l] + nums[r];
			if(sum == 0){
				s.insert({value,nums[l],nums[r]});
				l++;
				r--;
			}
			else if(sum < 0){
				l++;
			}
			else{
				r--;
			}
		}
	}
	for(auto v:s){
		ans.push_back(v);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	vector<vector<int>> ans;
	ans = threeSum(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
