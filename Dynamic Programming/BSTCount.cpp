#include <bits/stdc++.h>
using namespace std;
  
int main()
{
  //write your code here
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    dp[0] = 1; // Empty graph
    dp[1] = 1;
    for(int i=2; i<=n; i++){
      for(int j=1; j<=i; j++){
        dp[i] += dp[i-j]*dp[j-1];
      }
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}