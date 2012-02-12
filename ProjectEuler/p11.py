f = open('p11.in')
n = 20

a = f.read()
b = a.split('\n')

c = [[]]*n

for i in range(n):
  c[i] = b[i].split()

for i in range(n):
  for j in range(n):
    c[i][j] = int(c[i][j])


dirs = [[0, 1], [1, 0], [-1, 1], [1, 1]]
maxp = 1

for i in range(n):
  for j in range(n):
    for d in range(4):
      x, y = j, i
      p = c[y][x]
      for k in range(3):
        y += dirs[d][0]
        x += dirs[d][1]
        if x >= 20 or y >= 20:
          break
        p *= c[y][x]
      maxp = max(p, maxp)

print maxp
