````markdown
# A Comprehensive Guide to C++ STL Containers for DSA 🚀

An essential guide for students of Data Structures & Algorithms and competitive programmers, covering the most common containers in the C++ Standard Template Library (STL) with their use cases and time complexities.

---

## Table of Contents

1.  **Sequence Containers**
    * `std::vector`
    * `std::list`
    * `std::deque`
2.  **Container Adaptors**
    * `std::stack`
    * `std::queue`
    * `std::priority_queue`
3.  **Associative Containers (Ordered)**
    * `std::set`
    * `std::map`
    * `std::multiset`
    * `std::multimap`
4.  **Unordered Associative Containers (Hashed)**
    * `std::unordered_set`
    * `std::unordered_map`
5.  **Utility**
    * `std::string`
    * `std::pair`
    * `std::tuple`

---

## 1. Sequence Containers

### `std::vector`

**Header:** `#include <vector>`

**Description:** A dynamic array that can automatically resize itself. Elements are stored **contiguously** in memory.

**Best Use Cases:**
* The **default container** for sequence data. Use it when in doubt.
* Fast random access (by index) is required.
* Frequent additions or removals of elements at the **end** of the sequence.

#### Syntax & Initialization
```cpp
// Empty vector
std::vector<int> v1;

// Vector of size 5, initialized with 0
std::vector<int> v2(5);

// Vector of size 5, all elements are 10
std::vector<int> v3(5, 10);

// Initializer list
std::vector<int> v4 = {1, 2, 3, 4, 5};

// Copy constructor
std::vector<int> v5(v4);
````

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push_back(val)` | Adds an element to the end. | Amortized O(1) |
| `pop_back()` | Removes the last element. | O(1) |
| `size()` | Returns the number of elements. | O(1) |
| `empty()` | Returns true if the vector is empty. | O(1) |
| `clear()` | Removes all elements. | O(N) |
| `v[i]` | Accesses the element at index i. | O(1) |
| `at(i)` | Accesses element at index i (with bounds checking). | O(1) |
| `front()` | Accesses the first element. | O(1) |
| `back()` | Accesses the last element. | O(1) |
| `begin()`, `end()` | Returns iterators to the beginning and end. | O(1) |
| `insert(pos, val)` | Inserts element `val` at iterator `pos`. | O(N) |
| `erase(pos)` | Erases element at iterator `pos`. | O(N) |
| `sort(v.begin(), v.end())` | Sorts the vector (requires `<algorithm>`). | O(N log N) |

-----

### `std::list` ⛓️

**Header:** `#include <list>`

**Description:** A **doubly-linked list**. Allows for constant time insertion and deletion anywhere, but does not support random access (`[]`).

**Best Use Cases:**

  * Frequent insertions and deletions in the **middle** of the sequence.
  * When you don't need random access to elements.
  * When you need iterators to remain valid after insertions/deletions elsewhere.

#### Syntax & Initialization

```cpp
std::list<int> l1;
std::list<int> l2 = {10, 20, 30};
```

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push_back(val)` | Adds an element to the end. | O(1) |
| `pop_back()` | Removes the last element. | O(1) |
| `push_front(val)` | Adds an element to the front. | O(1) |
| `pop_front()` | Removes the first element. | O(1) |
| `insert(pos, val)` | Inserts `val` before iterator `pos`. | O(1) |
| `erase(pos)` | Erases element at iterator `pos`. | O(1) |
| `size()`, `empty()`, `front()`, `back()` | Same as `vector`. | O(1) |
| `reverse()` | Reverses the list. | O(N) |
| `sort()` | Sorts the list. | O(N log N) |
| `merge(other_list)` | Merges another sorted list into this one. | O(N) |

-----

### `std::deque`

**Header:** `#include <deque>`

**Description:** "Double-ended queue". A sequence container that allows for efficient insertion and deletion at **both the beginning and the end**.

**Best Use Cases:**

  * When you need fast insertions and deletions at both the front and back.
  * Implementing a queue or a sliding window algorithm.
  * When random access is needed, but performance is less critical than for `vector`.

#### Syntax & Initialization

```cpp
std::deque<int> dq = {10, 20, 30};
```

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push_back(val)` | Adds element to the end. | Amortized O(1) |
| `pop_back()` | Removes last element. | O(1) |
| `push_front(val)` | Adds element to the front. | Amortized O(1) |
| `pop_front()` | Removes first element. | O(1) |
| `dq[i]`, `at(i)` | Random access (slower than vector). | O(1) |
| `size()`, `empty()`, `front()`, `back()` | Same as `vector`. | O(1) |

-----

## 2\. Container Adaptors

### `std::stack` (LIFO) 🥞

**Header:** `#include <stack>`

**Description:** **Last-In, First-Out (LIFO)** data structure. It is an adaptor that provides a stack interface over an underlying container (default is `std::deque`).

