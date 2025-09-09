#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max

class Solution {
public:
    /**
     * Time Complexity: O(n^2) - Due to the nested loops, it's too slow for large inputs.
     * Space Complexity: O(1) - Only a constant amount of extra space is used.
     **/
    int maxArea_brute_force(const std::vector<int>& height) {
        int n = height.size();
        int max_area = 0;

        // Iterate through each possible pair of lines
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the width of the container
                int width = j - i;
                // The height is limited by the shorter of the two lines
                int h = std::min(height[i], height[j]);

                // Calculate the area for the current pair of lines
                int current_area = width * h;

                // Update the maximum area if the current one is larger
                max_area = std::max(max_area, current_area);
            }
        }
        return max_area;
    }

    /**
     * Time Complexity: O(n) - A single pass is made through the array.
     * Space Complexity: O(1) - Only a constant amount of extra space is used.
     **/

    int maxArea_two_pointer(const std::vector<int>& height) {
        // Initialize pointers at the start and end of the vector
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        // Loop until the pointers meet
        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            // The height is limited by the shorter of the two lines
            int h = std::min(height[left], height[right]);

            // Calculate the area for the current container
            int current_area = width * h;

            // Update the maximum area if the current one is larger
            max_area = std::max(max_area, current_area);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

// Example usage:
int main() {
    // Create an instance of the Solution class
    Solution solver;

    // Define the input vector of heights
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Call the methods on the instance and print the results
    std::cout << "Input Heights: [1, 8, 6, 2, 5, 4, 8, 3, 7]" << std::endl;
    std::cout << "Max Area (Brute Force): " << solver.maxArea_brute_force(heights) << std::endl;
    std::cout << "Max Area (Two Pointer): " << solver.maxArea_two_pointer(heights) << std::endl;

    // Another example
    std::vector<int> heights_2 = {1, 1};
    std::cout << "\nInput Heights: [1, 1]" << std::endl;
    std::cout << "Max Area (Brute Force): " << solver.maxArea_brute_force(heights_2) << std::endl;
    std::cout << "Max Area (Two Pointer): " << solver.maxArea_two_pointer(heights_2) << std::endl;

    return 0;
}
