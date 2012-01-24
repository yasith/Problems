class Node:
    left, right = None, None
    rng = ()
    v = 0

    def __init__(self, rng, v):
        self.left = None
        self.right = None
        self.rng = rng
        self.v = v

def vowels(s):
    lst = ['a', 'e', 'i', 'o', 'u']
    total = 0

    for ch in s:
        if ch in lst:
            total += 1

    return total

def good(s):
    v = vowels(s)

    return v <= 2 * (len(s) - v)


def bttest(s):

    tree = Node(

if __name__ == '__main__':

    s = raw_input().lower()

    bttest(s)

    ans = 0
    count = 0

    #print s

    for i in range(len(s), 0, -1):
        for j in range(0, (len(s) - i) + 1):
            ss = s[j:j + i]

            v = 0
            for x in range(j, j + i)
            if good(ss):
                #print ss, i, j
                ans = i
                count += 1
        if ans != 0:
            break

    if ans == 0:
        print "No solution"
    else:
        print ans, count


