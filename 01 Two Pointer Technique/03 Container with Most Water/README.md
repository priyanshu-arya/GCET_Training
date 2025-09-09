### Problem Analysis

The problem gives us an array of non-negative integers called `height`, where each integer represents the height of a vertical line at a specific x-coordinate. We need to find two of these lines that, together with the x-axis, form a container that can hold the most water. The area of the water is determined by the distance between the two lines (the width) and the height of the shorter of the two lines.

The formula for the area between two lines at indices `i` and `j` (with `i < j`) is:
`Area = width * height = (j - i) * min(height[i], height[j])`

Our goal is to maximize this area.

The constraints are:

  * `n == height.length`
  * `2 <= n <= 10^5`
  * `0 <= height[i] <= 10^4`

The large value of `n` (up to 100,000) suggests that a solution with a time complexity of $O(n^2)$, which would involve checking every possible pair of lines, will be too slow and likely fail due to a "Time Limit Exceeded" error. We should aim for a more efficient approach, likely linear time, $O(n)$.

-----

### Method 1: Brute Force (Two-Pass Nested Loop)

The most straightforward approach is to consider every possible pair of vertical lines, calculate the area for each pair, and keep track of the maximum area found so far.

**Algorithm:**

1.  Initialize a variable `max_area` to 0.
2.  Use a nested loop to iterate through all possible pairs of lines `(i, j)` where `i < j`.
      * The outer loop runs from `i = 0` to `n-2`.
      * The inner loop runs from `j = i + 1` to `n-1`.
3.  For each pair, calculate the width (`j - i`) and the height (`min(height[i], height[j])`).
4.  Compute the current area and update `max_area` if the current area is larger.
5.  After the loops complete, `max_area` will hold the result.

**Example Walkthrough:**
`height = [1, 8, 6, 2]`

1.  **Initial:** `max_area = 0`
2.  **(i=0, j=1):** `width = 1`, `h = min(1, 8) = 1`, `area = 1*1 = 1`. `max_area` is now 1.
3.  **(i=0, j=2):** `width = 2`, `h = min(1, 6) = 1`, `area = 2*1 = 2`. `max_area` is now 2.
4.  **(i=0, j=3):** `width = 3`, `h = min(1, 2) = 1`, `area = 3*1 = 3`. `max_area` is now 3.
5.  **(i=1, j=2):** `width = 1`, `h = min(8, 6) = 6`, `area = 1*6 = 6`. `max_area` is now 6.
6.  **(i=1, j=3):** `width = 2`, `h = min(8, 2) = 2`, `area = 2*2 = 4`. `max_area` is still 6.
7.  **(i=2, j=3):** `width = 1`, `h = min(6, 2) = 2`, `area = 1*2 = 2`. `max_area` is still 6.

Final `max_area` is 6.

**Python Code:**

```python
def maxArea_brute_force(height: list[int]) -> int:
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
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n^2)$
      * The nested loops cause the area calculation to be performed for every pair of lines. For an array of size `n`, this is approximately $\\frac{n(n-1)}{2}$ pairs, leading to a quadratic time complexity. This is too slow for the given constraints.
  * **Space Complexity:** $O(1)$
      * We only use a few variables to store the maximum area and loop indices. The space required does not grow with the input size.

-----

### Method 2: Two-Pointer (One-Pass Algorithm)

This is the optimal and intended solution. The idea is to start with the widest possible container and iteratively narrow it down, discarding the worse of the two lines at each step.

We use two pointers, `left` starting at the beginning of the array and `right` starting at the end.

**Algorithm:**

1.  Initialize `left = 0`, `right = len(height) - 1`, and `max_area = 0`.
2.  Loop as long as `left < right`.
3.  Inside the loop, calculate the area for the container formed by the lines at `left` and `right`.
      * `width = right - left`
      * `h = min(height[left], height[right])`
      * `current_area = width * h`
4.  Update `max_area = max(max_area, current_area)`.
5.  Now, move one of the pointers. The key insight is to **move the pointer corresponding to the shorter line**. Why? Because the width is decreasing with every step. To have any chance of finding a larger area, we need a greater height. Moving the pointer of the taller line won't help, as the height is always limited by the shorter line. By moving the shorter line's pointer, we explore the possibility of finding a taller line that might compensate for the reduced width.
      * If `height[left] < height[right]`, increment `left`.
      * Otherwise, decrement `right`.
6.  The loop terminates when the pointers meet. Return `max_area`.

**Example Walkthrough:**
`height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`

| `left` | `right` | `height[left]` | `height[right]` | Width | Height | Area | `max_area` | Action to take |
|:------:|:-------:|:--------------:|:---------------:|:-----:|:------:|:----:|:----------:|:---------------|
| 0      | 8       | 1              | 7               | 8     | 1      | 8    | 8          | `height[0]<height[8]`, `left++` |
| 1      | 8       | 8              | 7               | 7     | 7      | 49   | **49** | `height[1]>height[8]`, `right--` |
| 1      | 7       | 8              | 3               | 6     | 3      | 18   | 49         | `height[1]>height[7]`, `right--` |
| 1      | 6       | 8              | 8               | 5     | 8      | 40   | 49         | `height[1]<=height[6]`, `right--` |
| 1      | 5       | 8              | 4               | 4     | 4      | 16   | 49         | `height[1]>height[5]`, `right--` |
| 1      | 4       | 8              | 5               | 3     | 5      | 15   | 49         | `height[1]>height[4]`, `right--` |
| 1      | 3       | 8              | 2               | 2     | 2      | 4    | 49         | `height[1]>height[3]`, `right--` |
| 1      | 2       | 8              | 6               | 1     | 6      | 6    | 49         | `height[1]>height[2]`, `right--` |

`left` is now 1 and `right` is 1. The condition `left < right` is false, so the loop terminates. The final answer is **49**.

**Python Code:**

```python
def maxArea_two_pointer(height: list[int]) -> int:
    """
    Finds the max area using an optimal one-pass two-pointer approach.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left = 0
    right = len(height) - 1
    max_area = 0
    
    while left < right:
        # Calculate width and height
        width = right - left
        h = min(height[left], height[right])
        
        # Calculate area and update max_area
        current_area = width * h
        max_area = max(max_area, current_area)
        
        # Move the pointer of the shorter line
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
            
    return max_area
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n)$
      * The algorithm makes a single pass through the array. The `left` pointer moves from left to right, and the `right` pointer moves from right to left. Since they only move in one direction and stop when they meet, we traverse the array at most once.
  * **Space Complexity:** $O(1)$
      * We only use three variables (`left`, `right`, `max_area`), which take up a constant amount of space.

### Summary of Solutions

| Method                           | Time Complexity | Space Complexity | Description                                                                                   | Optimal |
|----------------------------------|-----------------|------------------|-----------------------------------------------------------------------------------------------|---------|
| **1. Brute Force** | $O(n^2)$        | $O(1)$           | Checks every possible pair of lines using nested loops. Too slow for the problem constraints. | No      |
| **2. Two-Pointer** (One-Pass)    | $O(n)$          | $O(1)$           | Starts with the widest container and moves the shorter line's pointer inward. **(Recommended)** | Yes ✅   |

The most efficient and recommended solution is **Method 2 (Two-Pointer Algorithm)** as it solves the problem in a single pass with constant extra space.