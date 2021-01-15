/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &nums){
    int n = nums.size();
    vector<int> jumps(n);
    jumps[0] = 0;
    for(int i=1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(j + nums[j] >= i && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Minimum no. of jumps are: "<<minJumps(nums)<<endl;
}