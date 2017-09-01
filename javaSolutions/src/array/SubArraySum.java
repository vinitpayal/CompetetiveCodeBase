import java.util.Scanner;

class ActualWorker{
    public void getFirstSubArrayWithSum(int[] arr, int size, int sum){
        int startIndex = 0;
        int sumSoFar = 0;
        int j;
        for(int i= 0; i < size; i++){
            sumSoFar += arr[i];
            j = startIndex;
            while(sumSoFar > sum && j < i){
                sumSoFar -= arr[j];
                j++;
                startIndex++;
            }

            if(sumSoFar == sum){
                System.out.println((startIndex+1)+" "+(i+1));
                break;
            }

        }
    }
}

public class SubArraySum{
    public static void main(String[] args) {
        int t,n,k;
        int[] arr = new int[102];

        Scanner sc=new Scanner(System.in);

        t = sc.nextInt();

        while(t-- > 0){
            n = sc.nextInt();
            k = sc.nextInt();

            for(int i = 0; i < n;i++){
                arr[i] = sc.nextInt();
            }

            new ActualWorker().getFirstSubArrayWithSum(arr,n,k);
        }

    }
}