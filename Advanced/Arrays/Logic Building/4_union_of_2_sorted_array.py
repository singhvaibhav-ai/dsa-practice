# Union of 2 sorted array


# Brute Force Approach 1
# TC = O(n)+O(m)+O((n+m)log(n+m))
# SC = O(n+m)
def unionArrayBrute1(nums1, nums2):
    s = set()
    for num in nums1:
        s.add(num)
    for num in nums2:
        s.add(num)
    union = list(sorted(s))
    return union


# Brute Force Approach 2
# TC = O(n) + O(m) + O((n+m)log(n+m))
# SC = O(n+m)
def unionArrayBrute2(nums1, nums2):
    return sorted(list(set(nums1) | set(nums2)))


# Optimal Approach
# TC = O(n+m)
# SC = O(n+m)
def unionArrayOptimal(nums1, nums2):
    n = len(nums1)
    m = len(nums2)
    i, j = 0, 0
    union = []
    while i < n and j < m:
        if nums1[i] < nums2[j]:
            if len(union) == 0 or union[-1] != nums1[i]:
                union.append(nums1[i])
            i += 1
        elif nums1[i] > nums2[j]:
            if len(union) == 0 or union[-1] != nums2[j]:
                union.append(nums2[j])
            j += 1
        else:
            if len(union) == 0 or union[-1] != nums1[i]:
                union.append(nums1[i])
            i += 1
            j += 1
    while i < n:
        if len(union) == 0 or union[-1] != nums1[i]:
            union.append(nums1[i])
        i += 1
    while j < m:
        if len(union) == 0 or union[-1] != nums2[j]:
            union.append(nums2[j])
        j += 1
    return union
