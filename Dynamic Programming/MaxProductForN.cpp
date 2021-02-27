#include <bits/stdc++.h>
using namespace std;

#define sz 1e5
  
int main()
{
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    vector<int> dp(sz);
    dp[1]=0,dp[2]=1,dp[3]=2,dp[4]=4,dp[0]=0,dp[5]=6,dp[6]=9;
    for(int i=7; i<=n; i++){
      int max_prod = INT_MIN;
      for(int cut=1; cut<=i; cut++){
        int cur = dp[cut] * (i-cut);
        max_prod = max(max_prod, cur);
      }
      dp[i] = max_prod;
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}
