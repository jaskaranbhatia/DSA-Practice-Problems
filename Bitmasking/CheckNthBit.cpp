#include<bits/stdc++.h>
using namespace std;

bool checkNthBit(int num,int n){
	if(num & (1<<n-1)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int num = 5;
	int pos = 1;
	if(checkNthBit(num,pos)){
		cout<<"Bit is set";
	}
	else{
		cout<<"Bit is not set";
	}
}




