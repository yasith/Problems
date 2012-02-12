from math import sqrt

def isprime(x):
  if x%2 == 0:
    return False
  for i in range(3, int(sqrt(x))+1, 2):
    if x%i == 0:
      return False
  return True

prime = 3
count = 1

while(count < 10001):
  if isprime(prime):
    count += 1
  prime += 2
  
print prime-2
