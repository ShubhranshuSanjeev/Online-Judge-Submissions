t = int(input())
for _ in range(t):
    n = int(input())
    string = input()
    d = {}
    for i in range(n):
        if not d.get(string[i], 0):
            d[string[i]] = [i, 10000000]
        else:
            d[string[i]][1] = min(d[string[i]][1], i-d[string[i]][0])
            d[string[i]][0] = i
    mindiff = 10000000
    for k,v in d.items():
        if v[1] == 10000000:
            continue
        if mindiff > v[1]:
            mindiff = v[1]
        
    if mindiff == 10000000:
        print(0)
    else:
        print(n-mindiff)



