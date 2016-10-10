/*input
53
*/
#include <iostream>
#include <map>
using namespace std;
map<string, bool> occupied;

string removeStartingZeros(string s){
	string nonZeroString = "";
	int size = s.size();
	int index =0;

	while(s[index] == '0' && index < size){
		index++;
	}

	for(int in = index; in < size; in++){
		nonZeroString += s[in];
	}

	int nonZeroStringSize  = nonZeroString.size();

	//making string atleast of size 3
	while(nonZeroString.size() < 3){
		nonZeroString = "0"+nonZeroString;
	}
	return nonZeroString;
}

bool existenceCheck(string s){
	// cout<<"returing "<<occupied[removeStartingZeros(s)]<<" from existenceCheck for "<<s<<"\n";
	return occupied[removeStartingZeros(s)]?true : false;

}

string getNextBinaryAvailable(string s){
	string temp_str = s;
	bool binaryFound = false;
	int size = s.size();

	for(int i = size-1; i >=0 && !binaryFound; i--){
		// cout<<temp_str[i]<<endl;
		if(temp_str[i] == '0'){
			temp_str[i] = '1';
		}
		else
			temp_str[i] = '0';

		if(!existenceCheck(temp_str)){
			binaryFound = true;
		}
		else
		{
			temp_str = s;
		}
	}

	if(!binaryFound)
		temp_str = '1'+s;

	// occupied[temp_str] = true;
	return temp_str;
}

int main(){
	int number;
	cin>>number;
	occupied["000"] = true;
	string last_str = "000";

	string curr_str = last_str;

	for(int currrent_number = 1 ; currrent_number <= number; currrent_number++){
		curr_str = getNextBinaryAvailable(last_str);
		last_str = curr_str;
		occupied[curr_str] = true;
	}

	cout<<curr_str<<endl;

}