**Best Use Cases:**

  * Reversing a sequence.
  * Parsing expressions (e.g., checking for balanced parentheses).
  * Simulating recursion or managing function calls.
  * Depth-First Search (DFS) in graphs (iterative approach).
  * Undo/redo functionality.

#### Syntax & Initialization

```cpp
// Default (uses std::deque<int>)
std::stack<int> s;

// Using std::vector<int> as the underlying container
std::stack<int, std::vector<int>> s_vec;
```

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push(val)` | Inserts an element at the top. | O(1) |
| `pop()` | Removes the top element. | O(1) |
| `top()` | Accesses the top element. | O(1) |
| `size()` | Returns the number of elements. | O(1) |
| `empty()` | Returns true if the stack is empty. | O(1) |

-----

### `std::queue` (FIFO)

**Header:** `#include <queue>`

**Description:** **First-In, First-Out (FIFO)** data structure. Like `stack`, it's an adaptor (default container is `std::deque`).

**Best Use Cases:**

  * Breadth-First Search (BFS) in graphs.
  * Handling tasks in the order they are received (e.g., print jobs, server requests).
  * Simulating any process where resources are shared among multiple consumers in order.

#### Syntax & Initialization

```cpp
std::queue<int> q;
```

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push(val)` | Inserts an element at the back. | O(1) |
| `pop()` | Removes the front element. | O(1) |
| `front()` | Accesses the front element. | O(1) |
| `back()` | Accesses the back element. | O(1) |
| `size()`, `empty()` | Same as `stack`. | O(1) |

-----

### `std::priority_queue`

**Header:** `#include <queue>`

**Description:** A queue where elements are popped based on priority. By default, it's a **Max-Heap** (the largest element has the highest priority).

**Best Use Cases:**

  * When you always need to access the largest (or smallest) element quickly.
  * Dijkstra's algorithm (for shortest paths) and Prim's algorithm (for minimum spanning trees).
  * A\* search algorithm.
  * Huffman coding (for data compression).
  * Processing items based on priority rather than arrival time.

#### Syntax & Initialization

```cpp
// Max-Heap (default)
std::priority_queue<int> pq_max;

// Min-Heap
std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;
```

#### Important Functions

| Function | Description | Time Complexity |
|---|---|---|
| `push(val)` | Inserts an element. | O(log N) |
| `pop()` | Removes the top priority element. | O(log N) |
| `top()` | Accesses the top priority element. | O(1) |
| `size()`, `empty()` | Same as `stack`. | O(1) |

-----

## 3\. Associative Containers (Ordered)

**Underlying Implementation:** Self-Balancing Binary Search Tree (typically a Red-Black Tree).
**Key Property:** Elements are always **sorted**.

### `std::set`

**Header:** `#include <set>`
**Description:** Stores a collection of **unique**, sorted elements.
**Best Use Cases:** Maintaining a collection of unique items in sorted order, quickly checking for presence, and finding elements in a range.

#### Syntax & Initialization

```cpp
std::set<int> s = {10, 50, 20, 10}; // s will contain {10, 20, 50}
```

### `std::multiset`

**Header:** `#include <set>`
**Description:** Stores a collection of sorted elements, **allowing duplicates**.
**Best Use Cases:** Storing elements in sorted order while allowing duplicates.

#### Syntax & Initialization

```cpp
std::multiset<int> ms = {10, 50, 20, 10}; // ms will contain {10, 10, 20, 50}
```

#### Important Functions for `set` and `multiset`

| Function | Description | Time Complexity |
|---|---|---|
| `insert(val)` | Inserts an element. | O(log N) |
| `erase(val)` | Removes occurrences of `val`. | O(log N) |
| `find(val)` | Returns an iterator to `val`, or `.end()`. | O(log N) |
| `count(val)` | Returns the number of occurrences of `val`. | O(log N + count) |
| `lower_bound(val)` | Iterator to the first element \>= `val`. | O(log N) |
| `upper_bound(val)` | Iterator to the first element \> `val`. | O(log N) |
| `size()`, `empty()` | Common functions. | O(1) |

-----

### `std::map` 🗺️

**Header:** `#include <map>`
**Description:** Stores key-value pairs with **unique, sorted keys**.
**Best Use Cases:** A dictionary where pairs need to be sorted by key, or frequency counters where element order matters.

#### Syntax & Initialization

```cpp
std::map<std::string, int> m;
m["apple"] = 1;
m["banana"] = 2;
m.insert({"cherry", 3});
```

### `std::multimap`

**Header:** `#include <map>`
**Description:** Stores key-value pairs with sorted keys, **allowing duplicate keys**.
**Best Use Cases:** Any dictionary-like scenario where a key can have multiple values, like grouping items.

#### Syntax & Initialization

```cpp
std::multimap<char, int> mm;
mm.insert({'a', 1});
mm.insert({'a', 2}); // Allowed
```

