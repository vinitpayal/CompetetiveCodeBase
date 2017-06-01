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

void reverseLLInK(){
	struct node* start = head;
	struct node* curr = start;
	struct node* prev = NULL;
	struct node* next = NULL; 
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}	

struct node* recursiveReverse(struct node* current,struct node* prev){
	struct node* next = current->next;
	current->next = prev;
	if(next){
		recursiveReverse(next, current);
	}
	else{
		return current; 
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


	cout<<"Before Reversing\n";
	printLinkedList();

	// reverseLLInK();
	head = recursiveReverse(head, NULL);

	cout<<"\nAfter Reversing\n";
	printLinkedList();

	
}