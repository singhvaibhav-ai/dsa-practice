# Move Zeros to End
# Brute Force Approach
# TC = O(n)
# SC = O(n)
def move_zeroes_to_end_brute(arr):
    n = len(arr)
    temp = []
    for i in range(n):
        if arr[i] != 0:
            temp.append(arr[i])
    for i in range(len(temp)):
        arr[i] = temp[i]
    for i in range(len(temp), n):
        arr[i] = 0


# Optimal Approach
# TC = O(n)
# SC = O(1)


# Version 1 (simpler, may self-swap)
def move_zeroes_to_end_optimal_v1(arr):
    n = len(arr)
    j = 0
    for i in range(n):
        if arr[i] != 0:
            arr[i], arr[j] = arr[j], arr[i]
            j += 1


# Version 2 (first-zero search, avoids self-swaps)
def move_zeroes_to_end_optimal_v2(arr):
    n = len(arr)
    j = -1
    for i in range(n):
        if arr[i] == 0:
            j = i
            break
    if j == -1:
        return
    for i in range(j + 1, n):
        if arr[i] != 0:
            arr[i], arr[j] = arr[j], arr[i]
            j += 1
