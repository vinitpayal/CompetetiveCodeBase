/*input
3
1 1 5 5
4 4 7 7
1 1 5 5
1 7 10 12
1 1 2 2
2 2 3 3
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t, x1,y1, x2,y2, x3,y3, x4,y4, blx,bly, trx,triy;

	cin>>t;

	for(int i = 1; i <= t; i++){
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;

		blx = max(x1,x3);
		bly = max(y1,y3);

		trx = min(x2, x4);
		triy = min(y2, y4);


		cout<<"Case "<<i<<": ";

		if(blx >= trx || bly >= triy) cout<<"No\n";
		else cout<<"Yes\n";
	}
}