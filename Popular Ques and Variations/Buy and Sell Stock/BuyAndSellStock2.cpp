/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int best_without_stock = 0;
    int best_with_stock = INT_MIN;
    for(int price:prices){
        best_without_stock = max(best_without_stock, best_with_stock + price);
        best_with_stock = max(best_with_stock, best_without_stock - price);
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
    cout<<maxProfit(prices)<<endl;
}