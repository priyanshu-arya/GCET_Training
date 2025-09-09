### Problem Analysis

The problem asks for the length of the longest substring within a given string `s` that does not contain any repeating characters. It's important to distinguish between a "substring" (a contiguous sequence of characters) and a "subsequence" (characters in order but not necessarily contiguous). For example, in "pwwkew", "wke" is a substring, but "pwke" is a subsequence.

The constraints are:

  * `0 <= s.length <= 5 * 10^4`
  * `s` can contain a mix of letters, digits, symbols, and spaces.

The length of the string (up to 50,000) indicates that an algorithm with $O(n^2)$ time complexity might be too slow and could time out. We should strive for a linear time, $O(n)$, solution.

-----

### Method 1: Brute Force

This approach involves checking every possible substring to see if it contains duplicate characters and then keeping track of the length of the longest valid one found.

**Algorithm:**

1.  Initialize a variable `maxLength` to 0.
2.  Use a nested loop to generate all possible substrings. The outer loop `i` will define the start of the substring, and the inner loop `j` will define the end.
3.  For each substring from `i` to `j`, use a helper data structure (like a Set) to check for duplicate characters.
4.  Iterate through the characters of the substring. If a character is already in the set, the substring has a repeat. If you reach the end of the substring without finding repeats, it's a valid one.
5.  If the substring is valid, update `maxLength = max(maxLength, length_of_substring)`.
6.  After checking all substrings, `maxLength` will be the answer.

**Example Walkthrough:**
`s = "abcabcbb"`

1.  **i=0:**
      * "a" -\> valid, len=1, `maxLength`=1
      * "ab" -\> valid, len=2, `maxLength`=2
      * "abc" -\> valid, len=3, `maxLength`=3
      * "abca" -\> invalid (repeats 'a')
      * ...and so on.
2.  **i=1:**
      * "b" -\> valid, len=1, `maxLength`=3
      * "bc" -\> valid, len=2, `maxLength`=3
      * "bca" -\> valid, len=3, `maxLength`=3
      * "bcab" -\> invalid (repeats 'b')
      * ...and so on.

This process continues until all substrings are checked. The final `maxLength` will be 3.

**Python Code:**

