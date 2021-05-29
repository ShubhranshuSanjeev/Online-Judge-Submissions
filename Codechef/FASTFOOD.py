t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split(' ', n)]
    b = [int(x) for x in input().split(' ', n)]
    val = 0
    for i in b:
        val+=i
    solution = {0:val}
    for i in range(1,n):
        val = solution[i-1] - b[i-1] + a[i-1]
        solution.update({i:val})
    val = solution[n-1] - b[n-1] + a[n-1]
    solution.update({i+1:val})
    maxProfit = 0
    for v in solution.values():
        if maxProfit < v:
            maxProfit = v
    print(maxProfit)
