import java.util.Scanner;

class ActualWorker{

}

public class IncreasingSubsequence {
    public static int findIncreasingSubsequence(int arr[],int start, int currSum, int arrSize, int maxElementSoFar){
        if(start >= arrSize - 1) return currSum;

        int sumAfterIncludingCurrent  = currSum+arr[start];

        int maxElementSoFarIfIncluded;

        if(maxElementSoFar < arr[start]) {
            maxElementSoFarIfIncluded = maxElementSoFar > arr[start] ? maxElementSoFar : arr[start];
            int maxSumAfterInclusion = findIncreasingSubsequence(arr, start+1, sumAfterIncludingCurrent, arrSize, maxElementSoFarIfIncluded);
            int maxSumWithoutInclusion = findIncreasingSubsequence(arr, start+1,currSum,arrSize,maxElementSoFar);

            return Math.max(maxSumAfterInclusion,maxSumWithoutInclusion);

        }
        else {
            int maxSumWithoutInclusion = findIncreasingSubsequence(arr, start+1,currSum,arrSize,maxElementSoFar);
            return maxSumWithoutInclusion;
        }



    }

    public static void main(String[] args) {
        int a[] = new int[105];

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        int n;

        while (t > 0) {
            n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            System.out.println(findIncreasingSubsequence(a,0,0,n,0));
        }
    }
}