#### Important Functions for `map` and `multimap`

| Function | Description | Time Complexity |
|---|---|---|
| `m[key] = val` | Access or insert (`map` only). | O(log N) |
| `insert({key, val})` | Inserts a key-value pair. | O(log N) |
| `erase(key)` | Removes all pairs with the given key. | O(log N) |
| `find(key)` | Returns an iterator to a pair with the key. | O(log N) |
| `count(key)` | Returns the number of pairs with the key. | O(log N + count) |
| `lower_bound(key)` | Iterator to first element with key \>= `key`. | O(log N) |
| `upper_bound(key)` | Iterator to first element with key \> `key`. | O(log N) |

-----

## 4\. Unordered Associative Containers (Hashed)

**Underlying Implementation:** Hash Table.
**Key Property:** Average case **O(1)** for search, insert, delete. No guaranteed order.

### `std::unordered_set`

**Header:** `#include <unordered_set>`
**Description:** Stores **unique** elements in no particular order.
**Best Use Cases:** The fastest way to store and check for unique items when order doesn't matter.

#### Syntax & Initialization

```cpp
std::unordered_set<int> us = {10, 50, 20, 10}; // us contains {10, 20, 50} in some order
```

### `std::unordered_map`

**Header:** `#include <unordered_map>`
**Description:** Stores key-value pairs with **unique** keys in no particular order.
**Best Use Cases:** The default choice for hashmaps/dictionaries. Fastest for frequency counters, caching, or memoization.

#### Syntax & Initialization

```cpp
std::unordered_map<std::string, int> um;
um["apple"] = 1;
um["banana"] = 2;
```

#### Important Functions for Unordered Containers

| Function | Description | Time Complexity |
|---|---|---|
| `insert(val)` | Inserts an element/pair. | Avg: O(1), Worst: O(N) |
| `erase(val)` | Removes elements/pairs with the given key. | Avg: O(1), Worst: O(N) |
| `find(val)` | Returns an iterator to the element. | Avg: O(1), Worst: O(N) |
| `count(val)` | Returns the number of occurrences. | Avg: O(1), Worst: O(N) |
| `um[key]` | Access or insert (`unordered_map` only). | Avg: O(1), Worst: O(N) |
| `size()`, `empty()` | Common functions. | O(1) |

**Note:** `unordered_multiset` and `unordered_multimap` also exist and behave like their ordered counterparts but with hashing and average O(1) complexity.

-----

## 5\. Utility

### `std::string`

**Header:** `#include <string>`
**Description:** A sequence of characters used for storing and manipulating text.

| Function | Description |
|---|---|
| `length()`, `size()` | Returns the number of characters. |
| `+`, `+=` | Concatenates strings. |
| `substr(pos, len)` | Returns a new string that is a substring. |
| `find(str)` | Finds the first occurrence of a substring. |
| `s[i]` | Accesses the character at index i. |
| `push_back(char)` | Appends a character. |
| `pop_back()` | Removes the last character. |

### `std::pair`

**Header:** `#include <utility>`
**Description:** A simple container that holds exactly two elements, which can be of different types.
**Access:** `p.first`, `p.second`
**Best Use Cases:** Returning two values from a function; storing items that naturally come in pairs like coordinates (x, y).

#### Syntax & Initialization

```cpp
std::pair<int, std::string> p1 = {1, "hello"};
std::pair<int, int> p2 = std::make_pair(10, 20);
```

### `std::tuple`

**Header:** `#include <tuple>`
**Description:** A fixed-size collection of heterogeneous values.
**Access:** `std::get<index>(t)`
**Best Use Cases:** Returning more than two values from a function; storing a heterogeneous record without creating a custom struct.

#### Syntax & Initialization

```cpp
std::tuple<int, char, double> t1 = {10, 'a', 3.14};

// Accessing elements
int i = std::get<0>(t1); // i = 10
char c = std::get<1>(t1); // c = 'a'
```

-----

*Crafted with ❤️ by Priyanshu Arya (The Tech Intel)*

### 📌 Connect with Me:

[LinkedIn](https://www.google.com/search?q=https://www.linkedin.com/in/priyanshu-arya-554b91173/) | [Medium](https://www.google.com/search?q=https://medium.com/%40thetechintel) | [Instagram](https://www.google.com/search?q=https://www.instagram.com/the.tech.intel/) | [YouTube](https://www.google.com/search?q=https://www.youtube.com/%40TheTechIntel)

### 🎯 Schedule a Visual Connect (Free):

[Book a Time Slot on Topmate](https://www.google.com/search?q=https://topmate.io/the_tech_intel)

### 📧 For queries, collaborations, or corrections:

Reach me at [priyanshuthetechintel@gmail.com](mailto:priyanshuthetechintel@gmail.com)

```
```