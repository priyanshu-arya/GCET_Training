# Java Data Structures & Algorithms (DSA) Cheat Sheet
## A Comprehensive Guide to Java Collections for DSA ☕️

An essential reference for students of Data Structures & Algorithms and competitive programmers covering the most common classes in the Java Collections Framework, their use cases, and time complexities.

---

## Table of Contents

1.  **Lists (Sequence Containers)**
    * `ArrayList`
    * `LinkedList`
2.  **Deques, Stacks, & Queues**
    * `ArrayDeque` (used for Stack and Queue)
    * `PriorityQueue`
3.  **Sets (Associative Containers)**
    * `HashSet` (Hashed)
    * `TreeSet` (Ordered)
4.  **Maps (Associative Containers)**
    * `HashMap` (Hashed)
    * `TreeMap` (Ordered)
5.  **Code Examples**

---

## 1. Lists (Sequence Containers)

### `ArrayList`

**Package:** `import java.util.ArrayList;`

**Description:** A resizable array implementation of the `List` interface. Elements are stored contiguously.

**Best Use Cases:**
* The **default choice** for a list. Use when in doubt.
* Fast random access by index (`get(i)`).
* Frequent additions/removals at the **end** of the list.

#### Syntax & Initialization
```java
// Empty ArrayList
List<Integer> list1 = new ArrayList<>();

// ArrayList with initial capacity
List<Integer> list2 = new ArrayList<>(20);

// From another collection
List<Integer> list3 = new ArrayList<>(Arrays.asList(1, 2, 3));
````

#### Important Methods

| Method | Description | Time Complexity |
|---|---|---|
| `add(val)` | Appends an element to the end. | Amortized O(1) |
| `add(index, val)` | Inserts an element at a specific index. | O(N) |
| `remove(index)` | Removes the element at an index. | O(N) |
| `get(index)` | Accesses the element at an index. | O(1) |
| `set(index, val)` | Replaces the element at an index. | O(1) |
| `size()` | Returns the number of elements. | O(1) |
| `isEmpty()` | Returns true if the list is empty. | O(1) |
| `clear()` | Removes all elements. | O(N) |
| `contains(val)` | Checks if the list contains a value. | O(N) |
| `Collections.sort(list)` | Sorts the list (requires `java.util.Collections`).| O(N log N) |

-----

### `LinkedList`

**Package:** `import java.util.LinkedList;`

**Description:** A doubly-linked list implementation of the `List` and `Deque` interfaces.

**Best Use Cases:**

  * Frequent insertions and deletions, especially in the **middle** of the list.
  * When you need an efficient queue (FIFO) or stack (LIFO) structure.

#### Syntax & Initialization

```java
List<String> list1 = new LinkedList<>();
LinkedList<String> list2 = new LinkedList<>(Arrays.asList("a", "b"));
```

#### Important Methods

| Method | Description | Time Complexity |
|---|---|---|
| `add(val)` | Appends to the end. | O(1) |
| `addFirst(val)` | Adds to the front. | O(1) |
| `addLast(val)` | Adds to the end. | O(1) |
| `removeFirst()` | Removes from the front. | O(1) |
| `removeLast()` | Removes from the end. | O(1) |
| `getFirst()`, `getLast()`| Access first/last elements. | O(1) |
| `get(index)` | Access by index (slow). | O(N) |
| `size()`, `isEmpty()` | Common methods. | O(1) |

-----

## 2\. Deques, Stacks, & Queues 🥞

### `ArrayDeque` (for Stack & Queue)

**Package:** `import java.util.ArrayDeque;`

**Description:** A resizable array implementation of the `Deque` (double-ended queue) interface. The modern and **preferred choice** for both stack (LIFO) and queue (FIFO) behavior.

**Best Use Cases:**

  * **Stack (LIFO):** Use `push()` and `pop()`. Perfect for DFS, parsing, etc.
  * **Queue (FIFO):** Use `add()` and `poll()`. Perfect for BFS.

#### Syntax & Initialization

```java
// As a Stack (LIFO)
Deque<Integer> stack = new ArrayDeque<>();

