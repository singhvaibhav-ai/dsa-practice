# Find Missing Number


# Brute Force Approach
# TC = O(n^2) (will never happen as the loop will brealk early in most cases)
# SC = O(1)
def missingNumberBrute(nums):
    N = len(nums)
    for i in range(0, N + 1):
        flag = 0
        for num in nums:
            if num == i:
                flag = 1
                break
        if flag == 0:
            return i
    return -1


# Better Approach using Sorting
# TC = O(n log n)
# SC = O(1)
def missingNumberBetter2(nums):
    n = len(nums)
    nums.sort()
    for i in range(n):
        if nums[i] != i:
            return i
    return n


# Better Approach using Hashing
# TC = O(n)
# SC = O(n)
def missingNumberBetter1(nums):
    n = len(nums)
    freq = [0] * (n + 1)
    for num in nums:
        freq[num] += 1
    for i in range(n + 1):
        if freq[i] == 0:
            return i
    return -1


# Optimal Approach using Sum
# TC = O(n)
# SC = O(1)
def missingNumberOptimal(nums):
    n = len(nums)
    total = n * (n + 1) // 2
    sum_of_nums = sum(nums)
    return total - sum_of_nums


# Optimal Approach using XOR
# TC = O(n)
# SC = O(1)
def missingNumberXOR(nums):
    n = len(nums)
    xor1 = 0
    xor2 = 0
    for i in range(n):
        xor1 ^= nums[i]
        xor2 ^= i + 1
    return xor1 ^ xor2
