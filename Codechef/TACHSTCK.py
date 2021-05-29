n,d = [int(x) for x in input().split()]
arr = [int(input()) for i in range(n)]
arr = sorted(arr)
i = 0
count = 0

while i < n-1:
    if arr[i+1]-arr[i] <= d:
        count += 1
        i += 2
    else:
        i+=1

print(count)