// As a Queue (FIFO)
Queue<Integer> queue = new ArrayDeque<>();
```

#### Important Methods

| Stack (LIFO) Method | Queue (FIFO) Method | Description | Time Complexity |
|---|---|---|---|
| `push(val)` | `add(val)` / `offer(val)` | Adds an element. | Amortized O(1) |
| `pop()` | `poll()` | Removes and returns an element. | O(1) |
| `peek()` | `peek()` | Views the next element without removing. | O(1) |
| `isEmpty()`, `size()` | `isEmpty()`, `size()` | Common methods. | O(1) |

-----

### `PriorityQueue`

**Package:** `import java.util.PriorityQueue;`

**Description:** A queue that orders elements based on their natural ordering or a custom `Comparator`. By default, it is a **Min-Heap**.

**Best Use Cases:**

  * When you always need to access the smallest (or largest) element.
  * Dijkstra's, Prim's, A\* search algorithms.
  * Finding the 'Kth' largest/smallest element.

#### Syntax & Initialization

```java
// Min-Heap (default)
Queue<Integer> pqMin = new PriorityQueue<>();

// Max-Heap
Queue<Integer> pqMax = new PriorityQueue<>(Collections.reverseOrder());
```

#### Important Methods

| Method | Description | Time Complexity |
|---|---|---|
| `add(val)` / `offer(val)` | Inserts an element. | O(log N) |
| `remove()` / `poll()` | Removes the top priority element. | O(log N) |
| `peek()` | Accesses the top priority element. | O(1) |
| `size()`, `isEmpty()` | Common methods. | O(1) |

-----

## 3\. Sets (Associative Containers)

### `HashSet` (Hashed)

**Package:** `import java.util.HashSet;`

**Description:** Stores a collection of **unique** elements using a hash table. Order is not guaranteed.

**Best Use Cases:**

  * The **fastest way** to store and check for the existence of unique items.
  * Removing duplicates from a collection.

#### Syntax & Initialization

```java
Set<String> set = new HashSet<>();
set.add("apple");
set.add("banana");
set.add("apple"); // Ignored
```

-----

### `TreeSet` (Ordered)

**Package:** `import java.util.TreeSet;`

**Description:** Stores a collection of **unique, sorted** elements using a Red-Black Tree.

**Best Use Cases:**

  * Maintaining unique items in sorted order.
  * Finding elements in a specific range (`subSet`, `headSet`, etc.).

#### Syntax & Initialization

```java
Set<Integer> set = new TreeSet<>();
set.add(50);
set.add(20); // Set is now {20, 50}
```

#### Important Methods for `HashSet` and `TreeSet`

| Method | Description | `HashSet` Complexity | `TreeSet` Complexity |
|---|---|---|---|
| `add(val)` | Adds an element. | Avg: O(1) | O(log N) |
| `remove(val)` | Removes an element. | Avg: O(1) | O(log N) |
| `contains(val)` | Checks for an element. | Avg: O(1) | O(log N) |
| `size()`, `isEmpty()`| Common methods. | O(1) | O(1) |
| `first()`, `last()` | (TreeSet only) Get min/max element.| N/A | O(log N) |

-----

## 4\. Maps (Associative Containers) 🗺️

### `HashMap` (Hashed)

**Package:** `import java.util.HashMap;`

**Description:** Stores key-value pairs using a hash table. Order is not guaranteed.

**Best Use Cases:**

  * The **default choice** for a map/dictionary.
  * Fastest for frequency counters, caching, and lookups.

#### Syntax & Initialization

```java
Map<String, Integer> map = new HashMap<>();
map.put("apple", 10);
map.put("banana", 20);
```

-----

### `TreeMap` (Ordered)

**Package:** `import java.util.TreeMap;`

**Description:** Stores key-value pairs sorted by key, using a Red-Black Tree.

**Best Use Cases:**

  * When you need to iterate through key-value pairs in sorted key order.
  * When you need to find keys within a certain range.

#### Syntax & Initialization

```java
Map<String, Integer> map = new TreeMap<>();
map.put("banana", 20);
map.put("apple", 10); // Map now stores ("apple", 10), ("banana", 20)
```

#### Important Methods for `HashMap` and `TreeMap`

| Method | Description | `HashMap` Complexity | `TreeMap` Complexity |
|---|---|---|---|
| `put(key, val)` | Inserts/updates a key-value pair. | Avg: O(1) | O(log N) |
| `get(key)` | Retrieves a value by its key. | Avg: O(1) | O(log N) |
| `remove(key)` | Removes a pair by its key. | Avg: O(1) | O(log N) |
| `containsKey(key)`| Checks if a key exists. | Avg: O(1) | O(log N) |
| `getOrDefault(k, def)`| Gets value or a default if not found. | Avg: O(1) | O(log N) |
| `keySet()`, `values()`| Get a collection of keys or values. | O(1) | O(1) |
| `size()`, `isEmpty()`| Common methods. | O(1) | O(1) |

-----

## 5\. Code Examples

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("--- ArrayList Example ---");
        List<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Orange");
        System.out.println("ArrayList: " + fruits);
        System.out.println("Element at index 1: " + fruits.get(1));

        System.out.println("\n--- Stack (ArrayDeque) Example ---");
        Deque<String> stack = new ArrayDeque<>();
        stack.push("First");
        stack.push("Second");
        System.out.println("Top of stack: " + stack.peek());
        stack.pop();
        System.out.println("Stack after pop: " + stack);

        System.out.println("\n--- Queue (ArrayDeque) Example ---");
        Queue<String> queue = new ArrayDeque<>();
        queue.add("Job 1");
        queue.add("Job 2");
        System.out.println("Front of queue: " + queue.peek());
        queue.poll();
        System.out.println("Queue after poll: " + queue);

        System.out.println("\n--- PriorityQueue (Min-Heap) Example ---");
        Queue<Integer> pq = new PriorityQueue<>();
        pq.add(50);
        pq.add(20);
        pq.add(100);
        System.out.println("Top of min-heap: " + pq.peek()); // 20
        pq.poll();
        System.out.println("Top after poll: " + pq.peek()); // 50

        System.out.println("\n--- HashSet Example ---");
        Set<String> uniqueFruits = new HashSet<>();
        uniqueFruits.add("Apple");
        uniqueFruits.add("Orange");
        uniqueFruits.add("Apple"); // Ignored
        System.out.println("HashSet: " + uniqueFruits);

        System.out.println("\n--- HashMap Example ---");
        Map<String, Integer> fruitPrices = new HashMap<>();
        fruitPrices.put("Apple", 10);
        fruitPrices.put("Orange", 15);
        System.out.println("Price of Apple: " + fruitPrices.get("Apple"));
        System.out.println("HashMap: " + fruitPrices);
    }
}
```

-----

*Crafted with ❤️ by Priyanshu Arya (The Tech Intel)*

### 📌 Connect with Me:

[LinkedIn](https://www.google.com/search?q=https://www.linkedin.com/in/priyanshu-arya-554b91173/) | [Medium](https://www.google.com/search?q=https://medium.com/%40thetechintel) | [Instagram](https://www.google.com/search?q=https://www.instagram.com/the.tech.intel/) | [YouTube](https://www.google.com/search?q=https://www.youtube.com/%40TheTechIntel)

### 🎯 Schedule a Visual Connect (Free):

[Book a Time Slot on Topmate](https://www.google.com/search?q=https://topmate.io/the_tech_intel)

### 📧 For queries, collaborations, or corrections:

Reach me at [priyanshuthetechintel@gmail.com](mailto:priyanshuthetechintel@gmail.com)

