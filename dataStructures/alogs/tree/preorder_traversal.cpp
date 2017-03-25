#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;


struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

stack<BinaryTreeNode*> nodeStack;

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

	return root;
}

void preOrder(struct BinaryTreeNode *node){

	if(node){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void preOrderWithOutRecursion(struct BinaryTreeNode *root){
	while(1){
		while(root){
			cout<<root->data<<" ";
			nodeStack.push(root);
			root = root->left;

		}

		if(!nodeStack.empty()){
			root = nodeStack.top();
			nodeStack.pop();

			// cout<<root->data<<" ";

			root = root->right;
		}else{
			break;
		}

	}	
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

    cout<<"-------Pre Order Witout Recursion-------"<<endl;
    preOrderWithOutRecursion(root);

    cout<<endl<<"------------preOrder with Recursion------"<<endl;
    preOrder(root);

	return 0;
}