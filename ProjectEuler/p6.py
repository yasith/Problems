n = 100

#s1 sum of first n nums squared
t = n*(n+1)/2
s1 = t**2

#s2 sum of first n^2 nums
s2 = n*(n+1)*(2*n+1)/6

print abs(s1-s2)


