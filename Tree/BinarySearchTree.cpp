#include <iostream>
using namespace std;
//Node structure defining
struct Node{
  int data;
  Node *left,*right;
};
//Node creation 
Node* create(int item){
  Node* node= new Node;
  node->data=item;
  node->left=node->right=NULL;
  return node;
}

//Print function 
void inorder(Node *root){
  if(root==NULL) return;
  inorder(root->left);//recursive call
  cout<<root->data<<" ";
  inorder(root->right);
}

//Insertion at tree 
Node* insertion(Node* root,int item){
  
  if(root==NULL) return create(item);
  if(item < root->data) root->left=insertion(root->left, item);
  else root->right=insertion(root->right, item);
  
  return root;
}
//findMinimum Function
Node* findMinimum(Node* curr){
  while(curr->left!=NULL){
    curr=curr->left;
  }
  return curr;
}

//Search Function
void search(Node*& curr,int item,Node*&parent){
  while(curr!=NULL && curr->data!=item){
    parent=curr;
    if(item<curr->data) curr=curr->left;
    else curr=curr->right;
  }
  
}

//Deletion Function
void deletion(Node*&root,int item){
  Node* parent=NULL;
  Node* curr=root;
  search(curr,item,parent);
  if (curr==NULL) return;
  if(curr->left==NULL && curr->right==NULL){
    if(curr!=root) {
      if(parent->left==curr) parent->left=NULL;
      else parent->right=NULL;
    }
    else root=NULL;
    delete curr;
  }
  else if(curr->left&&curr->right){
    Node* success=findMinimum(curr->right);
    int val=success->data;
    deletion(root,success->data);
    curr->data=val;
  }
  else {
    Node* child=(curr->left)? curr->left:curr->right;
    if(curr!=root){
    if(curr==parent->left) parent->left=child;
    else parent->right=child;
    }
    else root=child;
    delete curr;
    
  }
  
}

//Driver Function
int main() 
{
    Node* root=NULL;
    root=insertion(root,45);
    root=insertion(root,30);
    root=insertion(root,50);
    root=insertion(root,25);
    root=insertion(root,35);
    root=insertion(root,60);
    root=insertion(root,4);
    
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    
    //Deletion Command 
    deletion(root,25);
    cout<<"After deleting 25: ";
    inorder(root);
    cout<<endl;
    
    //Again Inserting 10;
    insertion(root,10);
    cout<<"After inserting 10: ";
    inorder(root);
    cout<<endl;
    
    
    
    return 0;
}