#include <bits/stdc++.h>
using namespace std;

long long int dp[100][100];
    
long long int find(int i,int j)
{
  if(i<0||j<0)return 0;
  
  if(i==0&&j==0){
    dp[0][0]=1;
    return 1;
  }
  
  if(dp[i][j]) return dp[i][j];
  
  long long int s=0;
  if(i<j) s+=find(i,j-1);
  if(i>0) s+=find(i-1,j);
  dp[i][j]=s;
  return s;
}

int main()
{  
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n%2==0)
    {
      cout<<find(n/2,n/2)<<endl;
    }
    else
    {
      cout<<0<<endl;
    }
  } 
  return 0;
}