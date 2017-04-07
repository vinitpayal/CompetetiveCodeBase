#include<iostream>
#include<climits>
using namespace std;
// class Heap
// {
// public:
// 	virtual void insert();
// 	virtual void filterUp();
// 	virtual void filterDown();
// 	virtual void deleteRoot();
// 	// virtual void getTop();
// 	// Heap();
// 	// ~Heap();
	
//  };

class MinHeap
{
	 public:
	 	 int size=0;
		 int heapArray[1000002];

		void insert(MinHeap &minHeap,int valueToInsert){
			int currentChildIndex=++minHeap.size;
			// cout<<"heap size "<<heap.size<<endl;

			minHeap.heapArray[currentChildIndex]=valueToInsert;
			// cout<<"currentChildIndex :"<<currentChildIndex<<endl;
			filterUp(minHeap,currentChildIndex);
			filterDown(minHeap,currentChildIndex);

			// if(minHeap.size-maxHeap.size>=2){
			// 	int toInsertIntoMinHeap=minHeap.heapArray[1];
			// 	minHeap.deleteRoot(maxHeap);
			// 	maxHeap.insert(maxHeap,toInsertIntoMinHeap);
			// }


			// cout<<"After Iteration :";
			// 	for(int i=1;i<=heap.size;i++){
			// 		cout<<heap.heapArray[i]<<" ";
			// 	}
			//  	cout<<endl;

		}

