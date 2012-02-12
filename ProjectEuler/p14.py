import math

dp = [0]*100000000
dp[1] = 1

def getn(n):
    if math.log(n, 2) % 1 == 0:
        if n <  100000000:
            dp[n] = math.log(n, 2) + 1
        else:
            return math.log(n, 2) + 1
    elif n >= 100000000:
        newn = 0
        if n & 1:
            newn = 3 * n + 1
        else:
            newn = n/2
        return getn(newn) + 1
    elif dp[n] == 0:
        newn = 0
        if n & 1:
            newn = 3 * n + 1
        else:
            newn = n / 2
        
        dp[n] = getn(newn) + 1

    return dp[n]

if __name__ == '__main__':
    maxim = 1
    num = 1
    for i in range(1, 1000000):
        newval = getn(i)
        if maxim < newval:
            maxim = newval
            num = i
            print maxim, num
        
    print num
    print maxim
