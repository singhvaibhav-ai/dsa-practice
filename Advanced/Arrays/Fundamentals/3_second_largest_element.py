def second_largest(nums):
    if len(nums) < 2:
        return None  # Not enough elements for second largest

    first = second = float("-inf")

    for num in nums:
        if num > first:
            second = first
            first = num
        elif first > num > second:
            second = num

    return second if second != float("-inf") else None


nums = [3, 1, 4, 1, 5, 9, 2, 6, 5]
result = second_largest(nums)
print(result)
