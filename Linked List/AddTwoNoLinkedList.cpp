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

void insert(Node *&head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node* addTwoLL(Node *h1,Node *h2){
    int sum,carry = 0;
    Node *newLL = NULL;
    Node *res;
    while(h1 != NULL || h2 != NULL){
        if(h1 != NULL && h2 != NULL){
            sum = h1->data + h2->data + carry;
            if(newLL == NULL){
            	newLL = new Node(sum%10);
            	res = newLL;
			}
			else{
				newLL->next = new Node(sum%10);
				newLL = newLL->next;
			}
            carry = sum/10;
            h1 = h1->next;
            h2 = h2->next;
        }
        else if(h1 == NULL && h2 != NULL){
            sum = h2->data + carry;
            if(newLL == NULL){
            	newLL = new Node(sum%10);
            	res = newLL;
			}
			else{
				newLL->next = new Node(sum%10);
				newLL = newLL->next;
			}
            carry = sum/10;
            h2 = h2->next;
        }
        else if(h1 != NULL && h2 == NULL){
            sum = h1->data + carry;
            if(newLL == NULL){
            	newLL = new Node(sum%10);
            	res = newLL;
			}
			else{
				newLL->next = new Node(sum%10);
				newLL = newLL->next;
			}
            carry = sum/10;
            h1 = h1->next;
        }
    }
    if(carry > 0){
        newLL->next = new Node(carry);
    }
    return res;
}

int main(){
    Node *h1 = NULL, *h2 = NULL;
    insert(h1,9);
    insert(h1,9);
    insert(h2,9);
    insert(h2,9);
    Node *ans = addTwoLL(h1,h2);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
}
