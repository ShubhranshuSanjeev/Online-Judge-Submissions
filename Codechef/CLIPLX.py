t = int(input())
for _ in range(t):
	x,y = [int(a) for a in input().split(' ')]
	ans = max(0,x-y)
	print(ans)
