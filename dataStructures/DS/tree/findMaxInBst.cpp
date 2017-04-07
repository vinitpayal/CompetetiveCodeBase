#include<iostream>
#include<stdlib.h>
#include<stack>
#include<climits>
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

void preOrder(struct BinaryTreeNode *node){

	if(node){
		cout<<node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void levelOrder(struct BinaryTreeNode* root){
	queue<struct BinaryTreeNode*> q;

	if(root) q.push(root);

	while(!q.empty()){
		struct BinaryTreeNode* curr = q.front();
		cout<<curr->data<<", ";
		q.pop();

		if(curr->left){
			q.push(curr->left);
		}

		if(curr->right){
			q.push(curr->right);
		}

	}

	// free(q);
}

int findMax(struct BinaryTreeNode* node){
	int left, right, max = INT_MIN;

	if(node){
		left = findMax(node->left);
		right = findMax(node->right);

		if(left > right) max = left;
		else max = right;

		if(node->data > max) max = node->data; 
	}
	return max;
}

bool findAnElementInBST(struct BinaryTreeNode* root, int valueLookingFor){
	if(root){
		if(root->data == valueLookingFor) return true;

		return findAnElementInBST(root->left, valueLookingFor) || findAnElementInBST(root->right, valueLookingFor);
	}
	else{
		return false;
	}
}

int calculateSizeOfBST(struct BinaryTreeNode* root){
	if(root) return 1 + calculateSizeOfBST(root->left) + calculateSizeOfBST(root->right);

	else return 0;
}

int calculateHeightOfBst(struct BinaryTreeNode* root){
	if(root){
		return 1 + max(calculateHeightOfBst(root->left), calculateHeightOfBst(root->right));
	}
	else{
		return 0;
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
    BSTInsertion(root, 10);


    cout<<"max value in BST :"<<findMax(root)<<"\n";

    cout<<"Loooking for element 20 in BST :"<<findAnElementInBST(root, 81)<<"\n";

    cout<<"size of bst :"<<calculateSizeOfBST(root)<<"\n";

    cout<<"Height of BST : "<<calculateHeightOfBst(root)<<"\n";

    cout<<"Level Order Of Tree \n";
    levelOrder(root);

    cout<<"\n";


	return 0;
}