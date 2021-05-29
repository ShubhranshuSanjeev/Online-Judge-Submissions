t = int(input())
for _ in range(t):
    n = int(input())
    names = [0]*n
    firstNames = {}
    for i in range(n):
        names[i] = [x for x in input().split(' ')]
        if firstNames.get(names[i][0], -1) != -1:
            firstNames[names[i][0]] = firstNames[names[i][0]] + 1
        else:
            firstNames.update({names[i][0] : 1})
    
    for i in names:
        if(firstNames[i[0]] > 1):
            print(i[0],i[1])
        else:
            print(i[0])



