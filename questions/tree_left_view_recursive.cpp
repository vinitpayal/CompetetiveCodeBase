/**
	online ide link -> https://repl.it/JcKM/2
**/
#include <iostream>
#include <stdlib.h>

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


int maxLevel = -1;

void leftViewOfTree(struct BinaryTreeNode * root, int currLevel){
    
    if(!root) return;
    
    if(currLevel > maxLevel) {
      cout<<root->data<<" ";
      // cout<<root->data<<" --> and level --> "<<currLevel<<" maxLevel -->"<<maxLevel<<"\n";
      maxLevel = currLevel;
    }	
    
    leftViewOfTree(root->left, currLevel+1 );
    leftViewOfTree(root->right, currLevel+1);
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
    BSTInsertion(root, 90);
    BSTInsertion(root, 100);


    

    cout<<endl<<"------------Left view------"<<endl;
    leftViewOfTree(root, 0);

	return 0;
}