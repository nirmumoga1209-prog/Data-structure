# Program to find sum using reduce()

from functools import reduce

numbers = [1, 2, 3, 4, 5]

sum_result = reduce(lambda x, y: x + y, numbers)

print("List Elements:", numbers)
print("Sum of Elements:", sum_result)
