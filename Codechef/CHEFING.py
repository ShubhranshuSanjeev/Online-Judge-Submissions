t = int(input())
for _ in range(t):
    n = int(input())
    i = 1
    strInp = [''.join(set(input())) for i in range(n)]
    
    op = []
    for c in strInp[0]:
        common = True
        for i in range(1, n):
            if strInp[i].find(c) == -1: common = False; break
        if common: op.append(c)

    print(len(op))
