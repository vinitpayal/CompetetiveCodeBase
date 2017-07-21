#include<iostream>
#include<stdlib.h>
#include<queue>
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


void levelOrderTraversal(struct BinaryTreeNode * root){
	std::queue<BinaryTreeNode *> q;

	BinaryTreeNode * currNode;

	q.push(root);
	
	while(! q.empty()){
		currNode = q.front();
		q.pop();

		if(currNode->left) q.push(currNode->left);
		if(currNode->right) q.push(currNode->right);

		cout<<currNode->data<<" ";

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

    cout<<endl<<"------------Level Order------"<<endl;
    levelOrderTraversal(root);

	return 0;
}