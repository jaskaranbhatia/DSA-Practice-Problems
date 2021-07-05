#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int m,int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int index = dp[m][n];  
   	char lcs[index+1]; 
   	lcs[index] = '\0';   
   	int i = m, j = n; 
  	while (i > 0 && j > 0) { 
		if (s1[i-1] == s1[j-1]){ 
        	lcs[index-1] = s1[i-1]; 
        	i--; 
			j--; 
			index--; 
      	}  
      	else if (dp[i-1][j] > dp[i][j-1]) 
        	i--; 
        else
         	j--; 
    }	 
    cout<<lcs<<endl;
    return dp[m][n];
}

int main(){
    string a = "ABBTAB";
    string b = "GXTXAYB";
    int m = a.length();
    int n = b.length();
    cout<<"Length of longest common subsequence is : "<<lcs(a,b,m,n)<<endl;
    return 0;
}
