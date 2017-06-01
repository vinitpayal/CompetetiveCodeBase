/*input
1
3
2 1 2
3 2 1
*/

#include<iostream>
using namespace std;

int main(){

	int t, n, tempIP;
	cin>>t;
	long long int xenny_even , xenny_odd , yana_even , yana_odd ;

	while(t--){
		cin>>n;
		xenny_odd = 0;
		xenny_even = 0;
		yana_odd = 0;
		yana_even = 0;
		for(int index = 0; index < n; index++){
			cin>>tempIP;

			if(index % 2 ==0 ) xenny_even += tempIP;
			else xenny_odd += tempIP;
			
		}

		for(int index = 0; index < n; index++){
			cin>>tempIP;

			if(index % 2 ==0 ) yana_even += tempIP;
			else yana_odd += tempIP;

		}

		cout<<min(xenny_even + yana_odd, xenny_odd + yana_even)<<endl;
	}
	return 0;
}