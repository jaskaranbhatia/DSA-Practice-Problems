#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int subtask(){
	ll n,ans = 0;
	cin>>n;
	vector<<ll> tot;
	ll a;
	for(ll i=1;i<=20;i++){
		cout<<i<<" "<<(1ul<<i)<<endl;
		cout.flush();
		cin>>a;
		tot.push_back(a);
	}
	reverse(tot.begin(),tot.end());
	ll to = tot[0]-n*(1ul<<20);
	for(ll i=1;i<tot.size();i++){
		if(tot[i] >= to){
			tot[i] = ((n-(tot[i]-to)/(1ul<<(tot.size()-i)))/2);
		}
	}
	for(ll i=1;i<tot.size();i++){
		if(tot[i] % 2 ! = 0){
			ans += 1ul<<(tot.size()-1);
		}
		if(to % 2 != 0){
			ans++;
		}
		cout<<2<<" "<<ans<<endl;
		cout.flush();
		ll result;
		cin>>result;
		return result;
	}
}

int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		if(!subtask()) break;
		cout<<endl;
		cout.flush();
	}
	return 0;
}
