#include<iostream> 
#include<unordered_map> 
using namespace std; 
  
struct Node 
{ 
    int key; 
    struct Node* left, *right, *random; 
}; 

  
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->random = temp->right = temp->left = NULL; 
    return (temp); 
} 
  

void printInorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    
    printInorder(node->left); 
  
    
    cout << "[" << node->key << " "; 
    if (node->random == NULL) 
        cout << "NULL], "; 
    else
        cout << node->random->key << "], "; 
  
    printInorder(node->right); 
} 
  

Node* copyLeftRightNode(Node* treeNode, unordered_map<Node *, Node *> &mymap) 
{ 
    if (treeNode == NULL) 
        return NULL; 
    Node* cloneNode = newNode(treeNode->key); 
    mymap[treeNode] = cloneNode; 
    cloneNode->left  = copyLeftRightNode(treeNode->left, mymap); 
    cloneNode->right = copyLeftRightNode(treeNode->right, mymap); 
    return cloneNode; 
} 
  
void copyRandom(Node* treeNode,  Node* cloneNode, unordered_map<Node *, Node *> &mymap) 
{ 
    if (cloneNode == NULL) 
        return; 
    cloneNode->random =  mymap[treeNode->random]; 
    copyRandom(treeNode->left, cloneNode->left, mymap); 
    copyRandom(treeNode->right, cloneNode->right, mymap); 
} 
  
Node* cloneTree(Node* tree) 
{ 
    if (tree == NULL) 
        return NULL; 
    unordered_map<Node *, Node *> mymap; 
    Node* newTree = copyLeftRightNode(tree, mymap); 
    copyRandom(tree, newTree, mymap); 
    return newTree; 
} 
  
int main() 
{ 
    Node *tree = newNode(1); 
    tree->left = newNode(2); 
    tree->right = newNode(3); 
    tree->left->left = newNode(4); 
    tree->left->right = newNode(5); 
    tree->random = tree->left->right; 
    tree->left->left->random = tree; 
    tree->left->right->random = tree->right; 
  
    cout << "Inorder traversal of original binary tree is: \n"; 
    printInorder(tree); 
  
    Node *clone = cloneTree(tree); 
  
    cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
    printInorder(clone); 
  
    return 0; 
} 
