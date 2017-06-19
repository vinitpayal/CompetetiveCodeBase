/*input
2

3
3
1
2

5
2
3
8
6
1
*/
#include <iostream>

using namespace std;

void printArray(long long int A[], long long int len){
	for(long long int i = 0; i < len; i++){
		cout<<A[i]<<" ";
	}
}

long long int mergeArrays(long long int A[], long long int l, long long int m, long long int r){
	// cout<<"\nMerging "<<l<<" -> "<<m<<" & "<<m+1<<" -> "<<r;

	long long int inversions = 0;
	long long int s = l; 
	long long int lTemp[m-l+1];
	long long int rTemp[r-m];

	long long int ltPicked = -1;
	long long int rtPicked = -1;

	for(long long int i = l; i <= r; i++){
		if(i <= m)
			lTemp[i-l] = A[i];
		else
			rTemp[i-m-1] = A[i];
	}

	//merging step
	for(long long int i = l; i <= r; i++){

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
		else if(lTemp[ltPicked + 1] > rTemp[rtPicked + 1]){
			inversions += (m - (l + ltPicked ));
			A[i] = rTemp[rtPicked+1];
			rtPicked++;
		}

	}

	return inversions;
}


long long int mergeSort(long long int A[], long long int l, long long int r){
	if(r > l){
		long long int mid = (l + r)/2;
		return mergeSort(A, l, mid) + mergeSort(A, mid+1, r) + mergeArrays(A,l,mid,r);
	}
	return 0;
}



int main(){

	long long int ip[200001];

	long long int t, n;
	cin>>t;

	while(t--){
		cin>>n;
		for(long long int i = 0; i < n; i++){
			cin>>ip[i];
		}
		cout<<mergeSort(ip,0,n-1)<<"\n";
	}
}