```python
def lengthOfLongestSubstring_brute_force(s: str) -> int:
    """
    Finds the length of the longest substring using a brute-force approach.
    Time Complexity: O(n^2) to O(n^3) depending on implementation.
    Space Complexity: O(k) where k is the size of the character set.
    """
    n = len(s)
    maxLength = 0
    for i in range(n):
        for j in range(i, n):
            substring = s[i:j+1]
            # Check for uniqueness
            if len(set(substring)) == len(substring):
                maxLength = max(maxLength, len(substring))
    return maxLength
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n^3)$
      * The two nested loops to generate substrings run in $O(n^2)$.
      * For each substring, creating a set from it takes time proportional to its length (up to $O(n)$).
      * This results in a total time complexity of $O(n^3)$. A more optimized check can bring it to $O(n^2)$, but it's still too slow for the given constraints.
  * **Space Complexity:** $O(k)$
      * The space required for the set depends on the number of unique characters in the substring, which is at most `k`, the size of the character set (e.g., 256 for extended ASCII).

-----

### Method 2: Sliding Window (Optimal) ✅

This is the most efficient approach. We can think of an imaginary "window" over the string. We expand this window by moving its right end. If we find a character that is already inside our current window, we shrink the window from the left end until the duplicate character is removed.

We use a hash map (or an array as a frequency map) to store the most recent index of each character we've encountered.

**Algorithm:**

1.  Initialize `maxLength = 0`.
2.  Initialize a `left` pointer (start of the window) to `0`.
3.  Initialize a hash map, `charIndexMap`, to store `character -> last_seen_index`.
4.  Iterate through the string with a `right` pointer from `0` to `n-1`.
5.  At each character `s[right]`:
      * Check if `s[right]` is already in `charIndexMap`.
      * If it is, it means we've seen this character before. We need to check if its last occurrence is *within our current window*. The window is from `left` to `right`. So, if `charIndexMap[s[right]] >= left`, the character is a duplicate *in the window*.
      * If it's a duplicate in the window, we must shrink the window by moving the `left` pointer to the position right after the previous occurrence: `left = charIndexMap[s[right]] + 1`.
6.  Update the character's last seen index in the map: `charIndexMap[s[right]] = right`.
7.  Calculate the length of the current valid window: `right - left + 1`.
8.  Update `maxLength = max(maxLength, current_window_length)`.
9.  After the loop, return `maxLength`.

**Example Walkthrough:**
`s = "abcabcbb"`

| `right` | `char` | `charIndexMap`             | `left` | `maxLength` | Action |
|:-------:|:------:|:---------------------------|:------:|:-----------:|:-------|
| 0       | 'a'    | {'a': 0}                   | 0      | 1           | Update map. `maxLen` = max(0, 0-0+1) = 1 |
| 1       | 'b'    | {'a': 0, 'b': 1}           | 0      | 2           | Update map. `maxLen` = max(1, 1-0+1) = 2 |
| 2       | 'c'    | {'a': 0, 'b': 1, 'c': 2}   | 0      | 3           | Update map. `maxLen` = max(2, 2-0+1) = 3 |
| 3       | 'a'    | {'a': 3, 'b': 1, 'c': 2}   | 1      | 3           | 'a' is in map. Its old index (0) \>= `left` (0). Move `left` to old index + 1. `left` = 1. `maxLen` = max(3, 3-1+1) = 3 |
| 4       | 'b'    | {'a': 3, 'b': 4, 'c': 2}   | 2      | 3           | 'b' is in map. Its old index (1) \>= `left` (1). Move `left` to old index + 1. `left` = 2. `maxLen` = max(3, 4-2+1) = 3 |
| 5       | 'c'    | {'a': 3, 'b': 4, 'c': 5}   | 3      | 3           | 'c' is in map. Its old index (2) \>= `left` (2). Move `left` to old index + 1. `left` = 3. `maxLen` = max(3, 5-3+1) = 3 |
| 6       | 'b'    | {'a': 3, 'b': 6, 'c': 5}   | 5      | 2           | 'b' is in map. Its old index (4) \>= `left` (3). Move `left` to old index + 1. `left` = 5. `maxLen` = max(3, 6-5+1) = 3 |

The final answer is 3.

**Python Code:**

```python
def lengthOfLongestSubstring_sliding_window(s: str) -> int:
    """
    Finds the length of the longest substring using an optimal sliding window.
    Time Complexity: O(n)
    Space Complexity: O(k)
    """
    charIndexMap = {}
    left = 0
    maxLength = 0
    
    for right in range(len(s)):
        currentChar = s[right]
        # If the character is in the map and its index is within the current window
        if currentChar in charIndexMap and charIndexMap[currentChar] >= left:
            # Move the left pointer to the right of the last occurrence
            left = charIndexMap[currentChar] + 1
            
        # Update the last seen index of the current character
        charIndexMap[currentChar] = right
        
        # Calculate the length of the current window and update max
        maxLength = max(maxLength, right - left + 1)
        
    return maxLength
```

**Complexity Analysis:**

  * **Time Complexity:** $O(n)$
      * The algorithm makes a single pass through the string. Both the `left` and `right` pointers only ever move forward. Each character is visited at most twice (once by `right` and once by `left`).
  * **Space Complexity:** $O(k)$
      * The space used by the hash map depends on the number of unique characters in the string. In the worst case (all unique characters), it's $O(n)$. In the best case, it's $O(1)$. More accurately, it's $O(k)$ where `k` is the size of the character set, since the map can't grow larger than that.

### Summary of Solutions

| Method                           | Time Complexity | Space Complexity | Description                                                                                    | Optimal |
|----------------------------------|-----------------|------------------|------------------------------------------------------------------------------------------------|---------|
| **1. Brute Force** | $O(n^3)$        | $O(k)$           | Checks every possible substring for uniqueness. Inefficient and too slow for large inputs.     | No      |
| **2. Sliding Window** | $O(n)$          | $O(k)$           | Maintains a window of unique characters, expanding and shrinking it in one pass. **(Recommended)** | Yes ✅   |