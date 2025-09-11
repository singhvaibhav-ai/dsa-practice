# Linear Search
# TC = O(n)
# SC = O(1)
def linearSearch(nums, target):
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1


nums = [1, 2, 3, 4, 5]
target = 4
result = linearSearch(nums, target)
print(result)
