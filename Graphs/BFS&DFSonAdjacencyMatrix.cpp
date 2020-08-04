#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> mat,int n,vector<bool> &visited,int src){
    cout<<src<<" ";
    visited[src] = true;
    for(int i=0;i<n;i++){
        if(mat[src][i] == 1 && (!visited[i])){
            dfs(mat,n,visited,i);
        }
    }
}

void bfs(vector<vector<int>> mat,int n,vector<bool> &visited,int src){
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty()){
		int f = q.front();
		cout<<f<<" ";
		q.pop();
		for(int i=0;i<n;i++){
			if(mat[f][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> mat(n,vector<int>(n,0));
    while(e--){
        int v1,v2;
        cin>>v1>>v2;
        mat[v1][v2] = 1;
        mat[v2][v1] = 1;
    }
    vector<bool> visiteddfs(n,false);
    dfs(mat,n,visiteddfs,0);
    cout<<endl;
    vector<bool> visitedbfs(n,false);
    bfs(mat,n,visitedbfs,0);
    return 0;
}
