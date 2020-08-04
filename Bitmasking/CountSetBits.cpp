#include<bits/stdc++.h>
using namespace std;

int noOfSetBitsSlow(int num){
	int count = 0;
	while(num > 0){
		count += (num & 1);
		num = num>>1;
	}
	return count;
}

int noOfSetBits(int num){
	int count = 0;
	while(num > 0){
		num = num & (num-1);
		count++;
	}
	return count;
}

int main(){
	int num = 31;
	cout<<noOfSetBits(num)<<endl;
	return 0;
}
