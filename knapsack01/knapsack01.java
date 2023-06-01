import java.util.Scanner;

public class knapsack01 {
    public static int max(int a, int b) {
        return (a > b) ? a : b;
    }
    public static void knapsack01(int W, int wt[], int val[], int n) {
        int i, w;
        int[][] K = new int[n + 1][W + 1];

        for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
        int res = K[n][W];

        System.out.print("Items: ");
        w = W;
        for (i = n; i > 0 && res > 0; i--) {
            if (res == K[i - 1][w])
                continue;
            else {
                System.out.print(wt[i - 1] + " ");
                res = res - val[i - 1];
                w = w - wt[i - 1];
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("enter Maximum size");
        int W = input.nextInt();
        System.out.println("enter number of items");
        int n = input.nextInt();
        int[] val = new int[n];
        int[] wt = new int[n];
        System.out.println("enter items value");
        for (int i = 0; i < n; i++){
            val[i] = input.nextInt();
        }
        System.out.println("enter items weight");
        for (int i = 0; i < n; i++) {
            wt[i] = input.nextInt();
        }
        knapsack01(W, wt, val, n);
    }
}