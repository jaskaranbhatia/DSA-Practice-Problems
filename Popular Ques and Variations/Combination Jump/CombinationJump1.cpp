/* 
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

*/

#include<bits/stdc++.h>
using namespace std;

void generateRes(vector<int> &candidates, int target, int l, int r, int sum, vector<int> &res, vector<vector<int>> &ans){
    if(sum>target){
        return;
    }
    else if(sum == target){
        ans.push_back(res);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            sum += candidates[i];
            res.push_back(candidates[i]);
            generateRes(candidates, target, i, r, sum, res, ans);
            res.pop_back();
            sum -= candidates[i];
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> res;
    vector<vector<int>> ans;
    generateRes(candidates, target, 0, candidates.size()-1, 0, res, ans);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> candidates(n);
    for(int i=0; i<n; i++){
        cin>>candidates[i];
    }
    int target;
    cin>>target;
    vector<vector<int>> result = combinationSum(candidates, target);
    for(auto v: result){
        for(auto ele:v){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}