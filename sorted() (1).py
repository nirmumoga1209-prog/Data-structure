# Program to sort tuples using lambda

students = [
    ("Anu", 85),
    ("Rahul", 72),
    ("Priya", 90),
    ("Kiran", 78)
]

sorted_students = sorted(students, key=lambda x: x[1])

print("Students Sorted by Marks:")
for student in sorted_students:
    print(student)