		void deleteRoot(MinHeap &heap){
			int indexOfDeletingElement=1;
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
		

		void filterUp(MinHeap &heap,int indexInArray){//Index of array for which filter up has to be done
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
		void filterDown(MinHeap &heap,int indexInArray){

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
class MaxHeap{
	public:
	 	 int size=0;
		 int heapArray[1000002];
		//  double getMedian(HeapDS &heap){
		//  	if(heap.size%2==0){
		//  		float median=((float)heap.heapArray[heap.size/2]+(float)heap.heapArray[(heap.size/2)+1])/2;
		//  		return median;
		//  	}
		//  	else{
		//  		return (double)heap.heapArray[(heap.size/2)+1];
		//  		// cout<<"Odd size :"<<heap.size<<endl;
		//  	}
		//  	// return heap.heapArray[1];
		// }
		void insert(MaxHeap &maxHeap,int valueToInsert){
			int currentChildIndex=++maxHeap.size;
			// cout<<"heap size "<<heap.size<<endl;

			maxHeap.heapArray[currentChildIndex]=valueToInsert;
			// cout<<"currentChildIndex :"<<currentChildIndex<<endl;
			filterUp(maxHeap,currentChildIndex);
			// filterDown(maxHeap,currentChildIndex);

			// if(maxHeap.size-minHeap.size>=2){
			// 	int toInsertIntoMinHeap=maxHeap.heapArray[1];
			// 	maxHeap.deleteRoot(maxHeap);
			// 	minHeap.insert(minHeap,toInsertIntoMinHeap);
			// }

			// filterDown(heap,currentChildIndex);
			// cout<<"After Iteration :";
			// 	for(int i=1;i<=heap.size;i++){
			// 		cout<<heap.heapArray[i]<<" ";
			// 	}
			//  	cout<<endl;

		}

		void deleteRoot(MaxHeap &heap){
			int indexOfDeletingElement=1;

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
		

		void filterUp(MaxHeap &heap,int indexInArray){//Index of array for which filter up has to be done
			int currentChildIndex=indexInArray;
			int parent=currentChildIndex/2;

			while(heap.heapArray[parent]<heap.heapArray[currentChildIndex]){
				// cout<<" parent index :"<<parent<<"  ";
				int tempVar=heap.heapArray[currentChildIndex];
				heap.heapArray[currentChildIndex]=heap.heapArray[parent];
				heap.heapArray[parent]=tempVar;

				currentChildIndex=parent;
				parent=currentChildIndex/2;
				// cout<<" Parent :"<<heap.heapArray[parent]<<" child : "<<heap.heapArray[currentChildIndex]<<endl;

				


			}

		}
		void filterDown(MaxHeap &heap,int indexInArray){

			int lChildIndex=indexInArray*2;
			int rChildIndex=indexInArray*2+1;
			 int minValueIndex;
			 int parent=indexInArray;
			if(rChildIndex<=heap.size){
				minValueIndex=(heap.heapArray[lChildIndex]>heap.heapArray[rChildIndex])? lChildIndex:rChildIndex;
			}
			else if(lChildIndex<=heap.size){
				minValueIndex=lChildIndex;
			}

			while(heap.heapArray[parent]<heap.heapArray[minValueIndex] && lChildIndex<=heap.size){
				
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
		}
};

int main()
{
	int t,newNumber;
	MaxHeap maxHeap;
	MinHeap minHeap;
	maxHeap.heapArray[0]=INT_MAX;
	minHeap.heapArray[0]=INT_MIN;
	cin>>t;
	int i=1;

	while(t--){
		cin>>newNumber;
		if(newNumber<maxHeap.heapArray[1]){
			maxHeap.insert(maxHeap,newNumber);

			if(maxHeap.size-minHeap.size>=2){
				int toInsertIntoMinHeap=maxHeap.heapArray[1];
				maxHeap.deleteRoot(maxHeap);
				minHeap.insert(minHeap,toInsertIntoMinHeap);

			}
		}
		else{
			minHeap.insert(minHeap,newNumber);
			if(minHeap.size-maxHeap.size>=2){
				int toInsertIntoMinHeap=minHeap.heapArray[1];
				minHeap.deleteRoot(minHeap);
				maxHeap.insert(maxHeap,toInsertIntoMinHeap);
			}
		}
		// maxHeap.insert(maxHeap,minHeap,newNumber);
		// if(maxHeap.size==0){
		// 	// cout<<" Inserted into maxHeap"<<endl;
		// 	maxHeap.insert(maxHeap,newNumber);
		// }
		// else if(minHeap.size==0){
		// 	// cout<<" Inserted into minheap"<<endl;

		// 	minHeap.insert(minHeap,newNumber);
		// }
		// else if(newNumber>maxHeap.heapArray[1]){
		// 	//Insert into max heap
		// 	maxHeap.insert(maxHeap,newNumber);
		// 	if(maxHeap.size-minHeap.size>=2){
		// 		int toInsertIntoMinHeap=maxHeap.heapArray[1];
		// 		maxHeap.deleteRoot(maxHeap);
		// 		minHeap.insert(minHeap,toInsertIntoMinHeap);

		// 	}
		// }
		// else if(newNumber<minHeap.heapArray[1]){
		// 	//Insert into minheap
		// 	minHeap.insert(minHeap,newNumber);
		// 	if(minHeap.size-maxHeap.size>=2){
		// 		int toInsertIntoMaxHeap=minHeap.heapArray[1];
		// 		minHeap.deleteRoot(minHeap);
		// 		maxHeap.insert(maxHeap,toInsertIntoMaxHeap);

		// 	}
		// }
		// else{
		// 	if(maxHeap.size>minHeap.size){
		// 		cout<<" In else & if "<<endl;
		// 		//Insert into max heap
		// 	}
		// 	else if(minHeap.size>maxHeap.size){
		// 		//Insert into minheap
		// 		cout<<" In else & else"<<endl;
		// 	}
		// }
		// heap.insert(heap,newNumber);
		// cout<<heap.getMedian(heap);
		cout<<"After Inserting "<<newNumber<<endl;
		cout<<"Min Heap "<<endl;
		for(int i=1;i<=minHeap.size;i++){
			cout<<minHeap.heapArray[i]<<" ";
		}
		cout<<endl<<"Max Heap"<<endl;
		for (int i = 1; i <= maxHeap.size; ++i)
		{
			cout<<maxHeap.heapArray[i]<<" ";
		}
		
		float median;
		if(maxHeap.size==minHeap.size){
			median=((float)maxHeap.heapArray[1]+(float)minHeap.heapArray[1])/2;
		}
		else if(maxHeap.size>minHeap.size){
			median=10*((double)maxHeap.heapArray[1]/10);
		}
		else{
			median=10*((double)minHeap.heapArray[1]/10);

		}
		
		cout<<" : "<<median<<endl;		// heap.getMedian(heap);

		
	}
}