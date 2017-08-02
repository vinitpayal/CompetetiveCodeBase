#include <iostream>
#include <limits.h>

using namespace std;

int minTrailingZerosSoFar = INT_MAX;

int minTrailingZeros(int g[][2],int currX, int currY, int n, int m, int twoCount, int fiveCount){
  
  int currElement = g[currX][currY];
  
  while(currElement %2 == 0){
    currElement /= 2;
    twoCount++;
  }
  while(currElement % 5 == 0){
    currElement /= 5;
    fiveCount++;
  }
  
  if(currX == n-1 && currY == m-1) {
    minTrailingZerosSoFar = min(minTrailingZerosSoFar,min(twoCount, fiveCount));
    return minTrailingZerosSoFar;
    
  }

   
   if(currX == n-1) {return minTrailingZeros(g, currX, currY + 1, n, m, twoCount, fiveCount);}
   else if(currY == m-1) {return minTrailingZeros(g, currX + 1, currY, n, m, twoCount, fiveCount);}
   else {
    minTrailingZeros(g, currX + 1, currY, n, m, twoCount, fiveCount);
    minTrailingZeros(g, currX, currY + 1, n, m, twoCount, fiveCount);
  }
  
}


int main(){
	 
	 int g[][2] = {{2,2},{5,5}};
	 
	 cout<<minTrailingZeros(g, 0, 0,  2, 2, 0, 0)<<endl;
	 
	 
	 
	return 0;
}