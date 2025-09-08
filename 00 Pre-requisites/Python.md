# Python Data Structures & Algorithms (DSA) Cheat Sheet
A comprehensive guide to Python's built-in and standard library data structures for DSA students and competitive programmers.

## Table of Contents

1. **Sequence Types**
    - `list`
    - `tuple`
2. **Stacks, Queues, & Deques**
    - `collections.deque` (for Stacks and Queues)
    - `list` (as a simple Stack)
3. **Priority Queues**
    - `heapq`
4. **Sets**
    - `set`
5. **Mappings (Dictionaries)**
    - `dict`
6. **Code Examples**

## 1. Sequence Types

### `list` (Dynamic Array)

- **Description:** Python's equivalent of a dynamic array or vector. It's a mutable, ordered sequence of elements.
- **Best Use Cases:**
    - The primary, general-purpose sequence container.
    - When you need to store a collection of items that might change (add, remove, modify).
    - Fast access by index is required.

### Syntax & Initialization

```
# Empty list
list1 = []
list2 = list()

# Initialized list
list3 = [1, 2, 3, "hello"]

# List comprehension
list4 = [x * x for x in range(5)] # [0, 1, 4, 9, 16]

```

### Important Methods & Operations

| Method/Operation | Description | Time Complexity |
| --- | --- | --- |
| `append(val)` | Adds an element to the end. | Amortized O(1) |
| `pop()` / `pop(i)` | Removes and returns from end (O(1)) or index `i` (O(N)). | O(1) / O(N) |
| `insert(i, val)` | Inserts an element at index `i`. | O(N) |
| `list[i]` | Accesses the element at index `i`. | O(1) |
| `list[i] = val` | Replaces the element at index `i`. | O(1) |
| `len(list)` | Returns the number of elements. | O(1) |
| `val in list` | Checks if the list contains a value. | O(N) |
| `list.sort()` | Sorts the list in-place. | O(N log N) |
| `sorted(list)` | Returns a new sorted list. | O(N log N) |
| `list[i:j]` | Slicing. | O(j - i) |

### `tuple` (Immutable List)

- **Description:** An immutable, ordered sequence of elements. Once created, it cannot be changed.
- **Best Use Cases:**
    - When you need to ensure data integrity and prevent modification.
    - As keys in a dictionary (since they are hashable).
    - Returning multiple values from a function.

### Syntax & Initialization

```
tuple1 = ()
tuple2 = (1, "a", True)
tuple3 = 1, 2, 3 # "Packing" a tuple

```

## 2. Stacks, Queues, & Deques

### `collections.deque`

- **Module:** `from collections import deque`
- **Description:** A "double-ended queue" optimized for fast appends and pops from both ends.
- **Best Use Cases:**
    - The most efficient way to implement both a **Queue (FIFO)** and a **Stack (LIFO)**.
    - Breadth-First Search (BFS) and sliding window problems.

### Syntax & Initialization

```
from collections import deque

d = deque([1, 2, 3])

```

### Important Methods

| Stack (LIFO) Method | Queue (FIFO) Method | Description | Time Complexity |
| --- | --- | --- | --- |
| `append(val)` | `append(val)` | Adds to the right side. | O(1) |
| `pop()` | `popleft()` | Removes from the right / left side. | O(1) |
| `appendleft(val)` | N/A | Adds to the left side. | O(1) |
| `d[0]`, `d[-1]` | `d[0]` | Peek at left / right elements. | O(1) |
| `len(d)` | `len(d)` | Get the size. | O(1) |

> Note: A standard Python list can be used as a simple stack with append() and pop(), but deque is more efficient for queue operations.
> 

## 3. Priority Queues

### `heapq`

- **Module:** `import heapq`
- **Description:** This module provides functions for implementing a **Min-Heap** on top of a standard Python `list`.
- **Best Use Cases:**
    - Dijkstra's, Prim's, A* search algorithms.
    - Any time you need to efficiently find and extract the smallest item.
    - Finding the 'Kth' largest/smallest element.

### Syntax & Initialization

```
import heapq

# Start with an empty list
min_heap = []

# To turn an existing list into a heap in-place
# heapq.heapify(list_name)

```

### Important Functions

| Function | Description | Time Complexity |
| --- | --- | --- |
| `heapq.heappush(heap, val)` | Pushes a value onto the heap. | O(log N) |
| `heapq.heappop(heap)` | Pops and returns the smallest value. | O(log N) |
| `heap[0]` | Accesses the smallest value without popping. | O(1) |
| `heapq.heapify(list)` | Converts a list into a heap in-place. | O(N) |
| `heapq.heappushpop(h, v)` | Pushes `v`, then pops smallest. More efficient. | O(log N) |

