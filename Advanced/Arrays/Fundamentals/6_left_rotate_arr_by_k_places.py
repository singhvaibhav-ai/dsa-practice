# Left Rotate Array by K places


# Brute Force Approach
# TC = O(n+k)
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
# TC = O(n)
# SC = O(1)
def rotateArrayOptimal(nums, k):
    n = len(nums)
    a = k % n
    reverse(nums, 0, a - 1)
    reverse(nums, a, n - 1)
    reverse(nums, 0, n - 1)


def reverse(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1


nums = [1, 2, 3, 4, 5]
k = 2
rotateArrayBrute(nums, k)
print(nums)
