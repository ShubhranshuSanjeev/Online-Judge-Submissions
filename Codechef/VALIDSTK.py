t = int(input())

for _ in range(t):
    n = int(input())
    ins = [int(x) for x in input().split(' ')]
    top = 0
    flag = 0
    for i in ins:
        if i == 0:
            if top!=0:
                top-=1
            else:
                flag = 1
                break
        if i==1:
            top+=1
    if flag == 1:
        print("Invalid")
    else:
        print("Valid")
