class ActualWorker{
    public int findElementInRotatedArray(int[] arr, int element,int start, int end){
//        System.out.println("s:"+start+"e:"+end);
        int mid = (start + end)/2;

        if(start >= end && arr[start] != element) return -1;
        if(arr[start] == element) return start;
        if(arr[end] == element) return end;
        if(arr[mid] == element) return mid;

        if(arr[mid] < arr[start]){
            if(element > arr[start]) return findElementInRotatedArray(arr, element, start, mid);
            else return findElementInRotatedArray(arr,element,mid+1,end);
        }
        else if(arr[mid] > arr[start] && arr[mid] > arr[mid+1]){
            if(element > arr[start]) return findElementInRotatedArray(arr, element, start, mid);
            else return findElementInRotatedArray(arr,element,mid+1,end);
        }
        else if(arr[mid] > arr[start] && arr[mid] < arr[mid+1]){
            if(arr[mid] < element){
                return findElementInRotatedArray(arr, element, mid+1, end);
            }
            else{
                if(element > arr[start]) return findElementInRotatedArray(arr, element, start, mid);
                else return findElementInRotatedArray(arr,element,mid+1,end);
            }
        }
        return -2;
    }
}

public class FindInRotatedArray{
    public static void main(String[] args) {
        int[] arr = new int[] {11,13,15,17,19,221,232,56,-17,-3,1,2,4,6,8};
//        System.out.println("6=> index :"+new ActualWorker().findElementInRotatedArray(arr,6,0,arr.length-1));

        for(int i = 0; i < arr.length;i++){
            System.out.println(arr[i]+"=> index :"+new ActualWorker().findElementInRotatedArray(arr,arr[i],0,arr.length-1));

        }

    }
}