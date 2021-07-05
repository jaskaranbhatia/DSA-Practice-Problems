#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
}; 

void insertNode(Node *root,int data){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
		q.pop();
		if(f->left == NULL){
			f->left = new Node(data);
			break;
		}
		else{
			q.push(f->left);
		}
		if(f->right == NULL){
			f->right = new Node(data);
			break;
		}
		else{
			q.push(f->right);
		}
	}
}

bool searchNode(Node *root,int target){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
		if(f->data == target){
			return true;
		}
		q.pop();
		if(f->left != NULL){
			q.push(f->left);
		}
		if(f->right != NULL){
			q.push(f->right);
		}
	}
	return false;
}

void bfs(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *f = q.front();
		if(f == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left != NULL){
				q.push(f->left);
			}
			if(f->right != NULL){
				q.push(f->right);
			}
		}
	}
}

void findAverageLevel(Node* a)
{
    //write your code here
    queue<Node*> q;
    q.push(a);
    q.push(NULL);
    float count = 0;
    float sum = 0;
    while(!q.empty()){
      Node *f = q.front();
      sum += f->data;
      count++;
      q.pop();
      if(f == NULL){
        float avg = sum/count;
        cout<<avg<<" ";
        sum = 0;
        count = 0;
        if(!q.empty()){
          q.push(NULL);
        }
      }
      else{
        if(f->left != NULL){
          q.push(f->left);
        }
        if(f->right != NULL){
          q.push(f->right);
        }
      }
    }
}


int main(){
	Node *root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(4);
	root->left->left = new Node(2);
	root->right->right = new Node(1);
	findAverageLevel(root);
}
