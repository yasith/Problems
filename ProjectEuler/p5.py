x = 20
while(True):
  found = True
  for i in range(1, 20):
    if(x%i > 0):
      found = False
      break
  if found:
    print x
    break
  x += 20
