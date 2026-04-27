arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

def two_sum(arr, target):
    seen = {}
    for i, num in enumerate(arr):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []

target = int(input("Enter the target sum: "))
result = two_sum(arr, target)
if result:
    print(f"Indices of two numbers that sum to {target}: {result}")
    print(f"The numbers are: {arr[result[0]]} and {arr[result[1]]}")
else:
    print("No two numbers sum to the target.")
