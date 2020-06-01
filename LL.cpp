#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtTail(Node *&head,Node *&tail,int data){
	if(head == NULL){
		head = new Node(data);
		tail = head;
		return;
	}
	tail->next = new Node(data);
	tail = tail->next;
}

void print(Node *temp){
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Node *l1Head = NULL;
	Node *l1Tail = NULL;
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++){
		int data;
		cin>>data;
		insertAtTail(l1Head,l1Tail,data);
	}
	int mid = l1Head->data + l1Tail->data;
	Node *temp = l1Head;
	int count = 1;
	Node *l2Head = NULL, *l2Tail = NULL, *l3Head = NULL, *l3Tail = NULL;
	while(temp->next->next != NULL){
		if(count % 2 != 0){
			insertAtTail(l2Head,l2Tail,temp->data + temp->next->next->data);
		}
		else{
			insertAtTail(l3Head,l3Tail,temp->data + temp->next->next->data);
		}
		count++;
		temp = temp->next;
	}
	print(l2Head);
	print(l3Head);
	cout<<mid<<endl;
	Node *newl1Head = NULL;
	Node *newl1Tail = NULL;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(l1Head != NULL){
			insertAtTail(newl1Head,newl1Tail,l1Head->data);	
			l1Head = l1Head->next;
		}
		if(l2Head != NULL){
			insertAtTail(newl1Head,newl1Tail,l2Head->data);	
			l2Head = l2Head->next;
		}
	}
	insertAtTail(newl1Head,newl1Tail,mid);
	for(int i=0;i<n;i++){
		if(l1Head != NULL){
			insertAtTail(newl1Head,newl1Tail,l1Head->data);	
			l1Head = l1Head->next;
		}
		if(l3Head != NULL){
			insertAtTail(newl1Head,newl1Tail,l3Head->data);	
			l3Head = l3Head->next;
		}
	}
	print(newl1Head);
	int n_newl1 = 4*n - 1;
	cout<<n_newl1<<endl;
}

