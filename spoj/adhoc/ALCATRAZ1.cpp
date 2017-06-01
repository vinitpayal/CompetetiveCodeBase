/*input
3
123123123
3434
1234567890
*/

#include<iostream>

using namespace std;

int charToInt(char c){
	switch (c) {
		case '0' : return 0; 
		case '1' : return 1;
		case '2' : return 2;
		case '3' : return 3;
		case '4' : return 4;
		case '5' : return 5;
		case '6' : return 6;
		case '7' : return 7;
		case '8' : return 8;
		case '9' : return 9;

	}
}

int main(){
	int t;
	cin>>t;
	
	string ip;
	long long int sod;

	while(t--){

		cin>>ip;
		
		int len = ip.length();

		sod = 0;

		for(int i = 0; i < len; i++){
			sod += charToInt(ip[i]);
		}

		cout<<sod<<endl;
	}
}