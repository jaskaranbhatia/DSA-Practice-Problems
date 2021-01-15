/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int profit = 0;
    int min_price = INT_MAX;
    for(int price:prices){
        min_price = min(min_price, price);
        profit = max(profit, price - min_price);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    cout<<maxProfit(prices)<<endl;
}