#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > threeSum(vector<int> arr,int n,int target){
    vector< vector<int> > ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int l = i+1;
        int r = n-1;
        while(l < r){
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == target){
                ans.push_back({i,l,r});
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
    vector< vector<int> > ans = threeSum(arr,n,sum);
    for(auto p:ans){
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}