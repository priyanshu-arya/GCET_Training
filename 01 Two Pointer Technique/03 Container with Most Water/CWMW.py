class Solution:
    def maxArea_brute_force(self, height: list[int]) -> int:
        """
        Finds the max area using a brute-force nested loop approach.
        Time Complexity: O(n^2)
        Space Complexity: O(1)
        """
        n = len(height)
        max_area = 0
        
        for i in range(n):
            for j in range(i + 1, n):
                # Calculate width and height
                width = j - i
                h = min(height[i], height[j])
                
                # Calculate area and update max_area
                current_area = width * h
                max_area = max(max_area, current_area)
                
        return max_area

    def maxArea_two_pointer(self, height: list[int]) -> int:
        """
        Finds the max area using the two-pointer technique.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        left, right = 0, len(height) - 1
        max_area = 0
        
        while left < right:
            # Calculate width and height
            width = right - left
            h = min(height[left], height[right])
            
            # Calculate area and update max_area
            current_area = width * h
            max_area = max(max_area, current_area)
            
            # Move the pointer pointing to the shorter line
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return max_area

# Example usage:
if __name__ == "__main__":
    solution = Solution()
    height = [1,8,6,2,5,4,8,3,7]
    
    print("Brute-force approach:", solution.maxArea_brute_force(height))  # Output: 49
    print("Two-pointer approach:", solution.maxArea_two_pointer(height))  # Output: 49