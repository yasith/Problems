import math

dp = [0] * 10001

def d(n):
    if n >= 10000:
        print n
    if dp[n] != 0:
        return dp[n]
    total = 1
    for i in range(int(math.sqrt(n)), 1, -1):
        if n % i == 0:
            total += i
            total += n / i
    
    dp[n] = total
    return dp[n]

def amicable(a, b):
    if d(a) == b and d(b) == a:
        return True
    return False

if __name__ == '__main__':
    total = 0
    al = []
    for i in range(1, 10001):
        for j in range(i+1, 10001):
            if(amicable(i, j)):
                if not(i in al):
                    al.append(i)
                if not(j in al):
                    al.append(j)
    for i in al:
        total += i
    print total
