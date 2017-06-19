#include <iostream>

using namespace std;

void printArray(int A[], int len){
	for(int i = 0; i < len; i++){
		cout<<A[i]<<" ";
	}
}

void mergeArrays(int A[], int l, int m, int r){
	cout<<"\nMerging "<<l<<" -> "<<m<<" & "<<m+1<<" -> "<<r;
	int s = l; 
	int lTemp[m-l+1];
	int rTemp[r-m];

	int ltPicked = -1;
	int rtPicked = -1;

	for(int i = l; i <= r; i++){
		if(i <= m)
			lTemp[i-l] = A[i];
		else
			rTemp[i-m-1] = A[i];
	}

	//merging step
	for(int i = l; i <= r; i++){

		//left temp array is completely exhausted
		if(ltPicked >= m-l){
			A[i] = rTemp[rtPicked+1];
			rtPicked++;
		}
		else if(rtPicked >= r-m-1){
			A[i] = lTemp[ltPicked+1];
			ltPicked++;
		}
		else if(lTemp[ltPicked + 1] <= rTemp[rtPicked + 1]){
			A[i] = lTemp[ltPicked+1];
			ltPicked++;
		}
		else {
			A[i] = rTemp[rtPicked+1];
			rtPicked++;
		}

	}

	// printArray(A, r+1);
}


void mergeSort(int A[], int l, int r){
	cout<<"\nCalled for l ="<<l<<" & r= "<<r;
	if(r > l){
		int mid = (l + r)/2;
		mergeSort(A, l, mid);
		mergeSort(A, mid+1, r);

		mergeArrays(A,l,mid,r);
	}
}



int main(){

	int ip[11] = {3,1,2};
	
	cout<<"Before Sorting \n";
	printArray(ip, 3);

	mergeSort(ip,0,2);

	cout<<"\nAfter Sorting\n";
	printArray(ip,3);
}
