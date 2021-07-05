#include<bits/stdc++.h>
using namespace std;

bool checkNthBit(int num,int i){
	if(num | ~(1<<i-1)){
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




