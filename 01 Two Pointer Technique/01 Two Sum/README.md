## 🔹 Problem

We are given:

* `nums[]` (array of integers),
* `target` (an integer).

We must **find two indices `i` and `j` such that `nums[i] + nums[j] == target`**.

Constraints guarantee:

* Exactly one solution exists.
* We cannot use the same element twice.

---

## ✅ Solution Approaches

### **1. Brute Force (Double Loop)**

* Check every possible pair `(i, j)` with `i < j`.
* If `nums[i] + nums[j] == target`, return `[i, j]`.

**Code (Python):**

```python
def twoSum(nums, target):
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
```

* **Time Complexity:** O(n²)
* **Space Complexity:** O(1)

---

### **2. Hash Map (One-Pass) → Optimal**

* Use a hash map to store `num → index`.
* For each element `x`, check if `target - x` is already in the map.
* If yes → return `[map[target-x], i]`.
* Otherwise, store `x` in the map.

**Code:**

```python
def twoSum(nums, target):
    num_to_index = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in num_to_index:
            return [num_to_index[diff], i]
        num_to_index[num] = i
```

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---

### **3. Two Pointers (After Sorting)**

* Sort the array (but we lose original indices → must store `(value, index)` pairs).
* Use two pointers (`l` and `r`).
* If `nums[l] + nums[r] == target`, return their original indices.
* If sum < target → move left pointer.
* If sum > target → move right pointer.

**Code:**

```python
def twoSum(nums, target):
    indexed_nums = [(num, i) for i, num in enumerate(nums)]
    indexed_nums.sort()  # sort by value
    
    l, r = 0, len(nums) - 1
    while l < r:
        total = indexed_nums[l][0] + indexed_nums[r][0]
        if total == target:
            return [indexed_nums[l][1], indexed_nums[r][1]]
        elif total < target:
            l += 1
        else:
            r -= 1
```

* **Time Complexity:** O(n log n) (due to sorting)
* **Space Complexity:** O(n)

---

### **4. Using Binary Search**

* For each element, compute `target - nums[i]`.
* Search for it in the array using binary search.
* Requires a **sorted array**.

**Code (conceptual):**

```python
import bisect

def twoSum(nums, target):
    indexed_nums = [(num, i) for i, num in enumerate(nums)]
    indexed_nums.sort()
    
    for i in range(len(nums)):
        complement = target - indexed_nums[i][0]
        j = bisect.bisect_left(indexed_nums, (complement, -1), i + 1)
        if j < len(nums) and indexed_nums[j][0] == complement:
            return [indexed_nums[i][1], indexed_nums[j][1]]
```

* **Time Complexity:** O(n log n)
* **Space Complexity:** O(n)

---

### **5. Using Set (Not directly indices, but can be extended)**

* Keep a set of seen numbers.
* For each number `x`, check if `target - x` is in the set.
* Need a map to store indices as well.

**Code:**

```python
def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        if target - num in seen:
            return [seen[target - num], i]
        seen[num] = i
```

* This is basically same as the hash map solution.

---


## 📊 Comparison of Approaches

| Approach               | Time Complexity | Space Complexity | Notes                   |
| ---------------------- | --------------- | ---------------- | ----------------------- |
| Brute Force            | O(n²)           | O(1)             | Simple but slow         |
| Hash Map (One-pass)    | O(n)            | O(n)             | ✅ Best choice           |
| Two Pointers (Sorting) | O(n log n)      | O(n)             | Loses order             |
| Binary Search          | O(n log n)      | O(n)             | Similar to two pointers |
| Set/Hashing            | O(n)            | O(n)             | Same as hashmap         |

---

👉 So in interviews, the **expected optimal answer** is **Hash Map O(n)**.
Other methods are useful for **discussion and trade-offs**.

---

