import fileinput

names = []

def score(name):
    total = 0
    for l in name:
        total += (ord(l) - ord('A')) + 1
    return total

if __name__ == '__main__':
    for line in fileinput.input("p22.txt"):
        l = line.strip('"')
        names = l.split('","')

    names.sort()

    total = 0
    print len(names)
    for i in range(len(names)):
        total += score(names[i]) * (i+1)

    print total


