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

void reverseLLInK(struct node* start, int k){

	if(start){
		int reversed = 0;         
		struct node* curr = start;
		struct node* prev = NULL;
		struct node* next = start->next;

		while(reversed < k &&  curr){
			
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next->next;
			// cout<<"temp->next :"<<temp->next<<endl;

			reversed++;
		}

		// cout<<"Current is :"<<curr->value<<endl;

		start->next = curr;

		if(start == head){
			
			head = prev;
		}

		// reverseLLInK(next, k);
		
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

	cout<<"Before Reversing"<<endl;
	printLinkedList();

	reverseLLInK(head, 7);

	cout<<"After Reversing"<<endl;
	printLinkedList();

	
}