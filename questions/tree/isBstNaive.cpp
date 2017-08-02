#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int getMinInChilds(struct node* root){
	if(! root) return INT_MAX;
	int leftMin = getMinInChilds(root->left);
	int rightMin = getMinInChilds(root->right);
	
	return min(min(root->data, leftMin), rightMin);
}

int getMaxInChilds(struct node* root){
	if(! root) return INT_MIN;
	int leftMax = getMaxInChilds(root->left);
	int rightMax = getMaxInChilds(root->right);
	
	return max(max(root->data, leftMax), rightMax);
}

bool isBST(struct node* root){
	if(!root) return true;
  
  int leftMax = getMaxInChilds(root->left);
  int rightMin = getMinInChilds(root->right);
  
  if(root->data == 1){cout<<"left min "<<leftMax<<" right max "<<rightMin<<endl;}
  
	if( (leftMax != INT_MIN && leftMax > root->data) ||  (rightMin !=  INT_MAX && root->data > rightMin)){
	 // cout<<"returning false for "<<root->data<<" leftMax "<<leftMax<<" rightMin "<<rightMin<<endl;
		return false;
	}
  
  
	return isBST(root->left)&&isBST(root->right);
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

  if(isBST(root))
    cout<< "Is BST";
  else
     cout<< "Not a BST";
     
  return 0;
} 