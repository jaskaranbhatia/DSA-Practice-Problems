#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> mat,int v,int src){
	vector<int> distance(v,INT_MAX);
	queue<int> q;
	q.push(src);
	distance[src] = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i=0;i<v;i++){
			if((mat[f][i] == 1) && (distance[i] == INT_MAX)){
				q.push(i);
				distance[i] = distance[f] + 1;
			}
		}
	}
	for(int i=0;i<v;i++){
		cout<<"Distance b/w "<<src<<" and "<<i<<" is "<<distance[i]<<endl;
	}
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
	shortestPath(mat,v,0);
	mat.clear();
	return 0;
}
