#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> // For std::max

class Solution {
public:
    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(k) where k is the size of the character set.
     */
    int lengthOfLongestSubstring_brute_force(const std::string& s) {
        int n = s.length();
        if (n == 0) return 0;
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            std::unordered_set<char> charSet;
            for (int j = i; j < n; ++j) {
                // If the character is already in our set, we have a repeat.
                if (charSet.count(s[j])) {
                    break;
                }
                // Otherwise, add it to the set and update the max length.
                charSet.insert(s[j]);
                maxLength = std::max(maxLength, (int)charSet.size());
            }
        }
        return maxLength;
    }

    /**
     * Time Complexity: O(n)
     * Space Complexity: O(k) where k is the size of the character set.
     */
    int lengthOfLongestSubstring_two_pointer(const std::string& s) {
        std::unordered_map<char, int> charIndexMap;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // Check if the current character is in the map and its index is within the current window
            if (charIndexMap.count(currentChar) && charIndexMap[currentChar] >= left) {
                // Move the left pointer to the right of the last occurrence of the current character
                left = charIndexMap[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndexMap[currentChar] = right;
            
            // Calculate the length of the current window and update maxLength
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

// Example usage:
int main() {
    Solution solution;
    std::string s1 = "abcabcbb";
    std::cout << "Input string: \"" << s1 << "\"" << std::endl;
    std::cout << "Brute-force approach: " << solution.lengthOfLongestSubstring_brute_force(s1) << std::endl; // Output: 3
    std::cout << "Two-pointer approach: " << solution.lengthOfLongestSubstring_two_pointer(s1) << std::endl; // Output: 3

    std::string s2 = "bbbbb";
    std::cout << "\nInput string: \"" << s2 << "\"" << std::endl;
    std::cout << "Brute-force approach: " << solution.lengthOfLongestSubstring_brute_force(s2) << std::endl; // Output: 1
    std::cout << "Two-pointer approach: " << solution.lengthOfLongestSubstring_two_pointer(s2) << std::endl; // Output: 1

    std::string s3 = "pwwkew";
    std::cout << "\nInput string: \"" << s3 << "\"" << std::endl;
    std::cout << "Brute-force approach: " << solution.lengthOfLongestSubstring_brute_force(s3) << std::endl; // Output: 3
    std::cout << "Two-pointer approach: " << solution.lengthOfLongestSubstring_two_pointer(s3) << std::endl; // Output: 3

    return 0;
}
