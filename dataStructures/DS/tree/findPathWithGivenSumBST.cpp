/**
	Can be run at -> https://repl.it/HApF/0 as to_string is not working on local currently
	 bcz of g++ version
**/
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <climits>
#include <queue>
#include <string> 

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

bool pathWithGivenSum(struct BinaryTreeNode* root, int sum, string s){

	int effectiveSum = sum;
	int ans = 0;

	if(root == NULL) return (sum == 0);
	// cout<<"Called "<<root->data<<" with sum left :"<<sum;
	
	sum -= root->data;

	// s += (std::to_string(root->data) + "->");

	// cout<<" on leaving :"<<sum<<"\n";
	if(root->left == NULL && root->right == NULL) {if(sum == 0) cout<<s<<endl;return (sum == 0);}

	if(root->left) ans = ans || pathWithGivenSum(root->left, sum, s);
	if(root->right) ans = ans || pathWithGivenSum(root->right, sum, s);

	return ans;
}

int main()
{
	// string s = to_string(42);
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
    BSTInsertion(root, 25);
    BSTInsertion(root, 35);




  cout<<"Path with sum = 155 Exists ? "<<pathWithGivenSum(root, 200,"");

	return 0;
}