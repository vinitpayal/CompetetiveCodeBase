/*input
3
VINIT PAYAL
DROGO
BATMAN
*/

#include<iostream>

using namespace std;


int main(){

	int t, len, asciiSum;
	cin>>t;

	string ipStr;

	for(int i = 0; i < t; i++){
		asciiSum = 0;

		cin>>ipStr;

		len = ipStr.length();
		for(int j = 0 ; j < len; j++){
			asciiSum += ipStr[j];
		}
		// cout<<asciiSum<<endl;
		// cout<<(asciiSum%3)?"YES":"NO"<<"\n";
		cout<<"Case "<<i+1<<": ";
		if(asciiSum % 3){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}

	return 0;
}