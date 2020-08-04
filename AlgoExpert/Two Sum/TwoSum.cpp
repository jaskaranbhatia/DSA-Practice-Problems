#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > twoSum(vector<int> arr,int n,int target){
    int l = 0;
    int r = n-1;
    vector< pair<int,int> > ans;
    while(l<r){
        int sum = arr[l] + arr[r];
        if(sum == target){
            pair<int,int> p;
            p.first = l;
            p.second = r;
            ans.push_back(p);
            l++;
            r--;
        }
        else if(sum < target){
            l++;
        }
        else{
            r--;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    vector< pair<int,int> > ans = twoSum(arr,n,sum);
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
}