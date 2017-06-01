/*input
1

5
2
2
2
2
2
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long int t, childCount, chocSum, chocs;
	cin>>t;
	char c;

	while(t--)
	{
		chocSum = 0;
		scanf("\n");
		// cin>>c;
		cin>>childCount;
		for(long long int i = 1; i<= childCount; i++)
		{
			cin>>chocs;
			// chocSum += chocs;
			chocSum = ((chocSum%childCount)+(chocs%childCount))%childCount;
		}
		// cout<<chocSum<<" "<<childCount<<"\n";
		if(chocSum % childCount)
			cout<<"NO\n";
		else
			cout<<"YES\n";

	}
	return 0;

}