N = int(input())
a = [int(x) for x in input().split()]

dp = []
for i in range(N):
    dp.append([0]*201)

for i in range(N):
    for j in range(201):
        dp[i][j] = (a[i] - j + 100) * (a[i] - j + 100)

min_cost = 1000005
for j in range(201):
    total_cost = 0
    for i in range(N):
        total_cost += dp[i][j]

    min_cost = total_cost if total_cost < min_cost else min_cost

print(min_cost)
