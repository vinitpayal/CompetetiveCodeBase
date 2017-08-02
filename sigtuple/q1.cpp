#include<bits/stdc++.h>
#include <map>
using namespace std;

map<int, bool> presentSumsMap;
 
void storeAllPossibleSubsetSums(int arr[], int n){
    long long total = 1<<n;
 
    for (long long i=0; i<total; i++){
      
        long long sum = 0;
 
        for (int j=0; j<n; j++){
          
            if (i & (1<<j)){
                sum += arr[j];
                presentSumsMap[sum] = true;
            }
        }
    }
}


int getMaxPossibleSum(int arr[], int n){
  int sum = 0;
  
  for(int i = 0; i < n; i++){
    sum += arr[i];
  }
  return sum;
}
 
int main(){
  
    int arr[] = {1,1,1,1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
 
    storeAllPossibleSubsetSums(arr,n);
    
    int maxPossibleSum = getMaxPossibleSum(arr, n);
    
    int i;

    for(i = 1; i < maxPossibleSum;i++){
      if(!presentSumsMap[i]){
        cout<<i<<endl;
        break;
      }
    }
    
    if(i == maxPossibleSum){
      cout<<maxPossibleSum+1<<endl;
    }
    
    return 0;
}