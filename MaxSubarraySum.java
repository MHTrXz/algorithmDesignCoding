public class MaxSubarraySum {

    private static int minValue(int[] chars) {
        int min = chars[0];
        for (int ktr = 1; ktr < chars.length; ktr++) {
            if (chars[ktr] < min) {
                min = chars[ktr];
            }
        }
        return min;
    }
    public static int subset_sum(int[] list, int sum, int starting_index, int target_sum) {
        if( target_sum == sum )
        {
            subset_count++;
            if(starting_index < list.length)
                subset_sum(list, sum - list[starting_index-1], starting_index, target_sum);
        }
        else {
            for( int i = starting_index; i < list.length; i++ )
            {
                subset_sum(list, sum + list[i], i + 1, target_sum);
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//        int maxSum = subset_sum(arr);
        System.out.println(maxSum); // خروجی برابر با 6 است
    }
}