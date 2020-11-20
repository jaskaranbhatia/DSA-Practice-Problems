#include<bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n){
    vector< pair<int,int> > arrPos(n);
    for(int i=0;i<n;i++){
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos.begin(), arrPos.end());
    vector<bool> vis(n, false);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(vis[i] || arrPos[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while(!vis[j]){
            vis[j] = true;
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
        // add the current cycle to ans
        if(cycle_size > 0) ans += (cycle_size-1);
    }
    return ans;
}

int main(){
    int arr[] = {6,7,3,4,5,1,2};
    int n = (sizeof(arr) / sizeof(int));
    cout<<minSwaps(arr, n)<<endl;
    return 0;
}