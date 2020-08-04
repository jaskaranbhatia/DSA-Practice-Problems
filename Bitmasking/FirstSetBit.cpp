#include<bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n){
    if(n==0)
    {
        return 0;
    }
    int i=0;
    while((n&(1<<i))==0)
    {
        i++;
    }
    return i+1;
}

int main(){
	int num = 24;
	cout<<returnFirstSetBit(num);
}
