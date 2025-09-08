### Problem Analysis

The problem asks us to sort an array containing only the numbers 0, 1, and 2, representing the colors red, white, and blue. The sorting should be done "in-place," meaning we cannot create a new array. We also cannot use the built-in `sort` function. The final sorted array should have all the 0s first, then all the 1s, and finally all the 2s.

The constraints are:

  * `1 <= n <= 300`
  * `nums[i]` is 0, 1, or 2.

The follow-up question is a crucial hint: "Could you come up with a one-pass algorithm using only constant extra space?" This suggests that a simple counting sort might not be the most optimal solution in terms of the number of passes, and a two-pointer approach is likely what they are looking for.

Let's explore the possible ways to solve this.

-----

### Method 1: Counting Sort (Two-Pass Algorithm)

This is a straightforward and intuitive approach. We can count the occurrences of each color (0, 1, and 2) and then rebuild the array based on these counts.

**Algorithm:**

1.  **Count:** Iterate through the array once and count the number of 0s, 1s, and 2s. We can use three variables, say `count0`, `count1`, and `count2`.
2.  **Rebuild:** Iterate through the array again, this time placing the sorted numbers back into the original array.
      * Place `count0` number of 0s at the beginning.
      * Then, place `count1` number of 1s.
      * Finally, place `count2` number of 2s.

**Example Walkthrough:**
`nums = [2, 0, 2, 1, 1, 0]`

1.  **Count:**

      * `count0 = 2`
      * `count1 = 2`
      * `count2 = 2`

2.  **Rebuild:**

      * `nums[0] = 0`, `nums[1] = 0`
      * `nums[2] = 1`, `nums[3] = 1`
      * `nums[4] = 2`, `nums[5] = 2`

    Final `nums` is `[0, 0, 1, 1, 2, 2]`

**Python Code:**

```python
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

```

**Complexity Analysis:**

  * **Time Complexity:** $O(n)$
      * The first loop to count the numbers runs in $O(n)$ time.
      * The second part to overwrite the array also takes $O(n)$ time in total (since we iterate `n` times in total).
      * The overall time complexity is $O(n) + O(n) = O(n)$.
  * **Space Complexity:** $O(1)$
      * We are only using a few constant variables (`count0`, `count1`, `count2`, `index`) to store the counts and the current position. The space used does not depend on the size of the input array. The sorting is done in-place.

-----

### Method 2: One-Pass (Dutch National Flag Algorithm)

This is the optimal solution and addresses the "follow-up" question. The Dutch National Flag algorithm is a classic and efficient approach for this specific problem. It partitions the array into three sections:

  * Elements from `0` to `low-1` are all 0s.
  * Elements from `low` to `mid-1` are all 1s.
  * Elements from `mid` to `high` are yet to be sorted.
  * Elements from `high+1` to `n-1` are all 2s.

We use three pointers: `low`, `mid`, and `high`.

  * `low`: Points to the end of the `0`s section.
  * `mid`: Points to the current element being considered.
  * `high`: Points to the beginning of the `2`s section.

**Algorithm:**

1.  Initialize three pointers: `low = 0`, `mid = 0`, `high = n - 1`.
2.  Iterate while `mid <= high`.
3.  Inside the loop, check the value at `nums[mid]`:
      * **If `nums[mid]` is 0:**
          * Swap `nums[mid]` with `nums[low]`.
          * Increment both `low` and `mid`.
      * **If `nums[mid]` is 1:**
          * The element is in its correct place relative to the `0`s and `2`s sections.
          * Simply increment `mid`.
      * **If `nums[mid]` is 2:**
          * Swap `nums[mid]` with `nums[high]`.
          * Decrement `high`. We do not increment `mid` here because the element we just swapped from `high` could be a 0, 1, or 2, and we need to check its value in the next iteration.

**Example Walkthrough:**
`nums = [2, 0, 2, 1, 1, 0]`
`n = 6`
`low = 0`, `mid = 0`, `high = 5`

