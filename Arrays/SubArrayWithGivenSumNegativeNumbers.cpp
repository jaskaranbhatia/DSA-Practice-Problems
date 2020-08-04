#include<bits/stdc++.h>
using namespace std;

pair<int,int> subArrGivenSum(int arr[],int n,int sum){
	unordered_map<int,int> mp;
	int cur_sum = 0;
	for(int i=0;i<n;i++){
		cur_sum += arr[i];
		if(cur_sum == sum){
			return {0,i};
		}
		if(mp.find(cur_sum-sum) != mp.end()){
			return {mp[cur_sum-sum]+1,i};
		}
		mp[cur_sum] = i;
	}
	return {-1,-1};
}

int main(){
	int arr[] = {1,-1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 0;
	pair<int,int> ans = subArrGivenSum(arr,n,sum);
	cout<<ans.first<<" "<<ans.second<<endl;
}
