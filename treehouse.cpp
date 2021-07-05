#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> g;
    vector<int> val;
    vector<int> ch;
public:
    Graph(int X, int N){
        val.resize(N+1);
        ch.resize(N+1);
        val[1] = X;
    }
    void addEdge(int x, int y){
        g[x].push_back(y);
    }
    int calculateChildren(int src){
        int count = 0;
        for(int nbr:g[src]){
            count += calculateChildren(nbr) + 1;
        }
        ch[src] = count;
        return count;
    }
    int calculateValue(int src, int n){
        int total = 0;
        queue<int> q;
        vector<int> visited(n+1, 0);
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            vector<pair<int,int>> nbrs;
            for(auto nbr:g[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    pair<int,int> p = make_pair(ch[nbr], nbr);
                    nbrs.push_back(p);
                }
            }
            if(nbrs.size() != 0){
                sort(nbrs.begin(), nbrs.end(), greater<pair<int,int>>());
                int gcd = val[f];
                int init = val[f];
                for(auto p:nbrs){
                    val[p.second] = gcd;
                    gcd += init;
                }
            }
        }
        int ans = accumulate(val.begin(), val.end(), 0);
        cout<<ans<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        Graph g(x, n);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            g.addEdge(u,v);
        }
        g.calculateChildren(1);
        g.calculateValue(1, n);
    }
}