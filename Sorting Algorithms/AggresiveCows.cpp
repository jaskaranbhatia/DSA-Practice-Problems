#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stall,int n,int c,int distance){
	int count = 1;
	int lastPosition = stall[0];
	for(int i=1;i<n;i++){
		if(stall[i] - lastPosition >= distance){
			lastPosition = stall[i];
			count++;
		}
		if(count == c){
			return true;
		}
	}
	return false;
}

int main(){
	int n,c;
	cin>>n>>c; // n is no of stalls and c is no of cows
	vector<int> stall(n);
	for(int i=0;i<n;i++){
		cin>>stall[i];
	}
	sort(stall.begin(),stall.end());
	int start = 0;
	int end = stall[n-1] - stall[0];
	int ans = -1;
	while(start<=end){
		int mid = start + (end-start)/2;
		if(isPossible(stall,n,c,mid)){
			ans = mid;
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	cout<<ans<<endl;
}
