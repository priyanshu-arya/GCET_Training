# Two Pointers Technique

## 📑 Table of Contents
- [1. Introduction: What is the Two Pointers Technique?](#1-introduction-what-is-the-two-pointers-technique)
- [2. Core Patterns of Two Pointers](#2-core-patterns-of-two-pointers)
  - [Pattern 1: Converging Pointers (Opposite Ends)](#pattern-1-converging-pointers-opposite-ends)
  - [Pattern 2: Fast and Slow Pointers (Same Direction)](#pattern-2-fast-and-slow-pointers-same-direction)
  - [Pattern 3: Sliding Window](#pattern-3-sliding-window)
- [3. How to Identify a Two Pointers Problem](#3-how-to-identify-a-two-pointers-problem)
- [4. Selected Interview Questions from Top Companies](#4-selected-interview-questions-from-top-companies)
  - [Easy](#easy)
    - [1. Valid Palindrome](#1-valid-palindrome)
    - [2. Squares of a Sorted Array](#2-squares-of-a-sorted-array)
  - [Medium](#medium)
    - [3. 3Sum](#3-3sum)
    - [4. Container With Most Water](#4-container-with-most-water)
    - [5. Sort Colors (Dutch National Flag)](#5-sort-colors-dutch-national-flag)
  - [Hard](#hard)
    - [6. Trapping Rain Water](#6-trapping-rain-water)
- [Crafted with Love ❤️ by Priyanshu Arya (The Tech Intel)](#crafted-with-love-️-by-priyanshu-arya-the-tech-intel)

---

## 1. Introduction: What is the Two Pointers Technique?

The **Two Pointers** technique is a powerful and efficient algorithm pattern primarily used for problems involving sorted arrays, linked lists, or strings. The core idea is to use two pointers to iterate through the data structure, moving them based on certain conditions to solve the problem in a single pass.

This approach is highly valued in technical interviews because it often reduces the time complexity of a problem from a brute-force `O(n^2)` or `O(n^3)` down to a much more efficient **`O(n)`**, while typically using only `O(1)` constant extra space.

**Why is it so efficient?**  
By intelligently moving two pointers, we can effectively explore pairs, subarrays, or subsequences without nesting loops. Each pointer traverses a portion of the array, and in a single pass, both pointers together cover the necessary ground to find the solution.

---

## 2. Core Patterns of Two Pointers

The Two Pointers technique can be broadly categorized into three main patterns based on the direction and movement of the pointers.

### Pattern 1: Converging Pointers (Opposite Ends)

This is the most common pattern. Two pointers are initialized, one at the beginning (`left`) and one at the end (`right`) of a data structure (usually a sorted array). They then move towards each other until they meet or cross.

- **Initialization:** `left = 0`, `right = array.length - 1`  
- **Movement:** `left++` or `right--` based on conditions  
- **Termination:** Loop continues while `left < right`

**When to use it:**
- Searching for a pair in a **sorted array**  
- Palindrome problems  
- Finding a pair closest to a value  

**Example: Two Sum II - Input array is sorted**
```js
function twoSumSorted(numbers, target) {
  let left = 0;
  let right = numbers.length - 1;

  while (left < right) {
    let currentSum = numbers[left] + numbers[right];
    if (currentSum === target) {
      return [left + 1, right + 1];
    } else if (currentSum < target) {
      left++;
    } else {
      right--;
    }
  }
  return [];
}
````

---

### Pattern 2: Fast and Slow Pointers (Same Direction)

Both pointers start at or near the beginning but move at different speeds.

* **Initialization:** `slow = 0`, `fast = 0` (or `fast = 1`)
* **Movement:** `slow += 1`, `fast += 2`
* **Termination:** Ends when `fast` reaches the end

**When to use it:**

* Cycle detection in linked lists
* Finding middle of list
* Removing duplicates in arrays

**Example: Linked List Cycle Detection**

```js
function hasCycle(head) {
  if (!head) return false;
  let slow = head, fast = head;

  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) return true;
  }
  return false;
}
```

---

### Pattern 3: Sliding Window

A variation of same-direction pointers.

* **Initialization:** `start = 0`, `end = 0`
* **Movement:** Expand `end++`, shrink with `start++` when condition fails

**When to use it:**

* Longest/shortest subarray problems
* Substring problems
* Window-based optimization

**Example: Longest Substring Without Repeating Characters**

```js
function lengthOfLongestSubstring(s) {
  let maxLength = 0, start = 0;
  const charMap = new Map();

  for (let end = 0; end < s.length; end++) {
    const currentChar = s[end];
    if (charMap.has(currentChar) && charMap.get(currentChar) >= start) {
      start = charMap.get(currentChar) + 1;
    }
    charMap.set(currentChar, end);
    maxLength = Math.max(maxLength, end - start + 1);
  }
  return maxLength;
}
```

---

## 3. How to Identify a Two Pointers Problem

* **Sorted Input** → Converging Pointers
* **Pairs or Triplets** → Converging Pointers
* **Subarray / Substring** → Sliding Window
* **In-place modification** → Fast & Slow Pointers
* **Linked List structure** → Fast & Slow Pointers
* **Optimization required** → Two Pointers is a strong candidate

---

## 4. Selected Interview Questions from Top Companies

### Easy

#### 1. Valid Palindrome

```js
function isPalindrome(s) {
  s = s.toLowerCase().replace(/[^a-z0-9]/g, '');
  let left = 0, right = s.length - 1;
  while (left < right) {
    if (s[left] !== s[right]) return false;
    left++;
    right--;
  }
  return true;
}
```

#### 2. Squares of a Sorted Array

```js
function sortedSquares(nums) {
  const n = nums.length, result = new Array(n);
  let left = 0, right = n - 1;
  for (let i = n - 1; i >= 0; i--) {
    if (Math.abs(nums[left]) > Math.abs(nums[right])) {
      result[i] = nums[left] ** 2;
      left++;
    } else {
      result[i] = nums[right] ** 2;
      right--;
    }
  }
  return result;
}
```

---

### Medium

#### 3. 3Sum

```js
function threeSum(nums) {
  nums.sort((a, b) => a - b);
  const result = [];
  for (let i = 0; i < nums.length - 2; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    let left = i + 1, right = nums.length - 1, target = -nums[i];
    while (left < right) {
      const sum = nums[left] + nums[right];
      if (sum === target) {
        result.push([nums[i], nums[left], nums[right]]);
        while (left < right && nums[left] === nums[left + 1]) left++;
        while (left < right && nums[right] === nums[right - 1]) right--;
        left++; right--;
      } else if (sum < target) left++;
      else right--;
    }
  }
  return result;
}
```

#### 4. Container With Most Water

```js
function maxArea(height) {
  let maxWater = 0, left = 0, right = height.length - 1;
  while (left < right) {
    const width = right - left;
    const currentHeight = Math.min(height[left], height[right]);
    maxWater = Math.max(maxWater, width * currentHeight);
    if (height[left] < height[right]) left++;
    else right--;
  }
  return maxWater;
}
```

#### 5. Sort Colors (Dutch National Flag)

```js
function sortColors(nums) {
  let low = 0, mid = 0, high = nums.length - 1;
  while (mid <= high) {
    if (nums[mid] === 0) {
      [nums[low], nums[mid]] = [nums[mid], nums[low]];
      low++; mid++;
    } else if (nums[mid] === 1) {
      mid++;
    } else {
      [nums[mid], nums[high]] = [nums[high], nums[mid]];
      high--;
    }
  }
}
```

---

### Hard

#### 6. Trapping Rain Water

```js
function trap(height) {
  if (height.length === 0) return 0;
  let left = 0, right = height.length - 1;
  let leftMax = 0, rightMax = 0, trappedWater = 0;

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) leftMax = height[left];
      else trappedWater += leftMax - height[left];
      left++;
    } else {
      if (height[right] >= rightMax) rightMax = height[right];
      else trappedWater += rightMax - height[right];
      right--;
    }
  }
  return trappedWater;
}
```

---

## Crafted with Love ❤️ by Priyanshu Arya (The Tech Intel)

📌 **Connect with Me:**
[LinkedIn](https://www.linkedin.com/in/priyanshu-arya/) | [Medium](https://medium.com/@priyanshuthetechintel?utm_source=chatgpt.com) | [Instagram](https://www.instagram.com/thetechintel/?utm_source=chatgpt.com) | [YouTube](https://www.youtube.com/@PriyanshuthetechIntel?utm_source=chatgpt.com)

🎯 **Schedule a Visual Connect (Free):**
[Book a Time Slot on Topmate](https://topmate.io/priyanshuthetechintel?utm_source=chatgpt.com)

📧 **For queries, collaborations, or corrections:**
Reach me at **[priyanshuthetechintel@gmail.com](mailto:priyanshuthetechintel@gmail.com)**


