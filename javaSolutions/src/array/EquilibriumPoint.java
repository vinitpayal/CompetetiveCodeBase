import java.util.Scanner;

public class EquilibriumPoint{
    public static void main(String[] args) {
        int a[]=new int[105];

        Scanner sc=new Scanner(System.in);

        int t = sc.nextInt();
        int n, ts,tempSum;
        boolean solnFound;

        while (t > 0){
            solnFound = false;
            n = sc.nextInt();
            ts = 0;
            tempSum = 0;

            for(int i = 0; i < n;i++){
                a[i] = sc.nextInt();
                ts += a[i];
            }
            //System.out.println("total sum "+ts+"\n");
            for(int i = 0; i < n; i++){

                //System.out.println("curr sum "+tempSum+"\n");
                if(2*tempSum == ts-a[i]){
                    solnFound = true;
                    System.out.println(i+1);
                    break;
                }
                tempSum += a[i];
            }

            if(!solnFound){
                System.out.println(-1);
            }
            t--;
        }
    }
}