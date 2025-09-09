import java.util.Arrays;

public class Solution {

    /**
     * Time Complexity: O(n^2) - Due to the nested loops, it's too slow for large inputs.
     * Space Complexity: O(1) - Only a constant amount of extra space is used.
     */
    public int maxArea_brute_force(int[] height) {
        int n = height.length;
        int maxArea = 0;

        // Iterate through each possible pair of lines
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate the width of the container
                int width = j - i;
                // The height is limited by the shorter of the two lines
                int h = Math.min(height[i], height[j]);

                // Calculate the area for the current pair of lines
                int currentArea = width * h;

                // Update the maximum area if the current one is larger
                maxArea = Math.max(maxArea, currentArea);
            }
        }
        return maxArea;
    }

    /**
     * Time Complexity: O(n) - A single pass is made through the array.
     * Space Complexity: O(1) - Only a constant amount of extra space is used.
     */
    public int maxArea_two_pointer(int[] height) {
        // Initialize pointers at the start and end of the array
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        // Loop until the pointers meet
        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            // The height is limited by the shorter of the two lines
            int h = Math.min(height[left], height[right]);

            // Calculate the area for the current container
            int currentArea = width * h;

            // Update the maximum area if the current one is larger
            maxArea = Math.max(maxArea, currentArea);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }

    // Example usage:
    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solver = new Solution();

        // Define the input array of heights
        int[] heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

        // Call the methods on the instance and print the results
        System.out.println("Input Heights: " + Arrays.toString(heights));
        System.out.println("Max Area (Brute Force): " + solver.maxArea_brute_force(heights));
        System.out.println("Max Area (Two Pointer): " + solver.maxArea_two_pointer(heights));

        // Another example
        int[] heights2 = {1, 1};
        System.out.println("\nInput Heights: " + Arrays.toString(heights2));
        System.out.println("Max Area (Brute Force): " + solver.maxArea_brute_force(heights2));
        System.out.println("Max Area (Two Pointer): " + solver.maxArea_two_pointer(heights2));
    }
}
