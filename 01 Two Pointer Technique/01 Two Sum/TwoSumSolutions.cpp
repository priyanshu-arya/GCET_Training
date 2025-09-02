// 1. Brute Force (O(n²))
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumBF(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // No solution (though problem guarantees one)
}


// 2. Using Hash Map (O(n))
vector<int> twoSumHM(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_index; // Maps number to its index
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int diff = target - num;
        if (num_to_index.find(diff) != num_to_index.end()) {
            return {num_to_index[diff], i};
        }
        num_to_index[num] = i;
    }
    return {}; // No solution (though problem guarantees one)
}

// 3. Two Pointers (O(n log n))
vector<int> twoSumTP(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> num_with_index; // Pair of (number, original index)
    for (int i = 0; i < n; i++) {
        num_with_index.push_back({nums[i], i});
    }
    sort(num_with_index.begin(), num_with_index.end()); // Sort based on numbers

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = num_with_index[left].first + num_with_index[right].first;
        if (sum == target) {
            return {num_with_index[left].second, num_with_index[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; // No solution (though problem guarantees one)
}

// 4. Binary Search (O(n log n))  
vector<int> twoSumBS(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> num_with_index; // Pair of (number, original index)
    for (int i = 0; i < n; i++) {
        num_with_index.push_back({nums[i], i});
    }
    sort(num_with_index.begin(), num_with_index.end()); // Sort based on numbers

    for (int i = 0; i < n; i++) {
        int complement = target - num_with_index[i].first;
        int left = i + 1, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (num_with_index[mid].first == complement) {
                return {num_with_index[i].second, num_with_index[mid].second};
            } else if (num_with_index[mid].first < complement) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return {}; // No solution (though problem guarantees one)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> resultBF = twoSumBF(nums, target);
    cout << "Brute Force: [" << resultBF[0] << ", " << resultBF[1] << "]\n";

    vector<int> resultHM = twoSumHM(nums, target);
    cout << "Hash Map: [" << resultHM[0] << ", " << resultHM[1] << "]\n";

    vector<int> resultTP = twoSumTP(nums, target);
    cout << "Two Pointers: [" << resultTP[0] << ", " << resultTP[1] << "]\n";

    vector<int> resultBS = twoSumBS(nums, target);
    cout << "Binary Search: [" << resultBS[0] << ", " << resultBS[1] << "]\n";

    return 0;
} 