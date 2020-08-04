#include<bits/stdc++.h>
using namespace std;

int setNthBit(int num,int n){
	int new_num = num | (1<<n-1);
	return new_num;
}

int main(){
	int num = 5;
	cout<<setNthBit(num,2);
}
