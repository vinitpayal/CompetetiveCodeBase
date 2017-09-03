import java.util.*;

class ActualWorker{
    public int findMinSteps(int[] arr, int size){
        int[] tabulation = new int[size];

        for(int i = 0; i < size; i++){
            tabulation[i] = -1;
        }

        tabulation[size-1] = 0;

        int minStepsRequired;
        boolean pathPossibleFlag;

        for(int i = size-2; i >=0; i--){
            int stepsPossibleFromCurrPos = arr[i];
            pathPossibleFlag = false;
            minStepsRequired = size+10000;
            for(int j = i+1; (j < size)&&(j <= i+stepsPossibleFromCurrPos); j++){
                if(tabulation[j] == -1) continue;

                if(tabulation[j] < minStepsRequired) {
                    pathPossibleFlag = true;
                    minStepsRequired = tabulation[j];
                }
            }

            if(pathPossibleFlag){
                tabulation[i] = 1 + minStepsRequired;
            }
        }
        return tabulation[0];
    }
}

public class MinimumJumps{
    public static void main(String[] args) {
        int t,n;
        int[] arr = new int[100];
        Scanner sc=new Scanner(System.in);

        t = sc.nextInt();

        while (t-- > 0){
            n = sc.nextInt();

            for(int i = 0; i < n;i++){
                arr[i] = sc.nextInt();
            }

            System.out.println(new ActualWorker().findMinSteps(arr, n));
        }
    }
}