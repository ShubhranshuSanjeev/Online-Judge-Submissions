def GCD(x, y):
    while y:
        x, y = y, x % y
    return x
t = int(input())
for _ in range(t):
    n, a, b, k = [int(x) for x in input().split(' ')]
    lcm = (a*b)//GCD(a,b)    
    counter = (n//a) + (n//b) - 2*(n//lcm)
    print("Win") if counter >= k else print("Lose")
