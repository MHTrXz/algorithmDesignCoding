import java.util.Arrays;
import java.util.Scanner;

public class SubsetSum {
    static int total_nodes;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of items");
        int size = input.nextInt();
        int[] weights = new int[size];
        System.out.println("enter subsets");
        for (int i = 0; i < size; i++) {
            weights[i] = input.nextInt();
        }
        int target;
        System.out.println("entertarget of sumition of subsets");
        target = input.nextInt();
        generateSubsets(weights, size, target);
        System.out.println("Nodes generated " + total_nodes);
    }

    public static void printSubset(int[] A, int size) {
        System.out.print("Items: ");
        for (int i = 0; i < size; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println();
    }

    public static int comparator(int pLhs, int pRhs) {
        return (pLhs > pRhs) ? 1 : ((pLhs == pRhs) ? 0 : -1);
    }

    public static void subset_sum(int[] s, int[] t, int s_size, int t_size, int sum, int ite, int target_sum) {
        total_nodes++;

        if (target_sum == sum) {
            printSubset(t, t_size);
            if (ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum) {
                subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
            }
            return;
        } else {
            if (ite < s_size && sum + s[ite] <= target_sum) {
                for (int i = ite; i < s_size; i++) {
                    t[t_size] = s[i];
                    if (sum + s[i] <= target_sum) {
                        subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                    }
                }
            }
        }
    }

    public static void generateSubsets(int[] s, int size, int target_sum) {
        int[] tuplet_vector = new int[size];
        int total = 0;
        Arrays.sort(s);
        for (int i = 0; i < size; i++) {
            total += s[i];
        }
        if (s[0] <= target_sum && total >= target_sum) {
            subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
        }
    }
}