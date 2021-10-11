public class Main {
    static void downheapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        // finding the maximum of left and right
        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        //swapping if child >parent
        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;


            downheapify(arr, n, largest);
        }
    }

    public static void sort(int arr[])
    {
        int n = arr.length;

      //build heap by calling heapify on non leaf elements
        for (int i = n / 2 - 1; i >= 0; i--)
            downheapify(arr, n, i);

     //extract elements from the root and call healpify
        for (int i=n-1; i>0; i--)
        {
          // swap the last element with root
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // i is the size of the reduced heap
            downheapify(arr, i, 0);
        }
    }
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void main(String[] arg)
    {
        int arr[] = {1, 10, 2, 3, 4, 1, 2, 100,23, 2};
        int n = arr.length;
        sort(arr);
        System.out.println("Sorted array is");
        printArray(arr);


    }

}