| Iteration | `nums`              | `mid` | `nums[mid]` | `low` | `high` | Action                                       |
|-----------|---------------------|-------|-------------|-------|--------|----------------------------------------------|
| Initial   | `[2, 0, 2, 1, 1, 0]`  | 0     | 2           | 0     | 5      |                                              |
| 1         | `[0, 0, 2, 1, 1, 2]`  | 0     | 2           | 0     | 4      | `nums[mid]` is 2, swap with `nums[high]`. `high`--. |
| 2         | `[0, 0, 2, 1, 1, 2]`  | 0     | 0           | 1     | 4      | `nums[mid]` is 0, swap with `nums[low]`. `low`++ and `mid`++. |
| 3         | `[0, 0, 2, 1, 1, 2]`  | 1     | 0           | 2     | 4      | `nums[mid]` is 0, swap with `nums[low]`. `low`++ and `mid`++. |
| 4         | `[0, 0, 2, 1, 1, 2]`  | 2     | 2           | 2     | 4      | `nums[mid]` is 2, swap with `nums[high]`. `high`--. |
| 5         | `[0, 0, 1, 1, 2, 2]`  | 2     | 1           | 2     | 3      | `nums[mid]` is 1, `mid`++.                      |
| 6         | `[0, 0, 1, 1, 2, 2]`  | 3     | 1           | 2     | 3      | `nums[mid]` is 1, `mid`++.                      |
| 7         | `[0, 0, 1, 1, 2, 2]`  | 4     | 2           | 2     | 3      | `mid > high`, loop terminates.                 |

Final `nums` is `[0, 0, 1, 1, 2, 2]`

**Python Code:**

```python
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
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n)$
      * The algorithm makes a single pass through the array. The `while` loop continues as long as `mid <= high`. In each iteration, `mid` is incremented or `high` is decremented, so the pointers always move towards each other. The total number of operations is proportional to the number of elements `n`.
  * **Space Complexity:** $O(1)$
      * We are using only three pointers (`low`, `mid`, `high`) which take up a constant amount of space. The sorting is done in-place.

-----

### Method 3: Sorting based on swaps (Less efficient but works)

This method is more of a brute-force approach that uses nested loops to place 0s and 2s correctly. It is not as efficient as the one-pass solution.

**Algorithm:**

1.  **Place all 0s:** Iterate through the array. When a `0` is found, swap it with the element at the current `zero_pointer` and increment the pointer.
2.  **Place all 2s:** Iterate through the array from the end. When a `2` is found, swap it with the element at the current `two_pointer` and decrement the pointer.

**Python Code:**

```python
def sortColors_two_pointer_basic(nums):
    """
    Sorts an array of 0s, 1s, and 2s using a basic two-pointer approach (two passes).
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    zero_ptr = 0
    two_ptr = n - 1

    # First pass: place all 0s at the beginning
    for i in range(n):
        if nums[i] == 0:
            nums[i], nums[zero_ptr] = nums[zero_ptr], nums[i]
            zero_ptr += 1

    # Second pass: place all 2s at the end
    for i in range(n - 1, -1, -1):
        if nums[i] == 2:
            nums[i], nums[two_ptr] = nums[two_ptr], nums[i]
            two_ptr -= 1
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n)$
      * The first loop for 0s takes $O(n)$ time.
      * The second loop for 2s also takes $O(n)$ time.
      * Total time complexity is $O(n) + O(n) = O(n)$.
  * **Space Complexity:** $O(1)$
      * Uses a few pointers, so the space is constant.

This method also solves the problem correctly and fulfills the time and space complexity requirements, but it's less elegant and intuitive than the one-pass Dutch National Flag algorithm. The Dutch National Flag algorithm is superior because it achieves the same result in a single pass, which is often a more desirable property in algorithm design.

### Summary of Solutions

| Method                               | Time Complexity | Space Complexity | Description                                                              | Follow-up |
|--------------------------------------|-----------------|------------------|--------------------------------------------------------------------------|-----------|
| **1. Counting Sort** (Two-Pass)      | $O(n)$          | $O(1)$           | Count occurrences of each number, then rebuild the array.                | No        |
| **2. Dutch National Flag** (One-Pass) | $O(n)$          | $O(1)$           | Uses three pointers to partition the array in a single pass. **(Optimal)** | Yes       |
| **3. Basic Two-Pointer** (Two-Pass)  | $O(n)$          | $O(1)$           | First, move all 0s to the front. Then, move all 2s to the end.           | No        |

The most efficient and recommended solution is **Method 2 (Dutch National Flag Algorithm)** as it meets all the constraints and the follow-up question.