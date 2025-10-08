#include <bits/stdc++.h>
using namespace std;

// --- Brute Force Approach ---
// TC = O(n^2) (usually breaks early)
// SC = O(1)
int missingNumberBrute(const vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i <= N; i++) {
        bool found = false;
        for (int num : nums) {
            if (num == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
    return -1;
}

// --- Better Approach using Hashing ---
// TC = O(n)
// SC = O(n)
int missingNumberBetterHash(const vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0);

    for (int num : nums) {
        freq[num]++;
    }

    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0)
            return i;
    }
    return -1;
}

// --- Better Approach using Sorting ---
// TC = O(n log n)
// SC = O(1)
int missingNumberBetterSort(vector<int> nums) {  // pass by value to allow sorting
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (nums[i] != i)
            return i;
    }
    return n;
}

// --- Optimal Approach using Sum ---
// TC = O(n)
// SC = O(1)
int missingNumberOptimalSum(const vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;

    for (int num : nums)
        sum += num;

    return total - sum;
}

// --- Optimal Approach using XOR ---
// TC = O(n)
// SC = O(1)
int missingNumberOptimalXOR(const vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor1 ^= nums[i];
        xor2 ^= (i + 1);
    }

    return xor1 ^ xor2;
}

// --- Helper to Print ---
void testMissingNumber(const vector<int>& nums) {
    cout << "Brute Force: " << missingNumberBrute(nums) << endl;
    cout << "Better (Hashing): " << missingNumberBetterHash(nums) << endl;
    cout << "Better (Sorting): " << missingNumberBetterSort(nums) << endl;
    cout << "Optimal (Sum): " << missingNumberOptimalSum(nums) << endl;
    cout << "Optimal (XOR): " << missingNumberOptimalXOR(nums) << endl;
}

// --- Main Function ---
int main() {
    vector<int> nums = {3, 0, 1}; // Missing number is 2

    cout << "Original Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    testMissingNumber(nums);

    return 0;
}
