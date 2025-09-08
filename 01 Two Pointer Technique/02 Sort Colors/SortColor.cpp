#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @brief Sorts an array of 0s, 1s, and 2s using the counting sort method.
     * * Time Complexity: O(n)
     * Space Complexity: O(1)
     * * @param nums The input vector to be sorted in-place.
     */
    void sortColors_counting(std::vector<int>& nums) {
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

        // Second pass: overwrite the vector with the sorted colors
        int index = 0;
        for (int i = 0; i < count0; ++i) {
            nums[index++] = 0;
        }
        for (int i = 0; i < count1; ++i) {
            nums[index++] = 1;
        }
        for (int i = 0; i < count2; ++i) {
            nums[index++] = 2;
        }
    }

    /**
     * @brief Sorts an array of 0s, 1s, and 2s using the Dutch National Flag algorithm.
     * This is an optimal one-pass algorithm.
     * * Time Complexity: O(n)
     * Space Complexity: O(1)
     * * @param nums The input vector to be sorted in-place.
     */
    void sortColors_dutch_flag(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

void printVector(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution solution;
    std::vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    std::vector<int> nums2 = {2, 0, 2, 1, 1, 0};

    std::cout << "Original array: ";
    printVector(nums1);

    // Using counting sort method
    solution.sortColors_counting(nums1);
    std::cout << "Sorted array (counting sort): ";
    printVector(nums1);

    std::cout << "\nOriginal array: ";
    printVector(nums2);

    // Using Dutch National Flag algorithm
    solution.sortColors_dutch_flag(nums2);
    std::cout << "Sorted array (Dutch National Flag): ";
    printVector(nums2);

    return 0;
}