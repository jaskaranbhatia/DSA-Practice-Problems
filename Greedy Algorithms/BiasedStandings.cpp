#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		int arr[100000] = {0};
		string name;
		int n,rank;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>name>>rank;
			arr[rank]++;
		}
		//Greedy Approach
		int actual_rank = 1;
		int sum = 0;
		for(int i=1;i<=n;i++){
			while(arr[i]){
				sum += abs(actual_rank - i);
				arr[i]--;
				actual_rank++;
			}
		}
		//The answer is the total badness
		cout<<sum<<endl;
	}
	return 0;
}
