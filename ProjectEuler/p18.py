import fileinput

size = 0
tree = [[0 for i in range(100)] for j in range(100)]

def print_tree():
    """Print the tree"""
    
    for i in range(size):
        for j in range(i+1):
            print tree[i][j],
        print "\n", 

if __name__ == '__main__':
    cnt = 0
    for line in fileinput.input("p18.in"):
        a = line.split()
        counter = 0
        for x in a:
            tree[cnt][counter] = int(x)
            counter += 1
        cnt += 1
    size = cnt

    for i in range(size - 1, -1, -1):
        for j in range(i+1):
            a = tree[i + 1][j]
            b = tree[i + 1][j+1]
            tree[i][j] += max(tree[i + 1][j], tree[i + 1][j + 1])

    print tree[0][0]
