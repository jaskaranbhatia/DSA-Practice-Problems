#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum){
    vector< vector<bool> > dp(n+1, vector<bool>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j < set[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] | dp[i-1][j - set[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 900;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout<<"Found a subset with given sum"<<endl;
    else
        cout<<"No subset with given sum"<<endl;
    return 0;
}