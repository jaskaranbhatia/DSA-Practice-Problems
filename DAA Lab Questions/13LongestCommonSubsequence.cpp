#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int n, int m){
    vector< vector<int> > dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int index = dp[n][m];  
   	char lcs[index+1]; 
   	lcs[index] = '\0';   
   	int i = n, j = m; 
  	while (i > 0 && j > 0) { 
		if (X[i-1] == Y[j-1]){ 
        	lcs[index-1] = X[i-1]; 
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
    return dp[n][m];
}

int main(){
    string X,Y;
    cin>>X>>Y;
    int n = X.length();
    int m = Y.length();
    cout<<lcs(X, Y, n, m);
    return 0;
}