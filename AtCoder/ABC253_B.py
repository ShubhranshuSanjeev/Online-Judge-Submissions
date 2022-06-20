h, w = [int(x) for x in input().split()]
grid = [[ch for ch in input()] for i in range(h)]


pairs = []
for i in range(h):
    for j in range(w):
        if(grid[i][j] == 'o'):
            pairs.append((i, j))

print(abs(pairs[0][1] - pairs[1][1]) + abs(pairs[0][0] - pairs[1][0]))
