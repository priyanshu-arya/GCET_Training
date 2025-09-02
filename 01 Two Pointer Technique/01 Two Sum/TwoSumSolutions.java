import java.util.*;

public class TwoSumSolutions {

    // 1. Brute Force (O(n²))
    public static int[] twoSumBF(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{}; // No solution (though problem guarantees one)
    }

    // 2. Using Hash Map (O(n))
    public static int[] twoSumHM(int[] nums, int target) {
        Map<Integer, Integer> numToIndex = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];
            if (numToIndex.containsKey(diff)) {
                return new int[]{numToIndex.get(diff), i};
            }
            numToIndex.put(nums[i], i);
        }
        return new int[]{}; // No solution (though problem guarantees one)
    }

    // 3. Two Pointers (O(n log n))
    public static int[] twoSumTP(int[] nums, int target) {
        int n = nums.length;
        int[][] numWithIndex = new int[n][2];
        for (int i = 0; i < n; i++) {
            numWithIndex[i][0] = nums[i];
            numWithIndex[i][1] = i;
        }

        Arrays.sort(numWithIndex, Comparator.comparingInt(a -> a[0]));

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numWithIndex[left][0] + numWithIndex[right][0];
            if (sum == target) {
                return new int[]{numWithIndex[left][1], numWithIndex[right][1]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return new int[]{}; // No solution (though problem guarantees one)
    }

    // 4. Binary Search (O(n log n))
    public static int[] twoSumBS(int[] nums, int target) {
        int n = nums.length;
        int[][] numWithIndex = new int[n][2];
        for (int i = 0; i < n; i++) {
            numWithIndex[i][0] = nums[i];
            numWithIndex[i][1] = i;
        }

        Arrays.sort(numWithIndex, Comparator.comparingInt(a -> a[0]));

        for (int i = 0; i < n; i++) {
            int complement = target - numWithIndex[i][0];
            int left = i + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numWithIndex[mid][0] == complement) {
                    return new int[]{numWithIndex[i][1], numWithIndex[mid][1]};
                } else if (numWithIndex[mid][0] < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return new int[]{}; // No solution (though problem guarantees one)
    }

    // Example usage
    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] resultBF = twoSumBF(nums, target);
        System.out.println("Brute Force: [" + resultBF[0] + ", " + resultBF[1] + "]");

        int[] resultHM = twoSumHM(nums, target);
        System.out.println("Hash Map: [" + resultHM[0] + ", " + resultHM[1] + "]");

        int[] resultTP = twoSumTP(nums, target);
        System.out.println("Two Pointers: [" + resultTP[0] + ", " + resultTP[1] + "]");

        int[] resultBS = twoSumBS(nums, target);
        System.out.println("Binary Search: [" + resultBS[0] + ", " + resultBS[1] + "]");
    }
}
