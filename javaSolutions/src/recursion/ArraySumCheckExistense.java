import java.util.Scanner;
import java.util.Arrays;


class ActualWorker{

    String pairs = "";

    public String findSumSubset(int[] arr, int currIndex, int size, int sumVal, String currPath, int k){
        if(sumVal == k) {
            pairs+= "("+currPath+")";
            return pairs;
        };
        if(currIndex > size-1) return "";

        String pathAfterInclusion;
        if(currPath == "") {
            pathAfterInclusion = currPath + Integer.toString(arr[currIndex]);
        }
        else{
            pathAfterInclusion = currPath + " " + Integer.toString(arr[currIndex]);
        }

        findSumSubset(arr,currIndex+1, size, sumVal,currPath,k);
        findSumSubset(arr,currIndex+1,size, sumVal+arr[currIndex],pathAfterInclusion,k);

        return pairs;
    }
}

class ArraySumCheckExistense{

    public static void main(String[] args) {
        int t, n, k;

        int [] ipArray = new int[1000];
        Scanner sc=new Scanner(System.in);
        t = sc.nextInt();

        while (t-- > 0){
            n = sc.nextInt();
            for(int i = 0; i < n;i++){
                ipArray[i] = sc.nextInt();
            }

            Arrays.sort(ipArray,0,n);

            k = sc.nextInt();
            String ans = new ActualWorker().findSumSubset(ipArray, 0, n, 0, "",k);
            if(ans == "") ans = "Empty";

            System.out.println(ans);

        }
    }



}