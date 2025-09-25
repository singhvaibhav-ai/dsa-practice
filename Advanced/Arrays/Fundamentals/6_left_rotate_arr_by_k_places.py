# Left Rotate Array by K places


# Brute Force Approach
# TC = O(n)
# SC = O(k)
def rotateArrayBrute(nums, k):
    n = len(nums)
    a = k % n
    temp = []
    for i in range(a):
        temp.append(nums[i])
    for i in range(a, len(nums)):
        nums[i - a] = nums[i]
    for i in range(a):
        nums[n - a + i] = temp[i]


# Optimal Approach


nums = [1, 2, 3, 4, 5]
k = 2
rotateArrayBrute(nums, k)
print(nums)
