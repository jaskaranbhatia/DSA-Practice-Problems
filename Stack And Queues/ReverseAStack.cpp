#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int top_v = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top_v);
}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int top_v = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, top_v);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}