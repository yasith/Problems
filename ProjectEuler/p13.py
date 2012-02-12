f = file("p13.in")
a = f.read().split()

total = 0
for i in range(len(a)):
  total += int(a[i])

print str(total)[:10]
