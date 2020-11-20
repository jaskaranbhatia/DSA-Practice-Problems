#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		pair<ll,ll> p[n];
		for(ll i=0;i<n;i++){
			cin>>p[i].second; //Putting Starting time as second
		}
		for(ll i=0;i<n;i++){
			cin>>p[i].first; //Putting Finishing time as First
		}
		sort(p,p+n);
		ll i=0,j=1,ans=1;
		while(i<n && j<n){
			if(p[i].first <= p[j].second){
				i = j;
				j++;
				ans++;
			}
			else{
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

