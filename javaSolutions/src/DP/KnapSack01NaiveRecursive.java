import java.util.*;
import java.lang.*;
import java.io.*;

class ActualWorker{
    public int knapsackRecursive(int[] v, int[] w,int capacity, int size, int currIndex, int currSum){
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

        // System.out.println("For index :"+currIndex+" returnVal :"+returnVal);

        return returnVal;
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

            System.out.println(new ActualWorker().knapsackRecursive(v,w,c,n,0,0));
        }
    }
}