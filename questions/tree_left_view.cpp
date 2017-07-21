/**
	online ide link -> https://repl.it/JcHi/1
**/
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <tuple>

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


void leftViewOfTree(struct BinaryTreeNode * root){
	
	tuple<BinaryTreeNode*,int> currTuple;

	queue<tuple<BinaryTreeNode*, int>> q;

	BinaryTreeNode * currNode;
	int currHeight;

	int maxLevelSofar = -1;

	q.push(make_tuple(root, 0));

	while(! q.empty()){
		currNode = (BinaryTreeNode*) get<0>(q.front());
		currHeight = (int) get<1>(q.front());

		q.pop();

		if(currHeight > maxLevelSofar){
			cout<<currNode->data<<" ";
			maxLevelSofar = currHeight;
		}

		if(currNode->left){
			q.push(make_tuple(currNode->left, currHeight + 1));
		}

		if(currNode->right){
			q.push(make_tuple(currNode->right, currHeight + 1));
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
    BSTInsertion(root, 90);
    BSTInsertion(root, 100);


    

    cout<<endl<<"------------Left view------"<<endl;
    leftViewOfTree(root);

	return 0;
}