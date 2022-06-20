n = int(input())

prevRow = []
currRow = []
for i in range(n):
    for j in range(i+1):
        if j == 0 or j == i:
            currRow.append(1)
        else:
            currRow.append(prevRow[j-1] + prevRow[j])
    print(" ".join([str(x) for x in currRow]))
    prevRow = list(currRow)
    currRow = []
