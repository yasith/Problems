found = 0
for i in range(999, 100, -1):
  for j in range(999, 100, -1):
    s = str(i*j)
    if s == s[::-1] and i*j > found:
      found = i*j

print found
