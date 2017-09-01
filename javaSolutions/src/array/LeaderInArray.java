import java.util.Scanner;

class ActualWorker{
    public String findLeadersInArray(int[] arr, int size){
        String soln = "";
        int maxSoFar = -100;
        for(int i = size-1; i >= 0; i--){
            if(arr[i] > maxSoFar) {
                soln = Integer.toString(arr[i])+" "+soln;
                maxSoFar = arr[i];
            }
        }
        return soln;
    }
}

public class LeaderInArray{
    public static void main(String[] args) {
        int t,n;
        int[] arr = new int[102];

        Scanner sc=new Scanner(System.in);

        t = sc.nextInt();

        while(t-- > 0){
            n = sc.nextInt();

            for(int i = 0; i < n;i++){
                arr[i] = sc.nextInt();
            }

            System.out.println(new ActualWorker().findLeadersInArray(arr,n));
        }

    }
}