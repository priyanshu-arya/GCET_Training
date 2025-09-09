
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LUS {

    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(k) where k is the size of the character set.
     */
    public int lengthOfLongestSubstring_brute_force(String s) {
        int n = s.length();
        if (n == 0) return 0;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            Set<Character> charSet = new HashSet<>();
            for (int j = i; j < n; j++) {
                // The add method returns false if the element is already in the set.
                if (!charSet.add(s.charAt(j))) {
                    // Duplicate found, break the inner loop.
                    break;
                }
                // Update max length with the current valid substring's length.
                maxLength = Math.max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }

    /**
     * Time Complexity: O(n)
     * Space Complexity: O(k) where k is the size of the character set.
     */
    public int lengthOfLongestSubstring_two_pointer(String s) {
        Map<Character, Integer> charIndexMap = new HashMap<>();
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            // Check if the character is in the map and its index is within the current window
            if (charIndexMap.containsKey(currentChar) && charIndexMap.get(currentChar) >= left) {
                // Move the left pointer to the right of the last occurrence
                left = charIndexMap.get(currentChar) + 1;
            }

            // Update the last seen index of the current character
            charIndexMap.put(currentChar, right);

            // Calculate the length of the current window and update max
            maxLength = Math.max(maxLength, right - left + 1);
        }
        return maxLength;
    }

    // Example usage:
    public static void main(String[] args) {
        LUS solution = new LUS();
        String s1 = "abcabcbb";
        System.out.println("Input string: \"" + s1 + "\"");
        System.out.println("Brute-force approach: " + solution.lengthOfLongestSubstring_brute_force(s1)); // Output: 3
        System.out.println("Two-pointer approach: " + solution.lengthOfLongestSubstring_two_pointer(s1)); // Output: 3

        String s2 = "bbbbb";
        System.out.println("\nInput string: \"" + s2 + "\"");
        System.out.println("Brute-force approach: " + solution.lengthOfLongestSubstring_brute_force(s2)); // Output: 1
        System.out.println("Two-pointer approach: " + solution.lengthOfLongestSubstring_two_pointer(s2)); // Output: 1
        
        String s3 = "pwwkew";
        System.out.println("\nInput string: \"" + s3 + "\"");
        System.out.println("Brute-force approach: " + solution.lengthOfLongestSubstring_brute_force(s3)); // Output: 3
        System.out.println("Two-pointer approach: " + solution.lengthOfLongestSubstring_two_pointer(s3)); // Output: 3
    }
}
