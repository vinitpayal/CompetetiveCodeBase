import java.util.*;
import java.lang.*;
import java.io.*;

import java.util.Scanner;

class GFG{

    public static int pathsCount = 0;

    static void countOfPaths(int currX,int currY, int n, int m){
        if(currX > n-1 || currY > m-1|| currX < 0 || currY < 0) return;
        if(currX == n-1 && currY == m-1){
            pathsCount++;
        }

        countOfPaths(currX+1,currY,n,m);
        countOfPaths(currX, currY+1,n,m);
    }

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int t, n, m;

        t = sc.nextInt();

        while (t-- > 0){
            pathsCount = 0;
            n = sc.nextInt();
            m = sc.nextInt();

            countOfPaths(0,0,n,m);

            System.out.println(pathsCount);
        }

    }
}