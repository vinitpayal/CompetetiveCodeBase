/*input
4
*/

#include<iostream>

using namespace std;

void binary(int n,  char* arr){
	// cout<<n<<endl;
	if(n < 1){
		cout<<arr<<endl;
	}
	else{
		arr[n-1] = '0';
		binary(n-1, arr);

		arr[n-1] = '1';
		binary(n-1, arr);
	}
}

int main(){
	int n;
	cin>>n;
	// cout<<"Here";
	cout<<"n : "<<n<<endl;
	char arr[n];
	binary(n, arr);
}