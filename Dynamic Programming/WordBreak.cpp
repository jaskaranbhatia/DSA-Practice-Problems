#include <bits/stdc++.h>
using namespace std;
  
bool isPossible(string s, vector<string>& wordDict){
  int n = s.length();
  vector<int> dp(n+1,false);
  dp[0] = true;
  for(int i=1; i<=n; i++){
    for(int j=i; j>=0; j--){
      if(dp[j]){
        string sub = s.substr(j,i-j);
        if(find(wordDict.begin(),wordDict.end(),sub) != wordDict.end()){
          dp[i] = true;
          break;
        }
      }
    }
  }
  return dp[n];
}  
  
int main()
{
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    int dict_sz;
    cin>>dict_sz;
    vector<string> dict(dict_sz);
    for(int i=0; i<dict_sz; i++){
      cin>>dict[i];
    }
    if(isPossible(s, dict)){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}