import java.util.*;
import java.lang.*;
import java.io.*;

import java.util.Scanner;

class PathsCountInMatrix{

    static int countOfPaths(int currX, int currY, int n, int m, int[][] memoized){
        if(currX > n-1 || currY > m-1|| currX < 0 || currY < 0) return 0;
        if(currX == n-1 && currY == m-1){
            return 1;
        }

        if(memoized[currX][currY] > 0) {
            return memoized[currX][currY];
        }

        int downFirstCount = countOfPaths(currX+1,currY,n,m, memoized);
        int rightFirstCount = countOfPaths(currX,currY+1,n,m,memoized);

        memoized[currX][currY] = downFirstCount+rightFirstCount;

        return downFirstCount+rightFirstCount;
    }

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int t, n, m;

        t = sc.nextInt();

        while (t-- > 0){
            n = sc.nextInt();
            m = sc.nextInt();

            int [][] memoized = new int[n][m];

            System.out.println(countOfPaths(0,0,n,m,memoized));
        }

    }
}