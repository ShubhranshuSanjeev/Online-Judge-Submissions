t = int(input())
for _ in range(t):
    n = int(input())
    bd = -1
    diff = 0
    a = [int(x) for x in input().split(' ')]
    d = [int(x) for x in input().split(' ')]
    for i in range(n):
        j = (i+1)%n
        if d[i] > a[i-1] + a[j] and bd < d[i]:
            bd = d[i]
    print(bd)
