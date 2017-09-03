import java.util.Scanner;

class ActualWorker{
    public int findLcs(String s1, String s2){
      if(s1.length() == 0 || s2.length() == 0) return 0;

      if(s1.charAt(s1.length() - 1) == s2.charAt(s2.length() - 1)){
          return 1 + findLcs(s1.substring(0, s1.length()-1), s2.substring(0, s2.length()-1));
      }

      else{
          int possibility1 = findLcs(s1.substring(0, s1.length()-1), s2.substring(0, s2.length()));
          int possibility2 = findLcs(s1.substring(0, s1.length()), s2.substring(0, s2.length()-1));
          return Math.max(possibility1, possibility2);
      }
    }
}

public class LCS{

    public static void main(String[] args) {
        int t,n1,n2;
        String s1,s2;
        Scanner sc=new Scanner(System.in);

        t = sc.nextInt();
        while (t-- > 0) {
            n1 = sc.nextInt();
            n2 = sc.nextInt();

            s1 = sc.next();
            s2 = sc.next();

            System.out.println(new ActualWorker().findLcs(s1,s2));
        }


    }
}