#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode(){
        this->isEnd = false;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
    }
};

bool isEmpty(TrieNode *root){
    for(int i=0;i<26;i++){
        if(root->children[i] != NULL){
            return false;
        }
    }
    return true;
}

void insert(TrieNode *root, string key){
    TrieNode *temp = root;
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!temp->children[index]){
            temp->children[index] = new TrieNode();
        }
        temp = temp->children[index];
    }
    temp->isEnd = true;
}

bool search(TrieNode *root, string key){
    TrieNode *temp = root;
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!temp->children[index]){
            return false;
        }
        temp = temp->children[index];
    }
    return (temp != NULL && temp->isEnd == true);
}

TrieNode* remove(TrieNode *root, string key,int depth = 0){
    if(root == NULL){
        return NULL;
    }
    if(depth == key.size()){
        if(root->isEnd){
            root->isEnd = false;
        }
        if(isEmpty(root)){
            delete root;
            root = NULL;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index],key,depth+1);
    if(isEmpty(root) && root->isEnd == false){
        delete root;
        root = NULL;
    }
    return root;
}

int main(){
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]);
    TrieNode *root = new TrieNode();
    for(int i=0;i<n;i++){
        insert(root,keys[i]);
    }
    // remove(root,"their");
    if(isEmpty(root)){
        cout<<"Trie is Empty, cannot perform search\n";
    }
    else{
        search(root,"their") ? cout<<"Yes" : cout<<"No";
    }
    return 0; 
}