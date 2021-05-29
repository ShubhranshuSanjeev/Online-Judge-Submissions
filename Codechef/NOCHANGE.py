t = int(input())
for _ in range(t):
    n,p = [int(x) for x in input().split()]
    D = [int(x) for x in input().split()]
    pos = {D[i]: i for i in range(n)}
    D.sort()
    flag = 0
    a = ['0']*n

    for i in range(n):
        if p % D[i]:
            flag = 1
            a[pos[D[i]]] = str(p//D[i] + 1)
            print('YES', end=' ')
            print((' ').join(a))
            break
    
    if flag:
        continue

    for i in range(n):
        flag = 0
        for j in range(i+1, n):
            if D[j] % D[i]:
                flag = 1
                break
        if flag:
            break
    
    if not flag:
        print('NO')
    else:
        x = p
        for i in range(n-1, -1, -1):
            if x % D[i]:
                a[pos[D[i]]] = str(x//D[i] + 1)
                break
            else:
                a[pos[D[i]]] = str(x//D[i] - 1)
                x = x - (x//D[i] - 1) * D[i]
        
        print('YES', end=' ')
        print((' ').join(a))
