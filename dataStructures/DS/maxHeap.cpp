#include<iostream>
#include<cstdlib>
using namespace std;

struct Heap{
	int *array;
	int capacity;
	int count;
};

int getChild(struct Heap* h, int i, char c){
	int childIndex;
	
	if(c == 'L') childIndex = 2*i + 1;
	else if(c == 'R') childIndex = 2*i + 2;

	if(childIndex >= h->count) return -1;

	return childIndex;
}

struct Heap* createHeap(int capacity){
	struct Heap* tempHeap = (struct Heap*) malloc(sizeof(struct Heap));		
	tempHeap->capacity = capacity;
	tempHeap->count = 0;
	tempHeap->array = (int*)malloc(sizeof(int)*capacity);

	return tempHeap;
}
/**
	P.No. => ME 197
**/
void maxHeapIfy(struct Heap* heap,  int index){
	int l, r, max, temp;

	l = getChild(heap, index, 'L');
	r = getChild(heap, index, 'R');

	if(l != -1 && heap->array[l] > heap->array[index]){
		max = l;
	}
	else{
		max = index;
	}

	if(r != -1 && heap->array[r] > heap->array[max]){
		max = r;
	}
	
	if(max != index){
		temp = heap->array[index];
		heap->array[index] = heap->array[max];
		heap->array[max] = temp;
		maxHeapIfy(heap, max); 
	}
}
/**
	P.No => 203
**/
void printElementsGreaterThenGiven(struct Heap* heap,int index,int data){
	if(heap->array[index] > data){
		cout<<heap->array[index]<<", ";
		int left = getChild(heap, index,'L');
		int right = getChild(heap, index, 'R');
		printElementsGreaterThenGiven(heap, left, data);
		printElementsGreaterThenGiven(heap, right, data);

	}
}

int deleteElement(struct Heap* heap){
	if(heap->count == 0) return -1;

	int data = heap->array[0];

	heap->array[0] = heap->array[heap->count - 1];
	heap->count --;

	maxHeapIfy(heap, 0);
}

void resizeHeap(struct Heap* heap){
	int* heap_old = heap->array;

	heap->array = (int *) malloc(heap->capacity * 2 * sizeof(int));

	for(int i = 0; i < heap->capacity; i++){
		heap->array[i] = heap_old[i];
	}

	heap->capacity *= 2; 
	free(heap_old);
}

void printHeapArray(struct Heap* heap){

	for(int i = 0; i < heap->count; i++){
		// cout<<"i:"<<i<<"\n";
		cout<<heap->array[i]<<",";
	}
}

void insertInHeap(struct Heap* heap,int data){
	if(heap->capacity == heap->count){
		resizeHeap(heap);
	}
	
	heap->array[heap->count] = data;
	heap->count ++;

	int i = heap->count - 1;

	while(i > 0 && data > heap->array[(i-1)/2]){
		heap->array[i] = heap->array[(i-1)/2];
		i = (i-1)/2;
	}

	heap->array[i] = data;
}



int main(){
	struct Heap* heap = createHeap(150);

	insertInHeap(heap, 31);
	insertInHeap(heap, 10);
	insertInHeap(heap, 16);
	insertInHeap(heap, 9);
	insertInHeap(heap, 8);
	insertInHeap(heap, 3);
	insertInHeap(heap, 30);

	insertInHeap(heap, 100);

	cout<<"Before delete \n";
	printHeapArray(heap);
	deleteElement(heap);

	// insertInHeap(heap, 5);
	// insertInHeap(heap, 7);
	// insertInHeap(heap, 1);
	// insertInHeap(heap, 19 );

	cout<<"\nAfter delete \n";
	printHeapArray(heap);

	cout<<"\nNumbers less then \n";
	printElementsGreaterThenGiven(heap, 0, 9);



}