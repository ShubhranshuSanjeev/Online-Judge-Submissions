t = int(input())
for _  in range(t):
    n = int(input())
    A = [int(a) for a in input().split()]
    B = [int(b) for b in input().split()]
    A = sorted(A)
    B = sorted(B)
    s = 0
    for i in range(n):
        s += min(A[i], B[i])
    print(s)
