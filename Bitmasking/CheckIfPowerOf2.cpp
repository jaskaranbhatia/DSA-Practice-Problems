#include<bits/stdc++.h>
using namespace std;

bool checkPowerOf2(int num){
	if((num & (num-1)) == 0){
		return true;
	}
	else{
		return false;
	}	
}

int main(){
	int num = 128;
	if(checkPowerOf2(num)){
		cout<<"The number is a power of 2";
	}
	else{
		cout<<"The number is not a power of 2";
	}
}
