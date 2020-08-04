// Input format:
// First line contains integer N
// N lines follow
// Each contains 6 space separated numbers representing Topic ID, current z-score - Z, Posts - P, Likes - L, Comments - C, Shares - S
//
// Output format:
// Print top 5 Topics each in a new line.
// Each line should contain two space separated integers, Topic ID and new z-score of the topic.
//
// Constraints:
// 1 = N = 106
// 1 = ID = 109
// 0 = Z, P, L, C, S = 109

// Now sort them according to the change in z-score. Change in z-score for IDs 999, 1001, 1002, 1003 is 100, 
// so sort them according to their ID (one with the higher ID gets priority). Similarly proceed further.
//
// After you get the top 5 list of Topic IDs according to the above criteria, find the new z-score from the table for each ID.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Details{
public:
    ll id;
    ll z_score;
    ll change_zscore;
};

struct comparator{
    bool operator()(Details d1,Details d2){
        if(d1.change_zscore == d2.change_zscore){
            return d1.id < d2.id;
        }
        return d1.change_zscore < d2.change_zscore;
    }
};

int main(){
    ll n;
    cin>>n;
    priority_queue<Details,vector<Details>,comparator> pq;
    for(ll i=0;i<n;i++){
        Details d;
        cin>>d.id;
        ll old_score;
        cin>>old_score;
        ll a,b,c,e;
        cin>>a>>b>>c>>e;
        ll new_zscore = a*50 + b*5 + c*10 + e*20;
        d.z_score = new_zscore;
        d.change_zscore =  new_zscore - old_score;
        pq.push(d);
    }
    ll count = 0;
    while(!pq.empty() && count < 5){
        Details d = pq.top();
        cout<<d.id<<" "<<d.z_score<<endl;
        pq.pop();
        count++;
    }
}
