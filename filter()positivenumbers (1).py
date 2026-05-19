# Program to filter positive numbers

numbers = [-10, 20, -30, 40, 50, -60]

positive_numbers = list(filter(lambda x: x > 0, numbers))

print("Original List:", numbers)
print("Positive Numbers:", positive_numbers)
