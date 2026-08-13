
def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        for j in range(i, n):
            left = 2 * j + 1
            right = 2 * j + 2

            if left < n and arr[left] > arr[j]:
                arr[j], arr[left] = arr[left], arr[j]

            if right < n and arr[right] > arr[j]:
                arr[j], arr[right] = arr[right], arr[j]

    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]

arr = [5, 3, 8, 4, 2]

heap_sort(arr)

print(arr)
