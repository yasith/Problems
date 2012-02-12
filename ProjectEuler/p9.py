found = False
for a in range(1, 1000):
  for b in range(1, 1000):
    for c in range(1, 1000):
      if a+b+c == 1000 and a**2+b**2 == c**2:
        found = True
        print a*b*c
        break
    if found:
      break
  if found:
    break

