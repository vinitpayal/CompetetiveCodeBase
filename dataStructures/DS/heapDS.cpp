#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
class HeapDS
{
	// int capacity=1000000;
	// void insert();
	// void delete();
	 public:
	 	 int size;
		 int heapArray[1000002];
		 int getMinElement(HeapDS &heap){
		 	return heap.heapArray[1];
		}
		void insert(HeapDS &heap,int valueToInsert){
			// cout<<"Inserting "<<valueToInsert<<endl;
			int currentChildIndex=++heap.size;
			// cout<<"heap size "<<heap.size<<endl;

			heap.heapArray[currentChildIndex]=valueToInsert;
			filterUp(heap,currentChildIndex);
			// cout<<"After Iteration :";
			// 	for(int i=1;i<=heap.size;i++){
			// 		cout<<heap.heapArray[i]<<" ";
			// 	}
			//  	cout<<endl;

		}
		void deleteNode(HeapDS &heap,int valueToDelete){
			int indexOfDeletingElement;
			for(int i=1;i<=heap.size;i++){
				if(heap.heapArray[i]==valueToDelete){
					// cout<<"deleting Index :"<<indexOfDeletingElement;
					indexOfDeletingElement=i;
				}
			}

			heap.heapArray[indexOfDeletingElement]=heap.heapArray[heap.size];
			heap.size--;
			int parent=indexOfDeletingElement/2;
			if(heap.heapArray[indexOfDeletingElement]<heap.heapArray[parent]){
				//filter up
				heap.filterUp(heap,indexOfDeletingElement);

			}
			else{
				//filter down
				heap.filterDown(heap,indexOfDeletingElement);
			}




		}

		void filterUp(HeapDS &heap,int indexInArray){//Index of array for which filter up has to be done
			int currentChildIndex=indexInArray;
			int parent=currentChildIndex/2;

			while(heap.heapArray[parent]>heap.heapArray[currentChildIndex]){
				int tempVar=heap.heapArray[currentChildIndex];
				heap.heapArray[currentChildIndex]=heap.heapArray[parent];
				heap.heapArray[parent]=tempVar;

				currentChildIndex=parent;
				parent=currentChildIndex/2;

			}

		}
		void filterDown(HeapDS &heap,int indexInArray){

			int lChildIndex=indexInArray*2;
			int rChildIndex=indexInArray*2+1;
			 int minValueIndex;
			 int parent=indexInArray;
			if(rChildIndex<=heap.size){
				minValueIndex=(heap.heapArray[lChildIndex]<heap.heapArray[rChildIndex])? lChildIndex:rChildIndex;
			}
			else if(lChildIndex<=heap.size){
				minValueIndex=lChildIndex;
			}

			while(heap.heapArray[parent]>heap.heapArray[minValueIndex] && lChildIndex<=heap.size){
				
				int tempVar=heap.heapArray[minValueIndex];
				heap.heapArray[minValueIndex]=heap.heapArray[parent];
				heap.heapArray[parent]=tempVar;

				parent=minValueIndex;
				lChildIndex=parent*2;
				rChildIndex=parent*2+1;

				if(rChildIndex<=heap.size){
						minValueIndex=(heap.heapArray[lChildIndex]<heap.heapArray[rChildIndex])? lChildIndex:rChildIndex;
				}
				else{

					minValueIndex=lChildIndex;
				}
			}
			// cout<<"After filterDown :";
			// for(int i=1;i<=heap.size;i++){
			// 	cout<<heap.heapArray[i]<<" ";
			// }

			// cout<<"filterDown end"<<endl;
			

		}

};
int main()
{
	HeapDS heap;
	heap.heapArray[0]=INT_MIN;

	int q,queryType,valueEntered;
	cin>>q;

	while(q--){
		cin>>queryType;
		// cout<<"Type: "<<queryType;
		if(queryType==1){
			cin>>valueEntered;
			heap.insert(heap,valueEntered);
		}
		else if(queryType==2){
			cin>>valueEntered;
			 heap.deleteNode(heap,valueEntered);
		}
		else{
			cout<<heap.getMinElement(heap)<<endl;
		}
		
	}
	return 0;
}