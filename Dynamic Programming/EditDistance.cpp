#include<bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2, int m, int n,vector< vector<int> > &dp){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    if(str1[m-1] == str2[n-1]){
        return editDistance(str1,str2,m-1,n-1,dp);
    }
    int ans = 1 + 
        min(editDistance(str1,str2,m-1,n-1,dp),
        min(editDistance(str1,str2,m-1,n,dp),
        editDistance(str1,str2,m,n-1,dp)));
    return dp[m][n] = ans;
}

int editDistanceBottomUp(string str1,string str2,int m,int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
            else
                dp[i][j] = 1 + min(dp[i][j - 1], 
                                   min(dp[i - 1][j], 
                                   dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";
    int m = s1.length();
    int n = s2.length();
    //vector< vector<int> > dp(m+1,vector<int>(n+1,-1));
    cout<<editDistanceBottomUp(s1,s2,m,n);
    return 0;
}