#include<iostream>
#include<cstdlib>
using namespace std;

struct node* head;
struct node* last;

struct node{
	int value;
	struct node* next;
};

struct node* newNode(int value){
	struct node* tempNode = (struct node*)malloc(sizeof(struct node));	
	tempNode->next = NULL;
	tempNode->value = value;

	return tempNode;
}

void insertAtLast(int value){
	struct node* tempNode = newNode(value);

	if(!head){
		head = tempNode;
		last = tempNode;
	}
	else{
		last->next = tempNode;
		last = tempNode;
	}
}

  void printLinkedList(){
	struct node* curr = head;

	while(curr){
		cout<<curr->value<<"->";
		curr = curr->next;
	}
}

void reverseLLInK(struct node* start,struct node* lastBlockLastNode, int k){

	if(start){
	}
}	

int main(){
	insertAtLast(10);
	insertAtLast(11);
	insertAtLast(12);
	insertAtLast(13);
	insertAtLast(14);
	insertAtLast(15);
	insertAtLast(16);
	insertAtLast(17);
	insertAtLast(18);


	cout<<"Before Reversing"<<endl;
	printLinkedList();

	reverseLLInK(head,NULL,3);

	cout<<"After Reversing"<<endl;
	printLinkedList();

	
}