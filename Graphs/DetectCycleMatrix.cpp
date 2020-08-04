#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>> mat,int v,vector<bool> &visited,int src,int parent){
	visited[src] = true;
	for(int i=0;i<v;i++){ // Check for all vertices
		if(mat[src][i] == 1){ // Which vertives are neighbours
			if(!visited[i]){ // Check if not visited
				if(detectCycle(mat,v,visited,i,src)){
					return true;				
				}
			}
			else if(visited[i]){ // If visited before
				if(parent != i){ // A back edge, means it has two parents, which means a cycle
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<int>> mat(v,vector<int>(v,0));
	while(e--){
		int v1,v2;
		cin>>v1>>v2;
		mat[v1][v2] = 1;
		mat[v2][v1] = 1;
	}
	vector<bool> visited(v,false);
	int src = 0;
	int parent = -1;
	bool ans = detectCycle(mat,v,visited,src,parent);
	if(ans){
		cout<<"Graph has a cycle";
	}
	else{
		cout<<"Graph doesnt has a cycle";
	}
}
