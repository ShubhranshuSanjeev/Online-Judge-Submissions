t = int(input())
for _ in range(t):
    n = int(input())
    jars = [int(x) for x in input().split(' ')]
    jars.sort()
    s = 1
    for i in range(n):
        s += jars[i] - 1
    print(s)    
