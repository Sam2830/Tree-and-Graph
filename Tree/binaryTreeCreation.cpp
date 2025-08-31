#include <iostream>
using namespace std;

//Structure for a node in the binary tree
struct Node{
  int data;
  Node* left;
  Node* right;

  //Constructor to initialize a new Node
  Node(int value): data(value),left(nullptr),right(nullptr){}


};

//Function to insert a node into the binary tree

Node* insert(Node* root,int value){
  if(root==nullptr) return new Node(value);

  else if(value< root->data)
    root->left=insert(root->left,value);

  else root->right=insert(root->right,value);

  return root;
}


//Function to print the binary tree in inorder traversal

void inorderTraversal(Node* root){
  if(root!=nullptr){
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
  }
}

int main()
{
    Node* root=nullptr;

    //Inserting nodes into the binary tree

    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    //printing the tree in inorder traversal

    cout<<"Inorder traversal of the binary tree: ";
    inorderTraversal(root);
    cout<<endl;
    return 0;
}
