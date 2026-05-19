# Program demonstrating higher-order function

def multiplier(n):
    return lambda x: x * n

double = multiplier(2)
triple = multiplier(3)

print("Double of 5:", double(5))
print("Triple of 5:", triple(5))