> For Max-Heaps: Store negated values in the list and negate them again upon retrieval. heapq.heappush(heap, -value).
> 

## 4. Sets

### `set` (Hash Set)

- **Description:** An unordered collection of **unique**, hashable elements.
- **Best Use Cases:**
    - Extremely fast membership testing (`val in set`).
    - Removing duplicates from a sequence (`list(set(my_list))`).
    - Mathematical set operations like union, intersection, and difference.

### Syntax & Initialization

```
s1 = set()
s2 = {1, 2, 3, 3, 4} # s2 becomes {1, 2, 3, 4}

```

### Important Methods & Operations

| Method/Operation | Description | Time Complexity |
| --- | --- | --- |
| `add(val)` | Adds an element. | Avg: O(1) |
| `remove(val)` | Removes an element (raises KeyError if not found). | Avg: O(1) |
| `discard(val)` | Removes an element (does nothing if not found). | Avg: O(1) |
| `val in s` | Checks for an element. | Avg: O(1) |
| `s1 | s2` | Union (`s1.union(s2)`) |
| `s1 & s2` | Intersection (`s1.intersection(s2)`) | O(min(len(s1), len(s2))) |
| `s1 - s2` | Difference (`s1.difference(s2)`) | O(len(s1)) |

## 5. Mappings (Dictionaries)

### `dict` (Hash Map)

- **Description:** An implementation of a hash table that stores key-value pairs. As of Python 3.7+, dictionaries preserve insertion order.
- **Best Use Cases:**
    - The standard, go-to data structure for key-value storage.
    - Frequency counters (`collections.Counter` is a specialized subclass).
    - Caching/memoization.

### Syntax & Initialization

```
d1 = {}
d2 = dict()
d3 = {"apple": 1, "banana": 2}

```

### Important Methods & Operations

| Method/Operation | Description | Time Complexity |
| --- | --- | --- |
| `d[key] = val` | Adds or updates a key-value pair. | Avg: O(1) |
| `d[key]` | Retrieves a value by its key (raises KeyError). | Avg: O(1) |
| `get(key, default)` | Retrieves a value (returns default if not found). | Avg: O(1) |
| `key in d` | Checks if a key exists. | Avg: O(1) |
| `del d[key]` | Deletes a key-value pair. | Avg: O(1) |
| `keys()`, `values()`, `items()` | Returns views of keys, values, or (key, value) pairs. | O(1) |

## 6. Code Examples

```
import heapq
from collections import deque

# --- List Example ---
print("--- List Example ---")
fruits = ["apple", "orange", "banana"]
fruits.append("grape")
print(f"List: {fruits}")
print(f"Element at index 1: {fruits[1]}")

# --- Deque as Queue ---
print("\n--- Deque as Queue (FIFO) ---")
q = deque(["Job 1", "Job 2"])
q.append("Job 3")
print(f"Queue: {q}")
print(f"Processing: {q.popleft()}")
print(f"Queue after popleft: {q}")

# --- Min-Heap (heapq) ---
print("\n--- heapq (Min-Heap) Example ---")
min_heap = []
heapq.heappush(min_heap, 50)
heapq.heappush(min_heap, 20)
heapq.heappush(min_heap, 100)
print(f"Min-Heap: {min_heap}")
print(f"Smallest item: {min_heap[0]}")
print(f"Popped smallest: {heapq.heappop(min_heap)}")
print(f"Heap after pop: {min_heap}")

# --- Set Example ---
print("\n--- Set Example ---")
unique_fruits = {"apple", "orange", "apple"}
unique_fruits.add("banana")
print(f"Set: {unique_fruits}")
print(f"Is 'apple' in the set? {'apple' in unique_fruits}")

# --- Dictionary Example ---
print("\n--- Dictionary Example ---")
fruit_prices = {"apple": 10, "orange": 15}
fruit_prices["banana"] = 20
print(f"Dictionary: {fruit_prices}")
print(f"Price of apple: {fruit_prices.get('apple')}")

```

Crafted with Love by Priyanshu Arya (The Tech Intel)

📌 **Connect with Me:**

[LinkedIn](https://www.linkedin.com/in/priyanshu-arya/) | [Medium](https://medium.com/@priyanshuthetechintel?utm_source=chatgpt.com) | [Instagram](https://www.instagram.com/thetechintel/?utm_source=chatgpt.com) | [YouTube](https://www.youtube.com/@PriyanshuthetechIntel?utm_source=chatgpt.com)

🎯 **Schedule a Visual Connect (Free):**

[Book a Time Slot on Topmate](https://topmate.io/priyanshuthetechintel?utm_source=chatgpt.com)

📧 **For queries, collaborations, or corrections:**

Reach me at **priyanshuthetechintel@gmail.com**