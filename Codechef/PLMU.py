t = int(input())
for _ in range(t):
    n = int(input())
    count_2 = 0
    count_0 = 0
    seq = [int(x) for x in input().split()]
    for i in range(n):
        if seq[i] == 2:
            count_2+=1
        if seq[i] == 0:
            count_0+=1
    count_2 = (count_2*(count_2-1))//2
    count_0 = (count_0*(count_0-1))//2
    count = count_0 + count_2
    print(count)
