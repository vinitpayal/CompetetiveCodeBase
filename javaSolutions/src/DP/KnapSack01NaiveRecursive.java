import java.util.*;
import java.lang.*;
import java.io.*;

class ActualWorker{

    public Map<String,Integer> memoize = new HashMap<String,Integer>();

    public int knapsackRecursive(int[] v, int[] w, int capacity, int size, int currIndex, int currSum){
        if(currIndex >= size) return currSum;

        int returnVal;

        if(capacity < w[currIndex]){
            returnVal = knapsackRecursive(v,w, capacity, size, currIndex+1, currSum);
        }
        else{
            int sumAfterIncluding, sumWithoutIncluding;

            sumWithoutIncluding = knapsackRecursive(v,w, capacity, size, currIndex+1, currSum);
            sumAfterIncluding = knapsackRecursive(v,w, capacity - w[currIndex], size, currIndex+1, currSum + v[currIndex]);

            returnVal = Math.max(sumAfterIncluding, sumWithoutIncluding);
        }

        return returnVal;
    }

    public int knapsackTabulation(int capacity, int size, int[] v, int[] w){
        int[][] tabulation = new int[size+1][capacity+1];

        for(int i = 0; i <= size; i++){
            for(int j = 0; j <= capacity; j++){
                if(i == 0 || j == 0) tabulation[i][j] = 0;

                else if(w[i-1] > j){
                    tabulation[i][j] = tabulation[i-1][j];
                }

                else{
                    int p1 = v[i-1] + tabulation[i-1][j-w[i-1]];
                    int p2 = tabulation[i-1][j];

                    tabulation[i][j] = Math.max(p1,p2);
                }
            }
        }

        return tabulation[size][capacity];
    }
}

public class KnapSack01NaiveRecursive{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t,n,c;
        int v[] = new int[101];
        int w[] = new int[101];

        t = sc.nextInt();

        while (t-- > 0){
            n = sc.nextInt();
            c = sc.nextInt();

            for(int  i = 0; i < n;i++){
                v[i] = sc.nextInt();
            }

            for(int  i = 0; i < n;i++){
                w[i] = sc.nextInt();
            }

            System.out.println(new ActualWorker().knapsackTabulation(c,n,v,w));
        }
    }
}