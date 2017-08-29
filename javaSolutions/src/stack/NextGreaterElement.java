import java.util.Scanner;
import java.util.*;

class IntegerPair{
    public int first;
    public int second;

    public IntegerPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
class ActualWorker{
    public String intArrToStr(int[] ipArr,int size){
        String tempStr = "";

        for(int i =0; i < size; i++){
            if(i > 0) tempStr += " ";
            tempStr += Integer.toString(ipArr[i]);
        }

        return tempStr;
    }
    public String nextGreaterElement(int[] inputArr,int arrSize){

        Stack<IntegerPair> stack = new Stack<IntegerPair>();

        int index = 0;
        stack.push(new IntegerPair(inputArr[index], index));

        index++;

        IntegerPair peekElement;

        while (index < arrSize) {
            peekElement = stack.peek();

            while (!stack.empty() && peekElement.first < inputArr[index]) {
                peekElement = stack.peek();
                if(peekElement.first >= inputArr[index]) break;
                else {
                    inputArr[peekElement.second] = inputArr[index];
                    stack.pop();
                }
            }

            stack.push(new IntegerPair(inputArr[index], index));

            index++;
        }

        while(!stack.empty()){
            peekElement = stack.pop();
            inputArr[peekElement.second] = -1;
        }

//        System.out.println("After NGE Array");

       return  intArrToStr(inputArr,arrSize);
    }
}

public class NextGreaterElement{
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

            System.out.println(new ActualWorker().nextGreaterElement(ipArr,n));
        }
    }
}