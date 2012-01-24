if __name__ == '__main__':
    n = int(raw_input())
    lst = raw_input().split()

    d = {}

    answer = 0
    
    for i in lst:
        c = lst.count(i)

        if int(i) > n and (i not in d):
            answer += 1

        if c > 1:
            d[i] = c

    for v in d.values():
        answer += v - 1

    print answer
