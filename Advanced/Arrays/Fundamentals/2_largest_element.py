# Largest Element
# TC = O(n)
# SC = O(1)
def largest_element(nums):
    if not nums:
        return None
    largest = nums[0]
    for num in nums:
        if num > largest:
            largest = num
    return largest


nums = [3, 1, 4, 1, 5, 9, 2, 6, 5]
result = largest_element(nums)
print(result)
