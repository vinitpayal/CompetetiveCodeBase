/*input
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
20
qwertyuiopasdfghjklzxcvbnm
0

*/

#include <iostream>
using namespace std;

int main()
{
	int rows;
	int elementsInAColoumn, strSize, opType, lastPrintedInCol;
	string str;
	cin>>rows;
	while(rows)
	{
		cin>>str;
		strSize = str.size();
		elementsInAColoumn = strSize/rows;
		opType = 1;

		for(int i = 0; i < rows; i++)
		{
			// if(i == 0 || i == rows-1)
			// 		continue;
			for(int j = 1; j <= elementsInAColoumn; j++){
				
				if(j == 1){
						lastPrintedInCol = i;
						// cout<<"printed1 "<<lastPrintedInCol<<"\n";
						cout<<str[i];
						opType = 1;
					}
					else
					{
						if(opType == 1)
						{
							// cout<<"lastPrintedInCol :"<<lastPrintedInCol;
							lastPrintedInCol = lastPrintedInCol+(2*(rows-(i+1))+1);
						    // cout<<"printed2 "<<lastPrintedInCol<<"\n";

							cout<<str[lastPrintedInCol];
							opType = 2;
						}
						else{
							lastPrintedInCol = lastPrintedInCol+(2*i+1);
							// cout<<"printed3 "<<lastPrintedInCol<<"\n";
							cout<<str[lastPrintedInCol];
							opType =1;
						}
					}
			}
		}
		cout<<"\n";
		cin>>rows;
	}
	return 0;
}