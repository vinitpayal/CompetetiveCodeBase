/*input
300
*/
#include <iostream>

using namespace std;

int main()
{
	//Number till where we have to find primes
	int n, j;
	cin>>n;

	bool primes[n+1];

	for(int i = 0; i < n; i++){
		primes[i] = true;
	}

	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	for(int i = 2; i <= n; i++){

		j = 2;

		if(primes[i]){
			while(i * j <= n){
				primes[i * j] = false;
				j++;
			}
		}
	}



	cout<<"Prime Numbers Till "<<n<<" are as below \n";


	for(int i = 0; i < n; i++){
		if(primes[i]) cout<<i<<" ";
	}


}