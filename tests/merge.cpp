#include <iostream>

using namespace std;

void printArray(int A[], int len){
	for(int i = 0; i < len; i++){
		cout<<A[i]<<" ";
	}
}

void mergeArrays(int A[], int l, int m, int r){

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


int main(){

	int ip[10] = {1,2,4,5,8,3,6,7,9, 10};
	
	cout<<"Before merging \n";
	printArray(ip, 10);

	mergeArrays(ip,0,4,9);

	cout<<"\nAfter merge \n ";
	printArray(ip,10);
}
