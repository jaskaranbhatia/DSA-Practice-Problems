#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums, int k){
    int n = nums.size();
    if(n <= 1) return 0;
    if(n/2 <= k){
        int profit = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                profit += (nums[i] - nums[i-1]);
            }
        }
        return profit;
    }
    vector< vector<int> > dp(k+1, vector<int>(n,0));
    for(int i=1;i<=k;i++){
        int maxVal = INT_MIN;
        for(int j=1;j<n;j++){
            maxVal = max(maxVal, dp[i-1][j-1] - nums[j-1]);
            dp[i][j] = max(dp[i][j-1], maxVal + nums[j]);
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
    int k;
    cin>>k;
    cout<<maxProfit(prices, k)<<endl;
}