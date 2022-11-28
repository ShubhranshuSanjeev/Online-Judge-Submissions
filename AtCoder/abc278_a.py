n,m = [int(x) for x in input().split()]
arr = input().split()

print(" ".join(arr[min(m, len(arr)):]) + " " + " ".join(["0"]*min(m, len(arr))))
