#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
    int flag = 0;
    for(int i=2;i<=sqrt(num);i++){
        if(num % i == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return false;
    }
    else{
        return true;
    }
}

void printPrime(int n){
    if(n>=2){
        cout<<2<<endl;
    }
    for(int i=3;i<=n;i++){
        if(!n&1){
            continue;
        }
        if(checkPrime(i)){
            cout<<i<<endl;
        }
    }
}

int main(){
    printPrime(50);
    return 0;
}