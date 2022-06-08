syllables = [int(x) for x in input().split()]
cnt_5 = 0
cnt_7 = 0

for s in syllables:
    if s == 5:
        cnt_5 += 1
    elif s == 7:
        cnt_7 += 1

if cnt_5 >= 2 and cnt_7 >= 1:
    print("YES")
else:
    print("NO")
