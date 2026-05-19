# Program to convert strings to uppercase using map()

names = ["anu", "rahul", "priya", "kiran"]

uppercase_names = list(map(lambda x: x.upper(), names))

print("Original Names:", names)
print("Uppercase Names:", uppercase_names)
