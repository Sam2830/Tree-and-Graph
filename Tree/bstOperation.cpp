//BST all
#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  //constructor
  Node(int item){
    data=item;
    left=NULL;
    right=NULL;
  }

};

Node* search(Node *node,int num){
  if(node==NULL||node->data==num) return node;
  else if(node->data<num) search(node->right,num);
  else search(node->left,num);
  return node;
}

Node* insert(Node* node,int key){
  if(node==NULL) return new Node(key);
  else if(node->data==key) return node;
  else if(node->data < key) node->right=insert(node->right,key);
  else  node->left=insert(node->left,key);
  return node;
}

void inorder(Node* node){
  if(node!=NULL){
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
  }
}


int main(){
  Node* root=new Node(50);
  root=insert(root,30);
  root=insert(root,70);
  root=insert(root,20);
  root=insert(root,60);
  root=insert(root,80);
  root=insert(root,35);
  root=insert(root,10);
  //print call
  //inorder(root);
  //cout<<root->data<<" ";
  int option;
  cout<<"\n\n Binary Search Tree Operation\n";
  cout<<"\n1.Search\n2.Insert\n3.Delete\n4.Traverse the list\n";
  cout<<"\nEnter your Choice: ";
  cin>>option;

  switch(option){
    case 1:
      int sNum;
      cout<<"Enter the number: ";
      cin>>sNum;
      (search(root,sNum)!=NULL) ? cout<<"Found\n":cout<<"NOT Found";
      break;
    case 2:
      int num;
      cout<<"Insert your number: ";
      cin>>num;
      root=insert(root,num);
      cout<<"After Inserting\n";
      inorder(root);
      break;
    case 3: break;
    case 4:
      inorder(root);
      break;
    // default:
    // break;
  }

  return 0;
}
