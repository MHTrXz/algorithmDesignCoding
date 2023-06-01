import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class FractionalKnapsack {
    private static class Item {
        double value;
        double weight;
        double ratio;

        public Item(double value, double weight) {
            this.value = value;
            this.weight = weight;
            this.ratio = value / weight;
        }
    }

    public static double getMaxValue(double[] values, double[] weights, double capacity) {
        int n = values.length;
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(values[i], weights[i]);
        }

        Arrays.sort(items, Comparator.comparingDouble((Item i) -> i.ratio).reversed());

        double maxValue = 0;
        for (Item item : items) {
            if (capacity == 0) {
                break;
            }
            double fraction = Math.min(1, capacity / item.weight);
            maxValue += fraction * item.value;
            capacity -= fraction * item.weight;
        }

        return maxValue;
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter count: ");
        int count = Integer.parseInt(input.nextLine());

        double[] values = new double[count];
        double[] weights = new double[count];

        System.out.print("Enter capacity: ");
        double capacity = Double.parseDouble(input.nextLine());

        System.out.println("Enter [value] [weight]");
        for (int i = 0; i < count ; i++) {
            String[] inp = input.nextLine().split(" ");
            values[i] = Double.parseDouble(inp[0]);
            weights[i] = Double.parseDouble(inp[1]);
        }

        double maxValue = FractionalKnapsack.getMaxValue(values, weights, capacity);
        System.out.println("Max value that can be put in the knapsack = " + maxValue);
    }
}