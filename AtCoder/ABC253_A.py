arr = [int(x) for x in input().split()]

narr = list(arr)
narr.sort()

if arr[1] == narr[1]:
    print("Yes")
else:
    print("No")
