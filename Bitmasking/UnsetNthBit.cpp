#include<bits/stdc++.h>
using namespace std;

int unSetNthBit(int num,int n){
	if(num & (1<<n-1)){
		return num & ~(1<<n-1);
	}
	else{
		return num;
	}
}

int main(){
	int num = 5;
	cout<<unSetNthBit(num,1);	
}
