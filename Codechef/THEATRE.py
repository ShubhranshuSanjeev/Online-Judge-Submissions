t = int(input())
totalEarning = 0
for _ in range(t):
    n = int(input())
    A = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    for i in range(n):
        m,time = input().split()
        time = int(time)
        r = ord(m) - 65
        c = 0
        if time == 12:
            c = 0
        elif time == 3:
            c = 1
        elif time == 6:
            c = 2
        else:
            c = 3
        A[r][c] += 1
    maxCost = -500
    cst = [100,75,50,25]
    for i in range(4):
        ch_1 = A[i][0]
        for j in range(4):
            if j == i: continue
            ch_2 = A[j][1]
            for k in range(4):
                if k == j or k == i: continue
                ch_3 = A[k][2]
                for l in range(4):
                    if l == k or l == j or l == i: continue
                    ch_4 = A[l][3]
                    choices = [ch_1, ch_2, ch_3, ch_4]
                    choices.sort(reverse=True)
                    tc = 0
                    for m in range(4):
                        if choices[m] == 0:
                            tc -= 100
                        else:
                            tc += choices[m] * cst[m]
                    if maxCost < tc:
                        maxCost = tc
    totalEarning += maxCost
    print(maxCost)
print(totalEarning)
