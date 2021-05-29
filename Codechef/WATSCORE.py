t = int(input())
for _ in range(t):
    n = int(input())
    m = {}
    for i in range(n):
        p,s = [int(x) for x in input().split()]
        if p > 8:
            continue
        m[p] = max(m.get(p, 0), s)
    count = 0
    for k,v in m.items():
        count+=v
    print(count)
