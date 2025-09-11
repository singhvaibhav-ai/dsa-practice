# Left Rotate Array by One
# TC = O(n)
# SC = O(1)


def rotateArrayByOne(nums):
    temp = nums[0]
    for i in range(1, len(nums)):
        nums[i - 1] = nums[i]
    nums[-1] = temp


nums = [1, 2, 3, 4, 5]
rotateArrayByOne(nums)
print(nums)
