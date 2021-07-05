#include<bits/stdc++.h>
using namespace std;

bool isPossible(string s, vector<string> &wordDict){
	int n = wordDict.size();
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=i; j>=0; j--){
			if(dp[j]){
				string sub = s.substr(j, i-j);
				if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()){
					dp[i] = true;
					break;
				}	
			}
		}
	} 
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	vector<string> wordDict(n);
	for(int i=0; i<n; i++){
		cin>>wordDict[i];
	}
	string s;
	cin>>s;
	if(isPossible(s, wordDict)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
