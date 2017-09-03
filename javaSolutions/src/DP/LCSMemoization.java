import java.util.Scanner;
import java.util.*;

class ActualWorker{
    public int findLcs(String s1, String s2, Map<String,int> memoizeMap){

        if(memoizeMap.get(s1+" "+s2)){
            return memoizeMap.get(s1+" "+s2);
        }

        if(s1.length() == 0 || s2.length() == 0) return 0;

        int val;
        if(s1.charAt(s1.length() - 1) == s2.charAt(s2.length() - 1)){
           val = 1 + findLcs(s1.substring(0, s1.length()-1), s2.substring(0, s2.length()-1), memoizeMap);
           memoizeMap.put(s1+" "+s2, val);
           return val;
        }

        else{
            int possibility1 = findLcs(s1.substring(0, s1.length()-1), s2.substring(0, s2.length()),memoizeMap);
            int possibility2 = findLcs(s1.substring(0, s1.length()), s2.substring(0, s2.length()-1),memoizeMap);
            val =  Math.max(possibility1, possibility2);
            memoizeMap.put(s1+" "+s2, val);
            return val;
        }
    }
}

public class LcsMemoization{

    public static void main(String[] args) {
        int t,n1,n2;
        String s1,s2;
        Scanner sc=new Scanner(System.in);
        Map<String,Integer> memoizeMap=new HashMap<String,Integer>();

        t = sc.nextInt();
        while (t-- > 0) {
            n1 = sc.nextInt();
            n2 = sc.nextInt();

            s1 = sc.next();
            s2 = sc.next();

            System.out.println(new ActualWorker().findLcs(s1,s2, memoizeMap));
        }


    }
}