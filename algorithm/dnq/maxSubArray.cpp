/*
	Divide And Conquer
	Finding sub array with maximum sum
	Time Complexity -> O(n*log(n))

*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

//Time Complexity = O(n)
int crossMaxArraySum(int A[], int low, int mid, int high){
	int leftSum = INT_MIN;

	int sum = 0, index = mid;


	while(index >= 0){
		sum += A[index];

		if(sum > leftSum) leftSum = sum;

		index--;
	}

	index = mid + 1;

	sum = 0;

	int rigthSum = INT_MIN;

	while(index <= high){
		sum += A[index];

		if(sum > rigthSum) rigthSum = sum;

		index++;
	}

	return leftSum + rigthSum;
}

//Time Complexity log(n) * n => here n for finding crossMaxArraySum
int maxSubArraySum(int A[], int low, int high){

	if(low == high) return A[low];

	int mid = (low + high)/2;

	int leftMaxSum = maxSubArraySum(A, low, mid);
	int rightMaxSum = maxSubArraySum(A, mid + 1, high);
	int crossMaxSum = crossMaxArraySum(A, low, mid, high);

	return max(max(leftMaxSum, rightMaxSum), crossMaxSum);
}

int main(){

	int A[] = {-2,2};

	int len = sizeof(A) / sizeof(A[0]);

	cout<<"Maximum sum possible :"<<maxSubArraySum(A,0,len-1);


	return 0;
}