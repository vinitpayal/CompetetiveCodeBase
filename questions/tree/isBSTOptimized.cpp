/**
  repl link --> https://repl.it/Jce2/1
**/
#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

bool isBST(struct node* root, int min, int max){
    if(!root) return true;
    cout<<"For "<<root->data<<" min "<<min<<" max "<<max<<endl;
    if(root->data > max || root->data < min) return false;
    return isBST(root->left,min, root->data) && isBST(root->right, root->data, max);
}

struct node* newNode(int data){
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int main()
{
  struct node *root = newNode(20);
  root->left        = newNode(10);
  root->left->left  = newNode(5);
  root->left->left->left  = newNode(1);
  root->left->left->right  = newNode(50);

  if(isBST(root, INT_MIN, INT_MAX))
    cout<< "Is BST";
  else
     cout<< "Not a BST";
     
  return 0;
} 