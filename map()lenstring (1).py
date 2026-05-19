# Program to calculate length of strings using map()

words = ["Python", "Java", "C", "JavaScript"]

lengths = list(map(lambda x: len(x), words))

print("Words:", words)
print("Lengths:", lengths)
