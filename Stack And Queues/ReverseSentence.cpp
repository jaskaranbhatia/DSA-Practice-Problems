#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    stack<string> tokens;
    while(getline(ss, token, ' ')){
        tokens.push(token);
    }
    string ans;
    while(!tokens.empty()){
        ans += tokens.top();
        ans += ' ';
        tokens.pop();
    }
    cout<<ans<<endl;
}