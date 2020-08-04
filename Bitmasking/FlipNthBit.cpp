#include<bits/stdc++.h>
using namespace std;

// x ^ 0 = x;
// x ^ 1 = ~x;
int flipNthBit(int num,int n){
	return num^(1<<n-1);
}

int main(){
	int num = 5;
	cout<<flipNthBit(num,2);
}
