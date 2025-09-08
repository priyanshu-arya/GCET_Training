import java.util.Arrays;

public class SortColors {

    /**
     * @brief Sorts an array of 0s, 1s, and 2s using the counting sort method.
     * * Time Complexity: O(n)
     * Space Complexity: O(1)
     * * @param nums The input array to be sorted in-place.
     */
    public void sortColors_counting(int[] nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        // First pass: count the occurrences of each color
        for (int num : nums) {
            if (num == 0) {
                count0++;
            } else if (num == 1) {
                count1++;
            } else { // num == 2
                count2++;
            }
        }

        // Second pass: overwrite the array with the sorted colors
        int index = 0;
        for (int i = 0; i < count0; i++) {
            nums[index++] = 0;
        }
        for (int i = 0; i < count1; i++) {
            nums[index++] = 1;
        }
        for (int i = 0; i < count2; i++) {
            nums[index++] = 2;
        }
    }

    /**
     * @brief Sorts an array of 0s, 1s, and 2s using the Dutch National Flag algorithm.
     * This is an optimal one-pass algorithm.
     * * Time Complexity: O(n)
     * Space Complexity: O(1)
     * * @param nums The input array to be sorted in-place.
     */
    public void sortColors_dutch_flag(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums, mid, high);
                high--;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        SortColors solution = new SortColors();
        int[] nums1 = {2, 0, 2, 1, 1, 0};
        int[] nums2 = {2, 0, 2, 1, 1, 0};

        System.out.println("Original array: " + Arrays.toString(nums1));
        
        // Using counting sort method
        solution.sortColors_counting(nums1);
        System.out.println("Sorted array (counting sort): " + Arrays.toString(nums1));
        
        System.out.println("\nOriginal array: " + Arrays.toString(nums2));
        
        // Using Dutch National Flag algorithm
        solution.sortColors_dutch_flag(nums2);
        System.out.println("Sorted array (Dutch National Flag): " + Arrays.toString(nums2));
    }
}
