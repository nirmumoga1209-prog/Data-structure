def add(a,b):
    return a+b

print(add(2,3))
 
def power(x,y=2):
   return x**y

print(power(3))
print(power(3,3))

def stat(numbers):
    return min(numbers),max(numbers),sum(numbers)/len(numbers)

print(stat([1,2,3,4,5]))

square=lambda x: x**2
print(square(5))