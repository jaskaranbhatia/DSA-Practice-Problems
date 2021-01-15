/* 
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums){
    int lastPos = nums.size()-1;
    for(int i=nums.size()-2; i>=0; i--){
        if(i + nums[i] >= lastPos){
            lastPos = i;
        }
    }
    return lastPos == 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    if(isPossible(nums)){
        cout<<"Can reach the end"<<endl;
    }
    else{
        cout<<"Can not reach the end"<<endl;
    }
}