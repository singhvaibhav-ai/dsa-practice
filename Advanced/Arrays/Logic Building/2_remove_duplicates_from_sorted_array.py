# Remove duplicates from sorted array


# Brute Force Approach
# TC = O(n log n)
# SC = O(n)
def remove_duplicates_brute(arr):
    n = len(arr)
    set_data = set()
    for i in range(n):
        set_data.add(arr[i])
    arr[:] = list(set_data)
    arr.sort()
    return len(arr)


# Optimal Approach
# TC = O(n)
# SC = O(1)
def remove_duplicates_optimal(arr):
    n = len(arr)
    if n == 0:
        return 0
    i = 0
    for j in range(1, n):
        if arr[j] != arr[i]:
            i += 1
            arr[i] = arr[j]
    return i + 1
