#include<bits/stdc++.h>
using namespace std;

int clearAllBits(int n, int i){
    int mask_initiator=(1<<(i));
    mask_initiator=mask_initiator-1;
    int mask=mask_initiator;
    return (mask&n);
}

// For LSB we can do -> mask = ~(mask_initiator);

int main(){
	cout<<clearAllBits(15,2);
}
