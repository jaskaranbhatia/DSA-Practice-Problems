#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int top = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(top);
}

void reverse(stack<int> &s){
	if(s.empty()){
		return;
	}
	int top = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,top);
}

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}
