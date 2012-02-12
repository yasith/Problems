from math import sqrt

def divisors(x):
  divs = 0
  for i in range(1, int(sqrt(x))+1):
    if x%i == 0:
      if i != x/i:
        divs += 2
      else:
        divs += 1
  return divs

trinum = 1
n = 2 

while(True):
  d = divisors(trinum)
  if d > 500:
    break
  trinum += n
  n += 1

print trinum
