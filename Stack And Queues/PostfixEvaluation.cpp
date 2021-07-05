#include<bits/stdc++.h>
using namespace std;

int eval(string expr){
    stack<int> s;
    for(int i=0; i<expr.length(); i++){
        if(expr[i] >= '0' && expr[i] <= '9'){
            s.push(expr[i] - '0');
        }
        else{
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch(expr[i]){
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }
    return s.top();
}

int main(){
    string expr;
    cin>>expr;
    int ans = eval(expr);
    cout<<ans<<endl;
}