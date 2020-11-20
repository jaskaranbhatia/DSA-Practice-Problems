#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int n, int W){
    vector< vector<int> > dp(n+1, vector<int>(W+1));
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w){
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int res = dp[n][W];
    int w = W;
    for(int i=n; i>0 && res > 0;i--){
        if(res == dp[i-1][w]){
            continue;
        }
        else{
            cout<<wt[i - 1]<<" "; 
            res = res - val[i - 1]; 
            w = w - wt[i - 1];
        }
    }
    return dp[n][W];
}

int main(){
    int val[] = { 60, 50, 20 }; 
    int wt[] = { 20, 25, 5 }; 
    int W = 40; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<"\n"<<"The maximum value is : "<<knapsack(val, wt, n, W)<<"\n";
    return 0;
}