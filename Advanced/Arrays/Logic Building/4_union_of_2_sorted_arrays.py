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


# Optimal Approach 1 (Classic Two Pointer Technique)
# TC = O(n+m)
# SC = O(n+m)
def unionArrayOptimal1(nums1, nums2):
    n = len(nums1)
    m = len(nums2)
    i, j = 0, 0
    union = []

    while i < n and j < m:
        if nums1[i] <= nums2[j]:

            if not union or union[-1] != nums1[i]:
                union.append(nums1[i])

            if nums1[i] == nums2[j]:
                j += 1
            i += 1
        else:  # nums1[i] > nums2[j]
            if not union or union[-1] != nums2[j]:
                union.append(nums2[j])
            j += 1

    while i < n:
        if not union or union[-1] != nums1[i]:
            union.append(nums1[i])
        i += 1

    while j < m:
        if not union or union[-1] != nums2[j]:
            union.append(nums2[j])
        j += 1

    return union


# Optimal Approach 2 (Single Loop with Sentinels)
# TC = O(n+m)
# SC = O(n+m)
def unionArrayOptimal2(nums1, nums2):
    n, m = len(nums1), len(nums2)
    i, j = 0, 0
    union = []

    # Single loop continues as long as at least one array has elements
    while i < n or j < m:
        # Use float("inf") as a sentinel when an array is exhausted.
        # This avoids an IndexError and simplifies the main comparison logic.
        val1 = nums1[i] if i < n else float("inf")
        val2 = nums2[j] if j < m else float("inf")
        candidate = 0

        if val1 < val2:
            candidate = val1
            i += 1
        elif val2 < val1:
            candidate = val2
            j += 1
        else:
            candidate = val1
            i += 1
            j += 1

        # The check for infinity is necessary to stop at the end
        if candidate != float("inf"):
            if not union or union[-1] != candidate:
                union.append(candidate)

    return union
