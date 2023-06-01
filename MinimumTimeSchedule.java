import java.util.Arrays;
import java.util.Scanner;

public class MinimumTimeSchedule {
    private static class Activity {
        int start;
        int end;
        int cost;

        public Activity(int start, int end, int cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }
    }

    public static int getMinCost(Activity[] activities) {
        Arrays.sort(activities, (a, b) -> a.end - b.end);

        int m = activities[activities.length - 1].end;
        int[] schedule = new int[m + 1];

        for (int i = 0; i < activities.length; i++) {
            int start = activities[i].start;
            int end = activities[i].end;
            int cost = activities[i].cost;

            for (int j = end; j >= start; j--) {
                if (schedule[j] == 0) {
                    schedule[j] = cost;
                    break;
                }
            }
        }

        int totalCost = 0;
        for (int i = 0; i < schedule.length; i++) {
            totalCost += schedule[i];
        }

        return totalCost;
    }


    public static void main(String[] args) {
        Activity[] activities = new Activity[5];

        Scanner input = new Scanner(System.in);

        System.out.print("Enter count:");
        int count = Integer.parseInt(input.nextLine());
        System.out.print("Enter [start] [end] [cost]");
        for (int i = 0; i < count ; i++) {
            String[] inp = input.nextLine().split(" ");
            activities[i] = new Activity(Integer.parseInt(inp[0]), Integer.parseInt(inp[1]), Integer.parseInt(inp[2]));
        }

        int minCost = MinimumTimeSchedule.getMinCost(activities);
        System.out.println("Minimum cost of scheduling activities = " + minCost);
    }
}