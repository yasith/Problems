num = 1
for i in range(1, 101):
    num *= i

s = str(num)

total = 0

for c in s:
    total += int(c)

print total
