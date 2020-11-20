#include<bits/stdc++.h>
using namespace std;

class Job{
public:
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> arr, int n){
    sort(arr.begin(),arr.end(),cmp);
    vector<int> result(n);
    vector<bool> slot(n);
    for(int i=0;i<n;i++){
        slot[i] = false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    int profit = 0;
    cout<<"Maximum profit is obtained by sequenc : ";
    for(int i=0;i<n;i++){
        if(slot[i]){
            profit += (arr[result[i]].profit);
            cout<<arr[result[i]].id<<" ";
        }
    }
    cout<<endl;
    cout<<"Maximum profit is : "<<profit<<endl;
}

int main(){
    vector<Job> arr;
    arr.push_back({'a', 2, 100});
    arr.push_back({'b', 1, 19});
    arr.push_back({'c', 2, 27});
    arr.push_back({'d', 1, 25});
    arr.push_back({'e', 3, 15}); 
    int n = arr.size();
    jobScheduling(arr, n); 
    return 0;
}