#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int t, n;
	int arr[100001];
	cin>>t;
	while(t--){
		cin>>n;

		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		sort(arr, arr+n-1);

		for(int i = 0; i < n; i++){
			cout<<arr[i]<<' ,';
		}

	}
}