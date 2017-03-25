#include<iostream>
#include<stdlib.h>
#include<cstdio>

using namespace std;

int blockSize;

struct listNode {
	int value;
	struct listNode * next;
};

struct listBlock{
	struct listNode* first;
	struct listBlock* next;
	int nodeCount;
};

//pointer to first block
struct listBlock* firstBlock;

//create new list node
struct listNode* newListNode(int value){
	struct listNode* tempListNode = (struct listNode*)malloc(sizeof(struct listNode));
	tempListNode->next = NULL;
	tempListNode->value = value;

	return tempListNode;
}

//create new list block
struct listBlock* newListBlock(){
	struct listBlock* tempListBlock = (struct listBlock*) malloc(sizeof(struct listBlock));
	tempListBlock->first = NULL;
	tempListBlock->next = NULL;
	tempListBlock->nodeCount = 0;

	return tempListBlock;
}

struct listBlock* getBlockFromBlockNumber(int blockNumber){
	int blockIndex = 0;
	struct listBlock* preBlockPtr = NULL;
	struct listBlock* blockPtr = firstBlock;

	if(!firstBlock){
		return NULL;
	}
	else{
		while(blockIndex < blockNumber && blockPtr){
			preBlockPtr = blockPtr;
			blockPtr = blockPtr->next;
			blockIndex++;
		}
	}

	if(!blockPtr){
		blockPtr = newListBlock();
		preBlockPtr->next = blockPtr;
	}

	return blockPtr;
}


void addElement(int insertIndex, int insertValue){
	if(!firstBlock){
		firstBlock = newListBlock();

		struct listNode* tempNode = newListNode(insertValue);
		tempNode->next = tempNode;

		firstBlock->first = tempNode;
		firstBlock->nodeCount++;
	}
	else{
		 int blockNumber = insertIndex/blockSize;
		 int nodeNumberInBlock = insertIndex % blockSize;

		 struct listBlock* toInsertBlock = getBlockFromBlockNumber(blockNumber);
		 struct listNode* toInsertNode = newListNode(insertValue);
		 struct listNode* currentNodeInBlock = toInsertBlock->first;


		 if(!toInsertBlock){
		 	cout<<"Invalid block number to insert";
		 }
		 else{

			//if have to insert at first index in any block
			 if(nodeNumberInBlock == 0){
			 	
			 	//if it's a new block 
			 	if(toInsertBlock->nodeCount == 0){

			 		toInsertNode->next = toInsertNode;
			 		toInsertBlock->first = toInsertNode;
			 		toInsertBlock->nodeCount++;
			 	}
			 	else{
			 		toInsertBlock->first = toInsertNode;

			 		int numberOfNodesInBlock = toInsertBlock->nodeCount;

			 		//get last in block to set it's next node to newly inserted node
			 		for(int i = 0; i < numberOfNodesInBlock-1;i++){
			 			currentNodeInBlock = currentNodeInBlock->next;
			 		}

			 		currentNodeInBlock->next = toInsertNode;
			 		toInsertBlock->nodeCount++;

			 	}
			 	// struct listNode* firstNodeInBlock = toInsertBlock->first;

			 	// toInsertNode->next = firstNodeInBlock;

			 	// toInsertBlock->first = 
			 }
			 else{
			 	// cout<<"In else inserting :"<<insertValue<<endl;
			 	for(int i = 0; i < nodeNumberInBlock - 1; i++){
			 		currentNodeInBlock = currentNodeInBlock->next;
			 	}

			 	toInsertNode->next = currentNodeInBlock->next;
			 	currentNodeInBlock->next = toInsertNode;
			 	toInsertBlock->nodeCount++;

			 }
		}
	}
}

void printUnrolledLL(){
	struct listBlock* curr = firstBlock;
	int blockCount = 0;
	while(curr){
		cout<<"Block :"<<blockCount<<" nodes :"<<curr->nodeCount<<endl;
		int nodeCount = curr->nodeCount;
		struct listNode* currNode = curr->first;

		for(int i =0; i < nodeCount; i++){
			cout<<currNode->value<<" ,";
			currNode = currNode->next;
		}
		curr = curr->next;
		blockCount++;
		cout<<endl;
	}
}


int main(){

	blockSize = 4;
	addElement(0,1);
	addElement(1,2);
	addElement(1,12);

	addElement(2,3);
	addElement(3,4);
	addElement(1,11);
	addElement(4,5);
	addElement(5,6);
	addElement(6,7);
	addElement(7,8);
	addElement(8,9);
	addElement(9,10);
	// addElement(25,15);



	printUnrolledLL();
}