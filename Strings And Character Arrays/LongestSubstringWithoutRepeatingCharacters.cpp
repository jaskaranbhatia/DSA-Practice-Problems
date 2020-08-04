#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_set<char> str;
	int i = 0, j = 0;
	int n = s.length();
	int ans = 0;
	while(i<n && j<n){
		if(str.find(s[j]) == str.end()){
			str.insert(s[j]);
			j++;
			ans = max(ans,j-i);
		}
		else{
			str.erase(s[i]);
			i++;	
		}
	}
	return ans;
}

int main(){
	string s;
	cin>>s;
	cout<<lengthOfLongestSubstring(s);
}
