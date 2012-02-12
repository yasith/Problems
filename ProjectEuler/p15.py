lim = 2
dp = [[0 for i in range(21)] for j in range(21)]
counter = 0

def rec(x, y):
    if x > lim or y > lim:
        return 0
    if dp[x][y] == 0:
        dp[x][y] = rec(x + 1, y) + rec(x, y + 1)
    
    return dp[x][y]

if __name__ == '__main__':
    lim = int(raw_input("Enter the limit "))
    dp[lim][lim] = 1
    print rec(0, 0)
