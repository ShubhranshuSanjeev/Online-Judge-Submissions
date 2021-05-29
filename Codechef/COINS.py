def coinChange(n,d):

    if d.get(n , -1) != -1:
        return d[n]

    if n <= 1:
        return n

    n1 = n//2
    n2 = n//3
    n3 = n//4
    solution = max(n , coinChange(n1,d)+coinChange(n2,d)+coinChange(n3,d))
    
    d.update({n:solution})

    return solution
    
while 1:
    try:
        n = int(input())
    except EOFError:
        break
    solution = coinChange(n,{})
    print(solution)

