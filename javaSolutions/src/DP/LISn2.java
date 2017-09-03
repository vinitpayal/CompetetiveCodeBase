import java.util.Scanner;
import java.util.Arrays;

class ActualWorker{
    public int findLisLength(int[] arr, int size){
        int[] lis = new int[size];

        for(int i = 0; i < size;i++){
            lis[i] = 1;
        }

        int maxLisLen;
        for(int i = 1; i < size;i++){
            maxLisLen = 0;
            for(int j = 0; j <= i-1;j++){
                if(lis[j] > maxLisLen && arr[i] > arr[j]) {
                    maxLisLen = lis[j];
                };
            }

            lis[i] = Math.max(1+maxLisLen, lis[i]);

        }
        int max = 0;
        for(int i = 0; i < size; i++){
            if(lis[i] > max) max = lis[i];
        }
        return max;
    }
}

public class LISn2{
    public static void main(String[] args) {
        int t,n;
        int[] ipArr = new int[1000];

        Scanner sc=new Scanner(System.in);
        t = sc.nextInt();
        while (t-- > 0){
            n = sc.nextInt();
            for(int i =0; i < n; i++){
                ipArr[i] = sc.nextInt();
            }

            System.out.println(new ActualWorker().findLisLength(ipArr,n));
        }
    }
}