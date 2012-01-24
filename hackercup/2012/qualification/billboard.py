from math import sqrt

def try_to_fit(s, text, W, H):
    status = True

    nl = True
    lines = 0
    length = 0

    i = 0
    while i < len(text):
        size = text[i]
        if nl:
            if size * s > W:
                status = False
                break
            length += size

            lines += 1
            if lines * s > H:
                status = False
                break

            nl = False

        else:
            if (length + size + 1) * s > W:
                nl = True
                length = 0
                continue

            length += size + 1

        i += 1

    return status


def solve():
    line = raw_input().split()
    W, H = int(line[0]), int(line[1])

    text = [len(line[i]) for i in xrange(2, len(line))]
    
    min_size = 0
    max_size = int(sqrt((W * H / (sum(text) + len(text) - 1))))

    m = max_size

    while m != min_size:
        if try_to_fit(m, text, W, H):
            min_size = m
        else:
            max_size = m

        m = (min_size + max_size) / 2


    return min_size
    

if __name__ == '__main__':
    T = int(raw_input())

    for i in xrange(T):
        answer = solve()
        print "Case #%d: %d" %(i+1, answer)
