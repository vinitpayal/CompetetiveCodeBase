/*input
8
*/
#include <iostream>
#define MAX 100000000
using namespace std;

int numerator[MAX], denominator[MAX];

bool isCommonFactor(int a, int b){
	int min = (a<b)?a:b;

	for(int i = 2; i <= min; i ++){
		if(a%i == 0 && b %i == 0)
			return true;
	}
	return false;
}

//selection sorting 
void sortArrays(int arrLen){
	int maxIndex;
	float tempVal, maxVal;
	for(int i = 0; i < arrLen; i++){

		maxVal = (float)numerator[i]/denominator[i];
		maxIndex = i;

		for(int j = i+1; j < arrLen; j++){
			tempVal = (float)numerator[j]/denominator[j];
			if(tempVal < maxVal){
				maxIndex = j;
				maxVal = tempVal;
			}
		}
		if(maxIndex != i){
			int swpVal = numerator[i];
			numerator[i] = numerator[maxIndex];
			numerator[maxIndex] = swpVal;

			swpVal = denominator[i];
			denominator[i] = denominator[maxIndex];
			denominator[maxIndex] = swpVal;
		}
	}
}

int main(){
	int number;
	int numeratorIn = 0, denominatorIn = 0;

	cin>>number;

	for(int index = 1; index <= number; index++){
		for(int index1 = number; index1 > index; index1--){
			if(index == 1 || !isCommonFactor(index, index1)){
				numerator[numeratorIn++] = index;
				denominator[denominatorIn++] = index1;
			}
		}
	}

	sortArrays(numeratorIn);

	//for handling if sequence no is 0 
	if(number > 0)
		cout<<"0/1,";
	else
		cout<<"0/1";

	for(int i = 0; i < numeratorIn; i++){
		cout<<numerator[i]<<"/"<<denominator[i]<<",";
	}

	//for handling if sequence no is 0 
	if(number > 0)
		cout<<"1/1\n";
}