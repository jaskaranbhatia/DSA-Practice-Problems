#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string,vector<string>> mp;
	for(auto str:strs){
		string cpy = str;
		sort(cpy.begin(),cpy.end());
		mp[cpy].push_back(str);
	}
	vector<vector<string>> ans;
	for(auto p:mp){
		vector<string> v = p.second;
		ans.push_back(v);
	}	        
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<string> strs(n);
	for(int i=0;i<n;i++){
		cin>>strs[i];
	}
	vector<vector<string>> ans;
	ans = groupAnagrams(strs);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
