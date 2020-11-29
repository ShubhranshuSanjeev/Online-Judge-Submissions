prime = [True for i in range(1299828)]
primes = []
p = 2
while (p * p <= 1299828): 
    if prime[p]: 
        for i in range(p * p, 1299828, p): 
            prime[i] = False
    p += 1

for p in range(2, 1299828):
    if prime[p]:
        primes.append(p)

t = int(input())
for _ in range(t):
    n = int(input())
    B = [int(x)-1 for x in input().split()]
    A = [0]*n
    
    pc = 0
    for i in range(n):
        a = B[i]
        if A[a]:
            A[i] = A[a]
        else:
            A[i] = primes[pc]
            A[a] = primes[pc]
            pc+=1
    print(' '.join([str(x) for x in A]))
