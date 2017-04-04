#include<iostream>
#include<stdlib.h>
#include<stack>
#include<climits>
using namespace std;


struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};


/**
 Function to create a new node 
**/
struct BinaryTreeNode* newNode(int data){
	struct BinaryTreeNode* tempNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	tempNode->data = data;
	tempNode->left = NULL;
	tempNode->right = NULL;

	return tempNode;
}

struct BinaryTreeNode* BSTInsertion(struct BinaryTreeNode * root, int insertData){
	//tree is empty means this will be the only node of tree 
	//hence return this node 
	if(root == NULL) return newNode(insertData);

	if(insertData < root->data){
		root->left = BSTInsertion(root->left, insertData);
	}
	else if(insertData > root->data) {
		root->right = BSTInsertion(root->right, insertData);
	}

	// return root;
}

void preOrder(struct BinaryTreeNode *node){

	if(node){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

bool isBST(struct BinaryTreeNode* root, int min, int max){
	if(root == NULL) return true;

	if(root->data < min && root->data > max) return false;

	return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data+1, max);
}


int main()
{
	struct BinaryTreeNode *root = NULL;
    root = BSTInsertion(root, 50);
	
    BSTInsertion(root, 30);
    BSTInsertion(root, 20);
    BSTInsertion(root, 40);
    BSTInsertion(root, 70);
    BSTInsertion(root, 60);
    BSTInsertion(root, 80);

    cout<<"Preorder of tree\n";
    preOrder(root);

    cout<<"\n------------------\nIS BST:"<<isBST(root, INT_MIN, INT_MAX)<<"\n-------------------\n";

	return 0;
}