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
            int n1 = findElementInRotatedArray(arr, element, start, mid);
            int n2 = findElementInRotatedArray(arr, element, mid+1, end);
            return Math.max(n1,n2);
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
        int[] arr = new int[] {1, 3, 50, 10, 9, 7, 6};

        for(int i = 0; i < arr.length;i++){
            System.out.println(arr[i]+"=> index :"+new ActualWorker().findElementInRotatedArray(arr,arr[i],0,arr.length-1));

        }

    }
}