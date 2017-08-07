#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

std::map<int,string> hDistanceMap;


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

void verticleTraversing(BinaryTreeNode* root, int currVerticleDistance){
// 	cout<<"called for "<<root->data<<" with height "<<currVerticleDistance<<"\n";
	if(!root) return;

	ostringstream str1;
 
    // Sending a number as a stream into output
    // string
    str1 << root->data;
    
		hDistanceMap[currVerticleDistance].append(' '+str1.str());
// 	}

	if(root->left) verticleTraversing(root->left, currVerticleDistance-1);

	if(root->right) verticleTraversing(root->right, currVerticleDistance+1);

}


int main(){
	// struct BinaryTreeNode *root = NULL;


	 	struct BinaryTreeNode *root = newNode(1);
	  root->left        = newNode(2);
	  root->left->left  = newNode(4);

	  root->right  = newNode(3);
	  root->right->left  = newNode(5);


    

    verticleTraversing(root, 0);

     for (std::map<int,string>::iterator it=hDistanceMap.begin(); it!=hDistanceMap.end(); ++it)
    		std::cout<< (it->second).substr(1) << '\n';

	return 0;
}