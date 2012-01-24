def comp(x, y):
    if x[0] > y[0]:
        return 1
    elif x[0] < y[0]:
        return -1
    
    return 0


if __name__ == '__main__':
    
    n = int(raw_input())

    events = []

    for i in xrange(n):
        l = raw_input().split()
        events.append((int(l[0]), int(l[1])))

    events.sort(comp)

    #print events

    answer = 0

    for i in xrange(1, n):
        if events[i-1][0] < events[i][0] and events[i-1][1] > events[i][1]:
            events[i] = events[i-1]
            answer += 1
        
    print answer
