#include<bits/stdc++.h>
using namespace std;

class Item{
public:
	int value;
	int weight;
	Item(int val,int we){
		value = val;
		weight = we;
	}
};

struct compareFnc { 
    bool operator()(Item p1, Item p2) 
    { 
        double r1 = (double)p1.value/p1.weight;
	    double r2 = (double)p2.value/p2.weight;
	    return r1<r2;
    } 
}; 

int main(){
    int W = 50;
	Item arr[3]  {{60, 10}, {100, 20}, {120, 30}};
	int n = sizeof(arr) / sizeof(arr[0]); 
    priority_queue<Item, vector<Item>, compareFnc> Q; 
    for(int i=0;i<n;i++){
        Q.push(arr[i]);
    }
    int curWeight = 0;
	double finalValue = 0.0;
    while(!Q.empty()){
        Item p = Q.top();
        if(curWeight + p.weight <= W){
			curWeight += p.weight;
			finalValue += p.value;
		}
        else{
			int remain = W - curWeight;
			finalValue += p.value * ((double)remain/p.weight);
			break;
		}
        Q.pop();
    }
    cout << "Maximum value we can obtain = "<< finalValue << endl; 
}