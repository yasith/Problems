from math import sqrt

def prime(fac):
  for i in range(3, int(sqrt(fac)), 2):
    if fac%i == 0:
      return False
  return True

x = 600851475143

answer = 3
fac = 3
while(fac <= x):
  if x%fac == 0 and prime(fac): #should work without checking for prime also
    answer = fac
  while(x%fac == 0):
    x = x/fac
  fac += 2

print answer
