# 1. Brute Force (O(n²))
def twoSumBF(nums, target):
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []  # No solution (though problem guarantees one)


# 2. Using Hash Map (O(n))
def twoSumHM(nums, target):
    num_to_index = {}  # Maps number to its index
    for i, num in enumerate(nums):
        diff = target - num
        if diff in num_to_index:
            return [num_to_index[diff], i]
        num_to_index[num] = i
    return []  # No solution (though problem guarantees one)


# 3. Two Pointers (O(n log n))
def twoSumTP(nums, target):
    n = len(nums)
    num_with_index = [(num, i) for i, num in enumerate(nums)]
    num_with_index.sort()  # Sort based on numbers

    left, right = 0, n - 1
    while left < right:
        s = num_with_index[left][0] + num_with_index[right][0]
        if s == target:
            return [num_with_index[left][1], num_with_index[right][1]]
        elif s < target:
            left += 1
        else:
            right -= 1
    return []  # No solution (though problem guarantees one)


# 4. Binary Search (O(n log n))
def twoSumBS(nums, target):
    n = len(nums)
    num_with_index = [(num, i) for i, num in enumerate(nums)]
    num_with_index.sort()  # Sort based on numbers

    for i in range(n):
        complement = target - num_with_index[i][0]
        left, right = i + 1, n - 1
        while left <= right:
            mid = (left + right) // 2
            if num_with_index[mid][0] == complement:
                return [num_with_index[i][1], num_with_index[mid][1]]
            elif num_with_index[mid][0] < complement:
                left = mid + 1
            else:
                right = mid - 1
    return []  # No solution (though problem guarantees one)


# Example usage:
if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9

    resultBF = twoSumBF(nums, target)
    print(f"Brute Force: {resultBF}")

    resultHM = twoSumHM(nums, target)
    print(f"Hash Map: {resultHM}")

    resultTP = twoSumTP(nums, target)
    print(f"Two Pointers: {resultTP}")

    resultBS = twoSumBS(nums, target)
    print(f"Binary Search: {resultBS}")
