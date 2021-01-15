#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee){
    int best_without_stock = 0;
    int best_with_stock = INT_MIN;
    for(auto price:prices){
        best_without_stock = max(best_without_stock, best_with_stock + price);
        best_with_stock = max(best_with_stock, best_without_stock - price - fee);
    }
    return best_without_stock;
}

int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    int fee;
    cin>>fee;
    cout<<maxProfit(prices, fee)<<endl;
}