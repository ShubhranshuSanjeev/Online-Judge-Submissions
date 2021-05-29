t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(a) for a in input().split()]
    s = sum(A)
    R = s % k
    print(R)
    
