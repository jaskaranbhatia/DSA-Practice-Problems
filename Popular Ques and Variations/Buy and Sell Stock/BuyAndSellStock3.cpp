#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();
    if(n <= 1) return 0;
    if(n==2){
        int profit = 0;
        if(prices[1] > prices[0]){
            profit += (prices[1] - prices[0]);
        }
        return profit;
    }
    int k = 2;
    vector< vector<int> > dp(k+1, vector<int>(n,0));
    for(int i=1; i<=k; i++){
        int maxVal = INT_MIN;
        for(int j=1; j<n; j++){
            maxVal = max(maxVal, dp[i-1][j-1] - prices[j-1]);
            dp[i][j] = max(dp[i][j-1], maxVal + prices[j]);
        }
    }
    return dp[k][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    cout<<maxProfit(prices)<<endl;
}