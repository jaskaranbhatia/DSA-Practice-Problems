/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array.
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Notice that you can not jump outside of the array at any time.
*/

#include<bits/stdc++.h>
using namespace std;

bool canReach(vector<int> nums, int start){
    int n = nums.size();
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;
    while(!q.empty()){
        int f = q.front();
        if(nums[f] == 0) return true;
        q.pop();
        if(f+nums[f] < n && !visited[f+nums[f]]){
            visited[f+nums[f]] = true;
            q.push(f+nums[f]);
        }
        if(f-nums[f] >= 0 && !visited[f-nums[f]]){
            visited[f-nums[f]] = true;
            q.push(f-nums[f]);
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int start;
    cin>>start;
    if(canReach(nums, start)){
        cout<<"Can Reach"<<endl;
    }
    else{
       cout<<"Can not reach"<<endl; 
    }
}