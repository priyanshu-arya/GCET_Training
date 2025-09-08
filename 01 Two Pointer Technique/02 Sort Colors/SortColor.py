def sortColors_counting(nums):
    """
    Sorts an array of 0s, 1s, and 2s using the counting sort method.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    count0 = 0
    count1 = 0
    count2 = 0

    # First pass: count the occurrences of each color
    for num in nums:
        if num == 0:
            count0 += 1
        elif num == 1:
            count1 += 1
        else:  # num == 2
            count2 += 1

    # Second pass: overwrite the array with the sorted colors
    index = 0
    for _ in range(count0):
        nums[index] = 0
        index += 1
    
    for _ in range(count1):
        nums[index] = 1
        index += 1
        
    for _ in range(count2):
        nums[index] = 2
        index += 1
    
    # Alternatively, a more concise way to overwrite:
    # nums[:count0] = [0] * count0
    # nums[count0 : count0 + count1] = [1] * count1
    # nums[count0 + count1 : count0 + count1 + count2] = [2] * count2
    

def sortColors_dutch_flag(nums):
    """
    Sorts an array of 0s, 1s, and 2s using the Dutch National Flag algorithm.
    This is a one-pass algorithm.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    low = 0
    mid = 0
    high = len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1

# Example usage:
if __name__ == "__main__":
    colors = [2, 0, 2, 1, 1, 0]
    print("Original array:", colors)
    
    # Using counting sort method
    sortColors_counting(colors)
    print("Sorted array (counting sort):", colors)
    
    colors = [2, 0, 2, 1, 1, 0]
    
    # Using Dutch National Flag algorithm
    sortColors_dutch_flag(colors)
    print("Sorted array (Dutch National Flag):", colors)