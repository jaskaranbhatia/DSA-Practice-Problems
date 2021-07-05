#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#define pii pair<ll,ll>
typedef long long int ll;
#define mod int(1e9 + 7)
 
using namespace std;
ll mat[1001][1001];    
int dx[]={2,2,-2,-2,-1,1,1,-1};
int dy[]={-1,1,1,-1,2,2,-2,-2};
ll fac(ll t) { 
    ll ans=1; 
    for(ll i=1;i<=t;i++)
        ans=(ans*i)%mod; 
    return ans; 
}
 
int dfs(ll start,ll end,ll mat[][1001],vector<vector<bool>>& visited,ll n,ll m){
    ll t = 0;
    for(ll i=0;i<8;i++){
        ll x = start + dx[i];
        ll y = end + dy[i]; 
        if(x<0 || y<0 || x>=n || y>=m || visited[x][y]){
            continue;    
        }    
        if(!visited[x][y] && (mat[x][y]==1)) {
            visited[x][y]=true;
            t += (dfs(x,y,mat,visited,n,m) + 1);    
        }   
    }
 	return t;
}

 
int main()
{
    //code
 
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                mat[i][j]=0;    
            }    
        }    
        ll q;
        cin>>q;
        while(q--){
            ll x,y;
            cin>>x>>y;
            mat[x-1][y-1]=1;
        } 
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        long long ans=1,t; 
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++) { 
                if(mat[i][j]==1 && !visited[i][j]) { 
                    t=dfs(i,j, mat, visited, n, m); 
                    ans=(ans*fac(t))%mod; 
            } 
        } 
        cout<<ans<<endl;    
    }
    return 0;
}
 




