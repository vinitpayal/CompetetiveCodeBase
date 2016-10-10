#include <iostream>
#include<map>
#include<string>
#include <sstream>

using namespace std;
int main()
{
	string ipString;
	map<char, string> sevenToDec;
	map<string, int> decToSeven;
	decToSeven["063"]=0;
	decToSeven["010"]=1;
	decToSeven["093"]=2;
	decToSeven["079"]=3;
	decToSeven["106"]=4;
	decToSeven["103"]=5;
	decToSeven["119"]=6;
	decToSeven["011"]=7;
	decToSeven["127"]=8;
	decToSeven["107"]=9;
	
	sevenToDec['0']="063";
	sevenToDec['1']="010";
	sevenToDec['2']="093";
	sevenToDec['3']="079";
	sevenToDec['4']="106";
	sevenToDec['5']="103";
	sevenToDec['6']="119";
	sevenToDec['7']="011";
	sevenToDec['8']="127";
	sevenToDec['9']="107";


	cin>>ipString;
	char a='+';
	const char * delm=&a;
	char* ips;
	string num1;
	string num2;
	string tok;
	int d1,d2;
	
	while(ipString!="BYE")
	{
		d1=0;
		d2=0;
		stringstream ss(ipString); // Turn the string into a stream.
		bool isFirst=true;
		while(getline(ss,tok,'+')) 
		{
			if(isFirst)
			{
				num1=tok;
				isFirst=false;
			}
			else
			{
				num2=tok;
			}
  		}

  		int i=0;
  		string curr;
  		while(i<num1.length())
  		{
  			curr=num1.substr(i,3);
  			int currDigit=decToSeven[curr];
  			d1=d1*10+currDigit;
  			i+=3;
  		}
  		i=0;
  		while(i<num2.length()-1)
  		{
  			curr=num2.substr(i,3);
  			int currDigit=decToSeven[curr];
  			d2=d2*10+currDigit;
  			i+=3;
  		}
		int d3=d1+d2;
		string sum=to_string(d3);
		string op=ipString;
		i=0;
		while(i<sum.length())
		{
			op+=sevenToDec[sum[i]];
			i++;
		}
		// cout<<"d1:"<<d1<<" d2:"<<d2<<" d3:"<<d3<<endl;
		cout<<op<<endl;
		cin>>ipString;
	}
	return 0;
}
