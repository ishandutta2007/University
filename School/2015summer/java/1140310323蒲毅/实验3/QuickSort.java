import java.util.Scanner;

public class QuickSort {

    
    public static void swap(int[] a, int i1, int i2){
        int tmp = a[i1];
        a[i1] = a[i2];
        a[i2] = tmp;
    }
    public static void sort(int[] a, int l, int r){
        System.out.println("in sort");
        System.out.println(l + " " + r);
        if(l >= r) return;
        
        int i = l - 1;
        int mid = a[r];
        for(int j = l; j < r; j++)
            if(a[j] < mid){
                i++;
                swap(a, i, j);
            }
        swap(a, i + 1, r);
        
        sort(a, l, i);
        sort(a, i + 2, r);

    }
    
    
    
    
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        n = cin.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) a[i] = cin.nextInt();
        
        System.out.println("Array unsorted:");
        for(int i = 0; i < n; i++) System.out.print(a[i] + " ");
        System.out.println("\n===========");
        
        sort(a, 0, n - 1);

        System.out.println("Array sorted:\n===========");
        for(int i = 0; i < n; i++) System.out.print(a[i] + " ");
        System.out.println();
    }
    
}
