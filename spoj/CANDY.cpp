/*input
3
2
2
2
-1
*/
#include <iostream>
using namespace std;

int chocs[10002];
int main()
{
	int numberOfPacks, chocSum, changeCount, avgChocs;
	cin>>numberOfPacks;
	while(numberOfPacks!=-1)
	{
		chocSum = 0;
		changeCount = 0;
		for(int i = 0; i < numberOfPacks; i++)
		{
			cin>>chocs[i];
			chocSum += chocs[i];
		}

		if(chocSum % numberOfPacks)
			cout<<"-1\n";
		else
		{
			avgChocs = chocSum/numberOfPacks;
			for(int i = 0; i < numberOfPacks; i++)
			{
				if(chocs[i] > avgChocs)
					changeCount += (chocs[i]-avgChocs);
			}
			cout<<changeCount<<"\n";
		}

		cin>>numberOfPacks;
	}
	return 0;
}