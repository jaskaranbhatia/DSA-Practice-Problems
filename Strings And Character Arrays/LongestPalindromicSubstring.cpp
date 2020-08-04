#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
		int n = s.length();
        if(n == 0){
            return "";
        }
        vector<vector<bool>> table(n,vector<bool>(n,false));
        int maxLength = 1;
        for(int i=0;i<n;i++){
            table[i][i] = true;
        }
        int start = 0;
        for(int i=0;i<n;i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = true;
                maxLength = 2;
                start = i;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                if(table[i+1][j-1] && s[i] == s[j]){
                    table[i][j] = true;
                    if(k>maxLength){
                        maxLength = k;
                        start = i;
                    }
                }
            }
        }
        string ans;
        for(int i=start;i<=start+maxLength-1;i++){
            ans += s[i];
        }
        return ans;
}

int main(){
	string s;
	cin>>s;
	string ans = longestPalindrome(s);
	cout<<ans<<endl;
}
