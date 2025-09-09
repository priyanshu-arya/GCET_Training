class Solution:
    def lengthOfLongestSubstring_brute_force(self, s: str) -> int:
        '''
        Finds the length of the longest substring using a brute-force approach.
        Time Complexity: O(n^2) to O(n^3) depending on implementation.
        Space Complexity: O(k) where k is the size of the character set.
        '''
        n = len(s)
        maxLength = 0
        for i in range(n):
            for j in range(i, n):
                substring = s[i:j+1]
                # Check for uniqueness
                if len(set(substring)) == len(substring):
                    maxLength = max(maxLength, len(substring))
        return maxLength

    def lengthOfLongestSubstring_two_pointer(self, s: str) -> int:
        '''
        Finds the length of the longest substring using the two-pointer technique.
        Time Complexity: O(n)
        Space Complexity: O(k) where k is the size of the character set.
        '''
        charIndexMap = {}
        left = 0
        maxLength = 0
        
        for right in range(len(s)):
            if s[right] in charIndexMap and charIndexMap[s[right]] >= left:
                left = charIndexMap[s[right]] + 1
            
            charIndexMap[s[right]] = right
            maxLength = max(maxLength, right - left + 1)
        
        return maxLength
    
# Example usage:
if __name__ == "__main__":
    solution = Solution()
    s = "abcabcbb"
    
    print("Brute-force approach:", solution.lengthOfLongestSubstring_brute_force(s))  # Output: 3
    print("Two-pointer approach:", solution.lengthOfLongestSubstring_two_pointer(s))  # Output: 3