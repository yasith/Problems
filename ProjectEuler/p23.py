import math

lim = 2823
abundant = []
dp = [0] * 3000

def facsum(n):
    total = 1
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            total += i
            if i != n / i:
                total += n / i
    return total

if __name__ == '__main__':
    for i in range(1, lim):
        if facsum(i) > i:
            abundant.append(i)

    #print abundant

    dp[0] = 1
    for den in abundant:
        i = 0
        while i + den < lim:
            if dp[i] != 0:
                dp[i+den] = 1
            i += 1

    total = 0
    for i in range(lim):
        if dp[i] == 0:
            total += i

    print total

    
