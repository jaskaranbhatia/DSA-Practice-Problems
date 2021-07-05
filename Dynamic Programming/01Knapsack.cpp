#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n){
	vector< vector<int> > K(n+1,vector<int>(W+1,0));
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if (i == 0 || w == 0) 
                K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
		}
	}

    // Printing items of Knapsack
    int res = K[n][W];     
    int w = W; 
    for (int i = n; i > 0 && res > 0; i--) { 
        if (res == K[i - 1][w])  
            continue;         
        else { 
            cout<<wt[i - 1]<<" "; 
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    } 
	return K[n][W];
}

int main(){
	int val[] = { 60, 100, 120, 150, 200 }; 
    int wt[] = { 10, 20, 30, 40 ,50 }; 
    int W = 70; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<"\n"<<"The maximum value is : "<<knapSack(W, wt, val, n)<<"\n";
    return 0;
}
