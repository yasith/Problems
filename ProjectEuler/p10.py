import math

def isprime(x):
  if x%2 == 0:
    return False
  for i in range (3, int(math.sqrt(x)+1), 2):
    if x%i == 0:
      return False
  return True

total = 2

for i in range(3, 2000000, 2):
  if isprime(i):
    total += i

print total
