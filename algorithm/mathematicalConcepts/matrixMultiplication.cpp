/*input
4
*/
#include <iostream>

using namespace std;

void printMatrix(int *arr, int n){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<*((arr+i*n) + j)<<" ";
		}
		cout<<"\n";
	}
}

void multiply(int *a, int *b, int n){
	int c[n][n];

	for(int i = 0; i < n; i++){
		for(int j =0 ;j < n; j++){
			c[i][j] = 0;
			for(int k = 0; k < n; k++){
				c[i][j] += *((a+i*n) + k) * *((b+k*n) + j);
			}
		}
	}
	cout<<"\nMultiplied Result\n";
	printMatrix((int *)c, n);
}

int main(){

	int n;
	cin>>n;

	int A[n][n], B[n][n], C[n][n];

	for(int  i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = n * i + j + 1;
			B[i][j] = n*n + n * i + j + 1;
		}
	}

	cout<<"First Matrix \n";

	printMatrix((int *)A, n);

	cout<<"\n2nd Matrix \n";

	printMatrix((int *)B, n);

	multiply((int *)A, (int *)B, n);
	// C = multiply(A, B, n);

	// cout<<"\nMultiplied Result\n";

	// printMatrix((int *)C, n);


	return 0;
}