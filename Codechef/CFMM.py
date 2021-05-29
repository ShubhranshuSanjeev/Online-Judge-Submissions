t = int(input())

for _ in range(t):
    n = int(input())
    letDict = {'c':0,'o':0,'d':0,'e':0,'h':0,'f':0}
    s = ''
    for _ in range(n):
        s+=input()
    for k,v in letDict.items():
        letDict[k] = s.count(k)
    x = (letDict['c']//2, letDict['e']//2, letDict['o'], letDict['d'], letDict['h'], letDict['f'])
    print(min(x))
